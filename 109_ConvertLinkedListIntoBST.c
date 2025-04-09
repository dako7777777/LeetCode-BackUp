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
#include <string.h>

struct ListNode {
  int val;
  struct ListNode *next;
};

struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
};

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
    pre->next = NULL; // Mistake: write pre = NULL -- question
    // but why we need to disconnect, since pre is a local variable, seems
    // nothing will connect to slow? use this to cut the linked list as half
  }

  return slow;
}

struct TreeNode *sortedListToBST(struct ListNode *head) {
  // base case 1
  if (head == NULL) {
    return NULL;
  }

  // base case 2?? create a single tree
  // Mistake: should add base case 2

  if (head->next == NULL) {
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->val = head->val;
    node->left = NULL;
    node->right = NULL;
    return node;
  }

  // recursion part

  // get the middle node and use it to create root
  struct ListNode *mid = getMid(head);
  struct TreeNode *root = malloc(sizeof(struct TreeNode));
  root->val = mid->val;

  root->left = sortedListToBST(head);
  root->right = sortedListToBST(mid->next)
}