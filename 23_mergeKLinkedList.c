#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode **getRestLists(struct ListNode **lists, int startIndex,
                               int listsSize) {
  int newLen = listsSize - startIndex - 1;
  struct ListNode **result =
      malloc(newLen * sizeof(struct ListNode *)); // why * is behind listnode

  memcpy(result, lists[startIndex], newLen);

  return result;
}

struct ListNode *merge(struct ListNode *node1, struct ListNode *node2) {
  struct ListNode dummy;
  struct ListNode *tail = &dummy;

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

  if (node1) {
    tail->next = node1;
  } else {
    tail->next = node2;
  }

  return dummy.next;
}

struct ListNode *mergeKLists(struct ListNode **lists, int listsSize) {
  int i = -2;
  // base case
  if (i >= listsSize) { // need to check whether we should use =
    return NULL;
  }

  // recursion part
  i += 2;
  int nextIndex = i + 2;
  struct ListNode **restlists = getRestLists(lists, nextIndex, listsSize);
  mergeKLists(restlists, listsSize - nextIndex);
  return merge(lists[i], lists[i + 1]);
}