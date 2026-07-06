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
    vector<int> postorderTraversal(TreeNode* root) { 
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;


       while(cur || !st.empty()) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();

               
                if (cur->right && cur->right != prev) {
                    // explore the right subtree first
                    cur = cur->right;
                } else {
                    // it is either the null (leaft node)   cur->right == nullptr
                    // or the R subtree has been finished   cur->right == prev
                    res.push_back(cur->val);
                    // we can only park here because we ensure the left and the right subtree is ifnished
                    // this follows the correct left right root recursion code
                    st.pop();
                    prev = cur;
                    cur = nullptr; // terminate the current recursion call stack 
                }
            }
       }

       return res;
    }
};

/*
post order sounds hard, but just inverse of Root->R->L (another kind of traverse, we insert to the begin)

or use the canonical one
because root is the left and r
or the canonical way of recursion stack
root = [1, 2, 3, 4, 5, 6, 7]
cur     stack       prev    res     next
1       [1]                 []      1->left = 2
2       [1,2]               []      2->left = 4
4       [1,2,4]             []      4->left = x
x       [1,2,4]             []      
4       [1,2]      4        []      4->right = x
x       [1,2]      4        [] 
2       [1]        4        [4(pushed, since 2->right == 4 )]


should have a previous ptr

*/