/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 
func preorderTraversal(root *TreeNode) []int {
    res := []int{}
    stack := []*TreeNode{}
    
    cur := root
    for cur != nil || len(stack) > 0 {
        if cur != nil {
            // Push to stack
            stack = append(stack, cur)
            // Visit root
            res = append(res, cur.Val)
            // Move to left child
            cur = cur.Left
        } else {
            // Pop from stack
            topIdx := len(stack) - 1
            cur = stack[topIdx]
            stack = stack[:topIdx]
            
            // Move to right child
            cur = cur.Right
        }
    }
    
    return res
}