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
    The iterative solution is just reconstruct the stack based on the recursive solution
    e.g.
            5
        4       7
    3        6 
2

We start from the route note and Traverse down the binary research tree
The order should be left, root, right

The idea is to continuously mimic the recusrion call stack as if for the recursion using stack data structure

So here left is the bottom of the stack and right is the top

inoder(root->left)
[5]           cur = 5
[5 4]         cur = 4
[5 4 3]       cur = 3
[5 4 3 2]     cur = 2
[5 4 3 2]     cur = *

print()
pop = 2     cur = 2 , res = [2]
2->right is empty, not push into stack
pop = 3     cur = 3, res = [2, 3]
3->right is empty, not push into stack
pop = 4     cur = 4, res = [2 ,3, 4]
4->right is empty, not push into stack
pop = 5     cur = 5, res = [2, 3, 4, 5]
5->right is 7

inorder(root->right)
7                   cur = 7
[7]
inorder(root->left)
7->left is 6        cur = 6
[7 6]
6->left is empty    cur = *

print()
pop = 6     cur = 6, res = [2, 3, 4, 5, 6]
[7]
pop = 7     cur = 7, res = [2, 3, 4, 5, 6, 7]
[]

terminate
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        
        // start from root
        if (!root) {
            return res;
        }

        TreeNode* cur = root;
        while(cur || !st.empty()) {
            if (cur) {
                st.push(cur);
                // inorder(cur->left)
                cur = cur->left;
            } else {
                // else base case, same as if root != nullptr
                // left is finished
                // equivalent to print(root->val)
                cur = st.top();
                st.pop(); // pop it away from the recursion call stack frame
                // since we always ensure the root node that is not null 
                // before pushing into the stack so we can directly add it to the answer

                res.push_back(cur->val);

                // equivalent to inorder(root->right)
                cur = cur->right;
            }
        }

        return res;
    }
};