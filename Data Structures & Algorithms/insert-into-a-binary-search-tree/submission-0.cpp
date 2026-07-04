/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // Insert a note into binary secretary is also recursively defined
        // in this problem, there is no need to rebalance the tree like the AVL or red-black tree, hence we can just always insert to the leat node 
        if (!root) {
            // a place to insert is found
            TreeNode *newNode = new TreeNode(val, nullptr, nullptr);
            return newNode;
        }

        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};