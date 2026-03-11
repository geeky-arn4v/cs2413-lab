/*
 * Assignment 2 / Question 2 / student.c
 * ------------------------------------------------------------
 * Check if a BST is an AVL tree
 *
 * Implement:
 *   bool isAVL(struct TreeNode* root);
 *
 * AVL (for this assignment) means:
 * 1) strict BST property (no duplicates)
 * 2) height-balanced: abs(height(left) - height(right)) <= 1 at every node
 *
 * Rules:
 * - Do NOT allocate new nodes.
 * - Do NOT modify the tree.
 * - Do NOT print anything.
 *
 * Build/Run (from Assignment2 folder):
 *   make run2
 */

#include <stdbool.h>
#include <stddef.h>
#include <limits.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper that checks both BST validity (within (minVal, maxVal)) and AVL balance.
// Returns the height of the subtree if it is a valid AVL tree, or -1 otherwise.
static int check_avl(struct TreeNode* root, long long minVal, long long maxVal) {
    if (root == NULL) {
        return 0;  // height of empty tree
    }

    // Enforce strict BST property: minVal < root->val < maxVal
    if ((long long)root->val <= minVal || (long long)root->val >= maxVal) {
        return -1;
    }

    int leftHeight = check_avl(root->left, minVal, root->val);
    if (leftHeight == -1) {
        return -1;
    }

    int rightHeight = check_avl(root->right, root->val, maxVal);
    if (rightHeight == -1) {
        return -1;
    }

    int diff = leftHeight - rightHeight;
    if (diff < -1 || diff > 1) {
        return -1;  // not height-balanced
    }

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

bool isAVL(struct TreeNode* root) {
    int height = check_avl(root, (long long)LLONG_MIN, (long long)LLONG_MAX);
    return height != -1;
}
