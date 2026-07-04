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

/*
Approach: 
To remove a node, we have 2 testcases 
1. the first one being the note with only one child or nothing. In this case we just need to return the auto parts of the child if it's not empty.
2. The second one is tricky because we need to find the smallest note from the right of subtree, 
and replaced the note value with the minimum from the right subtree. Then remove such as a smallest note.

Because the binary surgery is recursively defined structure, so we also use the recursive approach to solve
*/
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        // this is the basic case for the recursion
        if (!root) {
            return nullptr;
        }

        // First of all, find a note to delete
        if (key < root->val) {
            // construct the substructure
            root->left = deleteNode(root->left, key);
            /* 
                Pitfall: not, deleteNode(root->left, key) only because
                    2
                1       3

                To delete 1

                in below (!root -> left) {
                    root = root->right is correct
                }

                return root (root is now right or left, root->right = empty)

                But most important is the above root equals to root right is only move that pointer. 
                It does NOT reconstruct the structure.

                So the tree become still, ALLEGEDLY
                     2
                null      3

                But the steel connection, is 2->left still 1
                So our tree is not modified at all
            */
        } else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else {
            // 1st case, been the note with only one child or nothing, there's no need to special judge that with no child
            if (!root->left) {
                root = root->right; // replace and connect
            } else if (!root->right) {
                root = root->left; // replace and connect
            } else {
                // 2nd case we need to find the minimum from the right sub tree,
                int rSubTreeMin = findMinBST(root->right);
                // replace the root with the minimum of the right sub tree and then delete it from the right sub tree
                root->val = rSubTreeMin;
                root->right = deleteNode(root->right, rSubTreeMin);
            }
        }

        return root; // return the deleted sub structure;
    }
private:
    int findMinBST(TreeNode* root) {
        int min;
        while(root) {
            min = root->val;
            root = root->left;
        }

        return min;
    }
};