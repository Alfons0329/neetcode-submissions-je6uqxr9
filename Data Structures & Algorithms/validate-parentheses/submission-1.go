func isValid(s string) bool {
	st := []byte{}
	match := map[byte]byte {
		'(' : ')',
		'{' : '}',
		'[' : ']',
	}


	for _, c := range(s) {
		if (c == '(' || c == '{' || c == '[') {
			st = append(st, byte(c))
			continue
		}

		if (c == ')' || c == '}' || c == ']') {
			if len(st) == 0 {
				return false
			}

			lastIdx := len(st) - 1
			if match[st[lastIdx]] != byte(c) {
				return false
			}

			// pop stack
			st = st[:lastIdx]
		}
	}

	return len(st) == 0
}
