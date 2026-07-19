/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func maxDepth(root *TreeNode) int {
	maxDepth := 0
	findMaxDepth(root, 0, &maxDepth)

	return maxDepth
}

func findMaxDepth(root *TreeNode, curDepth int, maxDepth *int) {
	// reach leaf, ok to update the maxDepth
	if root == nil {
		if *maxDepth < curDepth {
			*maxDepth = curDepth
		}

		return
	}

	findMaxDepth(root.Left, curDepth+1, maxDepth)
	findMaxDepth(root.Right, curDepth+1, maxDepth)
}
