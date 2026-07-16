func longestCommonPrefix(strs []string) string {
	
	for i := 0; i < len(strs[0]); i++ {
		for _, s := range strs {
			if i == len(s) || s[i] != strs[0][i] {
				// reach end or difference
				return s[:i]
			}
		}
	}

	return strs[0] // all matched
}
