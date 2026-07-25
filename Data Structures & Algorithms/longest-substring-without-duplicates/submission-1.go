func lengthOfLongestSubstring(s string) int {
	l := 0
	res := 0
	n := len(s)
	existChar := map[byte]bool{}

	for r := 0; r < n; r++ {
		_, ok := existChar[s[r]]

		if !ok {
			if r - l + 1 > res {
				res = r - l + 1
			}
		} else {
			for existChar[s[r]] {
				delete(existChar, s[l])
				l++
			}
		}

		existChar[s[r]] = true
	}

	return res
}
