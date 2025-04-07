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

struct ListNode {
  int val;
  struct ListNode *next;
};

//========= solution for leet code ==========
struct ListNode *getMid(struct ListNode *head) {
  struct ListNode *prev;
  struct ListNode *slow;
  struct ListNode *fast;

  prev = NULL;
  slow = head;
  fast = head;

  // find the middle through while loop
  while (fast && fast->next) {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }

  // disconnect the first half from the second half
  if (prev) {
    prev->next = NULL;
  }

  return slow;
}

struct ListNode *merge(struct ListNode *left, struct ListNode *right) {
  // V1
  // forget to create current node,
  // instead, using dummy directly, which can work in loop
  // but change the head -- Therefore, dummy is not for loop purpose

  // V2
  //  use tail to simplify the solution
  struct ListNode dummy;
  struct ListNode *tail = &dummy;

  dummy.next = NULL; // prevent containing random garbage

  while (left && right) {
    if (left->val < right->val) {
      // insertion
      tail->next = left;
      left = left->next;
    } else {
      tail->next = right;
      right = right->next;
    }

    tail = tail->next;
  }

  if (left) {
    tail->next = left;
  } else {
    tail->next = right;
  }

  return dummy.next;
}

struct ListNode *sortList(struct ListNode *head) {
  // original method: caused by the lack of understanding of linked list
  // in the method for array, the index is using as parameter, for linked list
  // it has to be returned
  // struct ListNode *mid = getMid(head);
  // if (head != mid) {
  //   sortList(head);
  //   sortList(mid);
  //   merge(head, mid);
  // }

  if (!head || !head->next) {
    // Mistake: write the base case wrong, without !
    return head;
  }

  struct ListNode *mid = getMid(head);
  struct ListNode *left = sortList(head);
  struct ListNode *right = sortList(mid);
  return merge(left, right);
}

// =================== Helper functions for testing ===================

// Create a new node
struct ListNode *createNode(int val) {
  struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
  node->val = val;
  node->next = NULL;
  return node;
}

// Create a linked list from an array
struct ListNode *createList(int arr[], int size) {
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

// Print a linked list
void printList(struct ListNode *head) {
  printf("[");
  while (head != NULL) {
    printf("%d", head->val);
    if (head->next != NULL) {
      printf(",");
    }
    head = head->next;
  }
  printf("]\n");
}

// Free memory used by a linked list
void freeList(struct ListNode *head) {
  struct ListNode *temp;
  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}

int main() {
  // Example 1
  int arr1[] = {4, 2, 1, 3};
  struct ListNode *head1 = createList(arr1, 4);
  printf("Example 1:\nInput: ");
  printList(head1);
  head1 = sortList(head1);
  printf("Output: ");
  printList(head1);
  freeList(head1);

  // Example 2
  int arr2[] = {-1, 5, 3, 4, 0};
  struct ListNode *head2 = createList(arr2, 5);
  printf("\nExample 2:\nInput: ");
  printList(head2);
  head2 = sortList(head2);
  printf("Output: ");
  printList(head2);
  freeList(head2);

  // Example 3
  printf("\nExample 3:\nInput: []\n");
  struct ListNode *head3 = NULL;
  head3 = sortList(head3);
  printf("Output: ");
  printList(head3);

  return 0;
}