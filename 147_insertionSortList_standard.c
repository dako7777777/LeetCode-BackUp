#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
  int val;
  struct ListNode *next;
};

// The corrected insertion sort implementation
struct ListNode *insertionSortList(struct ListNode *head) {
  if (!head || !head->next)
    return head; // Mistake: without checking edge case

  struct ListNode *currNode = head->next;
  struct ListNode *sortedHead = head;
  head->next = NULL; // Mistake: missing this line, which create infinite loop
                     // in following code

  while (currNode) {
    // store the next in original list
    struct ListNode *next = currNode->next;

    // case 1: if current node is smaller than head, it should be new head
    // Mistake: should check before the loop for iterNode
    if (currNode->val < sortedHead->val) {
      currNode->next = sortedHead;
      sortedHead = currNode;
    }

    // Case 2: Find position in the sorted list
    else {
      // iterate result node to find place to insert for current node
      struct ListNode *iterNode = sortedHead;
      // Find the node after which we should insert
      while (iterNode->next && iterNode->next->val <= currNode->val) {
        iterNode = iterNode->next;
      }

      // Insert after iterNode
      currNode->next = iterNode->next;
      iterNode->next = currNode;
    }

    // keep iterate
    currNode = next;
  }
  return sortedHead;
}

// Utility function to create a linked list from an array
struct ListNode *createList(int arr[], int size) {
  struct ListNode *head = NULL, *tail = NULL, *newNode;

  for (int i = 0; i < size; i++) {
    newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
    newNode->val = arr[i];
    newNode->next = NULL;

    if (!head) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  return head;
}

// Utility function to print a linked list
void printList(struct ListNode *head) {
  printf("[");
  while (head) {
    printf("%d", head->val);
    if (head->next)
      printf(",");
    head = head->next;
  }
  printf("]\n");
}

// Utility function to free a linked list
void freeList(struct ListNode *head) {
  struct ListNode *temp;
  while (head) {
    temp = head;
    head = head->next;
    free(temp);
  }
}

int main() {
  // Test case 1: [4,2,1,3] -> [1,2,3,4]
  int arr1[] = {4, 2, 1, 3};
  int size1 = sizeof(arr1) / sizeof(arr1[0]);
  struct ListNode *head1 = createList(arr1, size1);

  printf("Test Case 1:\n");
  printf("Input: ");
  printList(head1);

  struct ListNode *sorted1 = insertionSortList(head1);

  printf("Output: ");
  printList(sorted1);
  printf("Expected: [1,2,3,4]\n\n");

  // Test case 2: [-1,5,3,4,0] -> [-1,0,3,4,5]
  int arr2[] = {-1, 5, 3, 4, 0};
  int size2 = sizeof(arr2) / sizeof(arr2[0]);
  struct ListNode *head2 = createList(arr2, size2);

  printf("Test Case 2:\n");
  printf("Input: ");
  printList(head2);

  struct ListNode *sorted2 = insertionSortList(head2);

  printf("Output: ");
  printList(sorted2);
  printf("Expected: [-1,0,3,4,5]\n");

  // Free memory
  freeList(sorted1);
  freeList(sorted2);

  return 0;
}