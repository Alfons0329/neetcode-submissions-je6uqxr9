/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Next *Node
 *     Random *Node
 * }
 */

/*
Intuition: 
	2 pass to use the hashmap to store the next node for random and next

	,a
*/
func copyRandomList(head *Node) *Node {
	if head == nil {
		return nil
	}
	// store the next pointer
	oldToNew := make(map[*Node]*Node) // maps old to new node
	newHead := &Node{Val: head.Val}
	oldToNew[head] = newHead

	prev := newHead
	cur := head.Next

	for cur != nil {
		prev.Next = &Node{
			Val: cur.Val,
		}

		// map and move both
		oldToNew[cur] = prev.Next
		cur = cur.Next
		prev = prev.Next
	}

	// Second pass: set random pointers
	cur = head
	curNew := newHead
	for cur != nil {
    	curNew.Random = oldToNew[cur.Random]
    	curNew = curNew.Next
    	cur = cur.Next
	}

	return newHead
}
