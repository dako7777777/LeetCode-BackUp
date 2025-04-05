/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition for singly-linked list
struct ListNode {
  int val;
  struct ListNode *next;
};

// Function to create a new node
struct ListNode *createNode(int val) {
  struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
  if (newNode) {
    newNode->val = val;
    newNode->next = NULL;
  }
  return newNode;
}

// Function to create a linked list from an array
struct ListNode *createLinkedList(int arr[], int size) {
  if (size == 0)
    return NULL;

  struct ListNode *head = createNode(arr[0]);
  struct ListNode *current = head;

  for (int i = 1; i < size; i++) {
    current->next = createNode(arr[i]);
    current = current->next;
  }

  return head;
}

// Function to print a linked list
void printLinkedList(struct ListNode *head) {
  printf("[");
  while (head) {
    printf("%d", head->val);
    if (head->next)
      printf(",");
    head = head->next;
  }
  printf("]\n");
}

// Function to free a linked list
void freeLinkedList(struct ListNode *head) {
  struct ListNode *temp;
  while (head) {
    temp = head;
    head = head->next;
    free(temp);
  }
}

// Function prototype for the solution (you will implement this)
struct ListNode *mergeNodes(struct ListNode *head) {
  struct ListNode *resultHead = NULL; // Mistake: not being initialized to NULL

  // use while loop to iterate through the linked list
  struct ListNode *currNode = head;
  int sum = 0; // 0 could represent this sequence hasn't start

  while (currNode != NULL) { // Mistake: currNode->next == NULL
    // reach the end of current sequence: value is 0 and sum isn't 0
    if (currNode->val == 0 && sum != 0) {
      // add current sum to result node

      // add to the head
      if (resultHead == NULL) {
        resultHead = malloc(sizeof(struct ListNode));
        resultHead->val = sum;
        resultHead->next = NULL;
      }

      // add to the next node
      struct ListNode *nodePre = resultHead;
      struct ListNode *nodeNext = nodePre->next;
      while (nodePre != NULL) {
        nodePre = nodeNext;
        nodeNext = nodeNext->next;
      }

      nodeNext = malloc(sizeof(struct ListNode));
      nodeNext->val = sum;
      nodeNext->next = NULL;

      // reset sum
      sum = 0;
    } else {
      sum += currNode->val;
    }
    currNode = currNode->next;
  }

  return resultHead;
};

int main() {
  // Test case 1: [0,3,1,0,4,5,2,0]
  {
    int arr[] = {0, 3, 1, 0, 4, 5, 2, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    struct ListNode *head = createLinkedList(arr, size);

    printf("Test Case 1:\n");
    printf("Input: ");
    printLinkedList(head);

    struct ListNode *result = mergeNodes(head);

    printf("Output: ");
    printLinkedList(result);
    printf("Expected: [4,11]\n");

    // Free the result list
    freeLinkedList(result);
  }

  // Test case 2: [0,1,0,3,0,2,2,0]
  {
    int arr[] = {0, 1, 0, 3, 0, 2, 2, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    struct ListNode *head = createLinkedList(arr, size);

    printf("\nTest Case 2:\n");
    printf("Input: ");
    printLinkedList(head);

    struct ListNode *result = mergeNodes(head);

    printf("Output: ");
    printLinkedList(result);
    printf("Expected: [1,3,4]\n");

    // Free the result list
    freeLinkedList(result);
  }

  return 0;
}
