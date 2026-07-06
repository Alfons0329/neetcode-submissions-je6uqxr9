/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func levelOrder(root *TreeNode) [][]int {
	// use BFS to search in each order, queue() makes sense

	queue := []*TreeNode{}
	res := [][]int{}

	if root == nil {
		return res
	}

	queue = append(queue, root)

	for len(queue) > 0 {
		// each level
		curLevelSize := len(queue)
		levelRes := []int{}
		for i := 0; i < curLevelSize; i++   {
			// visit current and pop
			cur := queue[0]
			queue = queue[1:] 
			levelRes = append(levelRes, cur.Val)

			if cur.Left != nil {
				queue = append(queue, cur.Left)
			}
			if cur.Right != nil {
				queue = append(queue, cur.Right)
			}
		}
		res = append(res, levelRes)
	}


	return res
}
