func search(nums []int, target int) int {
	l, r := 0, len(nums)

	for l < r {
		m := (l + r) / 2
		if target == nums[m] {
			return m
		} else if target > nums[m] {
			l = m + 1
		} else {
			r = m
		}
	}


	return -1
}
