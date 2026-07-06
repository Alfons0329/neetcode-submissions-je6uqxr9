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
    vector<int> preorderTraversal(TreeNode* root) {
        /*
        You can use similar iterative approach as inorder travesal

        preorder is
        root
        root->left
        root->right
        */

        vector<int> res;
        stack<TreeNode*> st;

        TreeNode* cur = root;
        while(cur || !st.empty()) {
            // we still have task to do in the recursion stack

            // root != null
            if (cur) {
                st.push(cur);
                // print() 
                res.push_back(cur->val);

                // preorder(root->left)
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
                cur = cur->right;
            }
        }

        return res;
    }
};

/*
Dry tun example for recursion stack
root = [1,2,3,4,5,6,7]

for each of the x, it is same as if (root == null) { return }
in the recusion solution

cur     stack           res         next
1       [1]             [1]         1->left = 2 
2       [1, 2]          [1, 2]      2->left = 4
4       [1, 2, 4]       [1, 2, 4]   4->left = x
x       
4       [1, 2]          [1, 2, 4]   4->right = x
x
2       [1]             [1, 2, 4]   2->right = 5
5       [1, 5]          [1,2,4,5]   5->left = x
x
5       [1]             [1,2,4,5]   5->right = x
x       [1]
1       []              [1,2,4,5]   1->right = 3
3       [3]             [1,2,4,5,3] 3->left = 6
6       [3,6]           [1,2,4,5,3,6] 6->left = x
x
6       [3]             [1,2,4,5,3,6] 6->right = x
x
3       []              [1,2,4,5,3,6] 3->right = 7
7       [7]             [1,2,4,5,3,6,7] 7->left = x
x       
7       []              [1,2,4,5,3,6,7] 7->right = x
x       []

----> Stack terminated!!!!

let's go through the complexity analysis. 
    1. The time complexity will be linear O(N) because we traverse each node once.
    2. Space complexity will be O(logN), this is the recursion tech growth up to the height of the tree, and if it is well balanced, then it will be up to log, 
and it is not balanced and skewed that it will up to the linear

*/
