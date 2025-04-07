#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
  int val;
  struct ListNode *next;
};

// The corrected insertion sort implementation
struct ListNode *insertionSortList(struct ListNode *head) {
  if (!head)
    return head; // Mistake: without checking edge case

  // Create a dummy node to simplify insertion at the beginning
  struct ListNode dummy;
  dummy.next = NULL;

  struct ListNode *currNode = head;

  while (currNode) {
    struct ListNode *next = currNode->next; // Mistake: forget next

    // Create node for iteration use
    struct ListNode *previous = &dummy; // Mistake: easy to forget the previous
    struct ListNode *iter = dummy.next;

    while (iter && iter->val < currNode->val) {
      previous = iter;
      iter = iter->next;
    }

    // insertion
    currNode->next = iter;
    previous->next = currNode;

    currNode = next;
  }
  return dummy.next;
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