func majorityElement(nums []int) int {
	freq := map[int]int{}

	for _, num := range(nums) {
		freq[num]++
	}

	for k, v := range(freq) {
		if v > int(len(nums) / 2) {
			return k
		}
	}

	return -1
}
