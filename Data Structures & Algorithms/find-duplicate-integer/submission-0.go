/*
Intuotion: Slow-past pointer to find duplicated, and it will meet at duplicate

Approach:
	1. slow = num[i]
	2. fast = num[num[i]]
	it will eventually converge at the duplicated number

	then start again at the beginning, with same pace to find the duplicated number
*/
func findDuplicate(nums []int) int {
	// start at begin
	fast := nums[0]
	slow := nums[0]

	// step 1 find the 
	for {
		fast = nums[nums[fast]]
		slow = nums[slow]
		if slow == fast {
			break	
		}
	}

	slow = nums[0]

	for slow != fast {
		fast = nums[fast]
		slow = nums[slow]
	}

	return slow
}
