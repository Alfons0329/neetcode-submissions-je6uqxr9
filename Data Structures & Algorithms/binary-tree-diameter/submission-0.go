/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func diameterOfBinaryTree(root *TreeNode) int {
    res := 0
	dfs(root, &res)
	return res
}

func dfs(root *TreeNode, res *int) int {
	if root == nil {
		return 0
	}

	lDia := dfs(root.Left, res)
	rDia := dfs(root.Right, res)
	cur := lDia+rDia
	if cur > *res {
		*res = cur
	}
	
	return 1 + max(lDia, rDia)
}

func getMax(a, b int) int {
	if a > b {
		return a
	}

	return b
}