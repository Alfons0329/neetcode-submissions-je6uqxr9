/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func isBalanced(root *TreeNode) bool {
    _, res := dfsCheck(root, 0)

    return res
}

// So we are using the approach to check each of the note with their deaf and check if they're deaf is different by more than one
func dfsCheck(root *TreeNode, depth int) (int, bool) {
    // null node is balanced
    if root == nil {
        return depth, true
    }

    lDepth, lBalanced  := dfsCheck(root.Left, depth+1)
    rDepth, rBalanced  := dfsCheck(root.Right, depth+1)

    // to prevent the wrong answer, we need to actually check the left or right depth and get to the maximum as the current depth
    maxDepth := max(lDepth, rDepth)

    return maxDepth, lBalanced && rBalanced && int(math.Abs(float64(lDepth - rDepth))) <= 1
} 


// root = [1,2,3,null,null,4,null,5]
/*
cur     depth         stack       lD  rD      balanced?
1       0             [1]
2       1             [1, 2]
2L x    2             [1, 2]      2  (ldepth for cur = 2 determined)
2R x    2             [1, 2]      2  (rdepth for cur = 2 determined) -> balanced
1       0             [1]         1  (ldepth for cur = 2 determined)
3       1             [1,3]
4       2             [1,3,4]
5       3             [1,3,4,5]   
5Lx     4             [1,3,4,5]   4 (ledpth for cur = 2 determined)
5Rx     4             [1,3,4,5]   4 (ledpth for cur = 2 determined) -> balanced
4       2             [1,3,4]     3 (ldepth for cur = 4 determined)
4R x    3             [1,3,4]     3 (rdepth for cur = 4 determined) -> balanced
3       1             [1,3]       3 (ldepth for cur = 3 detemined)
3Rx     2             [1,3]       3 (rdepth for cur = 3 determnied) -> balaanced WRONG ANSWER, actually not!!

A reason to get the wrong answer because is that we only get it left or right child current depth, 
instead of calculating all the way deep down to the leaf node

*/