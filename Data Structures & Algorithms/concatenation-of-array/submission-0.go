func getConcatenation(nums []int) []int {
	sz := len(nums)
	res := make([]int, 2 * sz)

	for i, num := range nums {
		res[i] = num
		res[i + sz] = num
	}

	return res
}
