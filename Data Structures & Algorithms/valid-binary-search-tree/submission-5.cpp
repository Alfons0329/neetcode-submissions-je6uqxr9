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
        return validBST(root, INT_MIN, INT_MAX);
    }

    bool validBST(TreeNode* root, int lowerBound, int upperBound) {
        if (!root) {
            return true;
        }

        // root value must resides b/w lowerBound and upperBound
        // continue the recursively defined structure
        // L subtree, lowerBound = lowerBound, upperBound = parnet (parent root)
        // R subtree, lowerBound = parent(root), upperBound = upperBound
        return (root->val < upperBound) && (root->val > lowerBound) && 
                validBST(root->left, lowerBound, root->val) && // tighetn left side
                validBST(root->right, root->val, upperBound); // tighten right side
    }
};

/*
*/
