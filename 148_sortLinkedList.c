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

struct ListNode *getMid(struct ListNode head) {
  struct ListNode pre;
  struct ListNode slow;
  struct ListNode fast;
  // = malloc(sizeof(struct ListNode));

  // pre = NULL;
  slow = *head;
  fast = *head;

  // find the middle through while loop
  while (fast.next) {
    // why can't write fast in the condition of while loop
    pre = slow;
    slow = slow.next;
    fast = fast.next.next;
  }

  // unchained the pre to the mid
  free(pre);

  return slow;
}

void merge(struct ListNode *head, struct ListNode *mid) { struct ListNode next }

void mergeSort(struct ListNode *head) {
  struct ListNode *mid = getMid(head);
  if (head != mid) {
    mergeSort(head);
    mergeSort(mid);
    merge(head, mid);
  }
}

struct ListNode *sortList(struct ListNode *head) {}