/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

/*
Intuition: kjth smallest BST naturally fits the inorder traversal  
Appraoch:
	Inorder until kth node and return 

Complexity:
	Time: O(N)
	Space: O(logN) the recursion call stack maximum depth
*/
func kthSmallest(root *TreeNode, k int) int {
	return findkth(root, &k)
}

func findkth(root *TreeNode, k *int) int {
	if root == nil {
		return -1
	}

	if ret := findkth(root.Left, k); ret != -1 {
		return ret // since value is positivie any non -1 retunr value symbolizes "We found!"
	}

	*k = *k-1
	if *k == 0 {
		return root.Val
	}
	if ret := findkth(root.Right, k); ret != -1 {
		return ret // since value is positivie any non -1 retunr value symbolizes "We found!"
	}

	return -1 // the note is not the kth one, return -1 indicate as "already visited"
}
