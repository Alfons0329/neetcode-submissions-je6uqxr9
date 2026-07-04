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
    bool isValidBST(TreeNode* root) {
        // base
        if (!root) {
            return true;
        }

        if (root->left && root->val <= findMaxLTree(root->left)) {
            return false;
        }

        if (root->right && root->val >= findMinRTree(root->right)) {
            return false;
        }

        return isValidBST(root->left) && isValidBST(root->right);
    }

    // validate if the root value sits in between the minimum of the right sub tree and the maximum of the left subtree
    int findMinRTree(TreeNode* root) {
        int res = INT_MAX;
        while(root) {
            res =  min(res, root->val);
            root = root->left;  
        }

        return res;
    }
    int findMaxLTree(TreeNode* root) {
        int res = INT_MIN;
        while(root) {
            res =  max(res, root->val);
            root = root->right;  
        }

        return res;
    }
};
