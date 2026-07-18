func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	charFreq := [26]int{}

	for i := 0 ; i < len(s); i++ {
		charFreq[s[i] - 'a']++
		charFreq[t[i] - 'a']--
	}

	for _, f := range(charFreq) {
		if f != 0 {
			return false
		}
	}

	return true
}
