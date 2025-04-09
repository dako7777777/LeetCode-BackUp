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

// Fixed version of getRestLists
struct ListNode **getRestLists(struct ListNode **lists, int startIndex,
                               int listsSize) {
  int newLen = listsSize - startIndex;
  if (newLen <= 0)
    return NULL;

  struct ListNode **result = malloc(newLen * sizeof(struct ListNode *));

  // Properly copy pointers from the original array
  memcpy(result, &lists[startIndex], newLen * sizeof(struct ListNode *));
  // for (int i = 0; i < newLen; i++) {
  //     result[i] = lists[startIndex + i];
  // }

  return result;
}

struct ListNode *merge(struct ListNode *node1, struct ListNode *node2) {
  struct ListNode dummy;
  struct ListNode *tail = &dummy;
  dummy.next = NULL; // Initialize dummy.next

  while (node1 && node2) {
    if (node1->val <= node2->val) {
      tail->next = node1;
      node1 = node1->next;
    } else {
      tail->next = node2;
      node2 = node2->next;
    }
    tail = tail->next;
  }

  // Attach remaining nodes
  tail->next = node1 ? node1 : node2;

  return dummy.next;
}

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
  // Base cases
  if (listsSize == 0)
    return NULL;
  if (listsSize == 1)
    return lists[0];

  // For merge sort approach, divide the lists into two halves
  int mid = listsSize / 2;

  // Get first half
  struct ListNode **leftLists = getRestLists(lists, 0, mid);
  // Get second half
  struct ListNode **rightLists = getRestLists(lists, mid, listsSize);

  // Recursively merge each half
  struct ListNode *left = mergeKLists(leftLists, mid);
  struct ListNode *right = mergeKLists(rightLists, listsSize - mid);

  // Free the temporary arrays
  free(leftLists);
  free(rightLists);

  // Merge the two sorted halves and return
  return merge(left, right);
}