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

void merge(struct ListNode *left, struct ListNode *right) {
  struct ListNode dummy;
  dummy.next = NULL;

  while (left && right) {

    if (left->val < right->val) {
      // insertion
      dummy.next = left;
      left->next = NULL;

      // move to the next node
      left = left->next;
    } else {
      // insertion
      dummy.next = right;
      right->next = NULL;

      // move to the next node
      right = right->next;
    }

    dummy.next = dummy.next->next;
  }

  while (left) {
    dummy.next = left;
    left->next = NULL;
  }

  while (right) {
    dummy.next = right;
    right->next = NULL;
  }

  left = dummy.next;
}

struct ListNode *sortList(struct ListNode *head) {
  struct ListNode *mid = getMid(head);
  if (head != mid) {
    sortList(head);
    sortList(mid);
    merge(head, mid);
  }

  return head;
}