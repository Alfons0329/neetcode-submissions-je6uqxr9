func sortColors(nums []int) {
    zero, one, two := 0, 0, 0
	for ;two < len(nums); two++ {
		tmp := nums[two]
		nums[two] = 2


		// write non-2 first until it is two
		if tmp < 2 {
			nums[one] = 1
			one++
		}
		if tmp < 1 {
			nums[zero] = 0
			zero++
		}
	}
}
