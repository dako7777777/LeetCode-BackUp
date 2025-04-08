/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

struct TreeNode *assemble(struct ListNode *left, struct ListNode *mid,
                          struct ListNode *right) {
  // may need to check the NULL case
  struct TreeNode *leftChild = malloc(sizeof(struct TreeNode));
  struct TreeNode *midTree = malloc(sizeof(struct TreeNode));
  struct TreeNode *rightChild = malloc(sizeof(struct TreeNode));

  leftChild->val = left->val;
  leftChild->left = NULL;
  leftChild->right = NULL;

  rightChild->val = right->val;
  rightChild->left = NULL;
  rightChild->right = NULL;

  midTree->val = mid->val;
  midTree->left = leftChild;
  midTree->right = rightChild;
}

struct ListNode *getMid(struct ListNode *head) {
  struct ListNode *pre, *slow, *fast; // easy to make mistake without using *
  pre = NULL;
  slow = head;
  fast = head;
  while (fast && fast->next) {
    pre = slow;
    slow = slow->next;
    fast = fast->next->next;
  }

  // disconnect pre to current linked list
  if (pre) {
    pre = NULL;
  }

  return slow;
}

struct TreeNode *sortedListToBST(struct ListNode *head) {
  // base case
  if (head == NULL || head->next == NULL) {
    return head;
  }

  // recursion part
  ListNode *mid = getMid(head);
  ListNode *left = sortedListToBST(head);
  ListNode *right = sortedListToBST(mid->next); // mid or mid->next?
  return assemble(left, mid, right);
}