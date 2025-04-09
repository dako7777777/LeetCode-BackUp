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

  // Divide the lists into two halves
  int mid = listsSize / 2;

  // Recursively merge each half
  struct ListNode *left = mergeKLists(lists, mid);
  struct ListNode *right = mergeKLists(lists + mid, listsSize - mid);

  // Merge the two sorted halves
  return merge(left, right);
}