func evalRPN(tokens []string) int {
	stk := []int64{}

	for _, c := range tokens {
		sz := len(stk)
		if c == "+" || c == "-" || c == "*" || c == "/" {
			oper2 := stk[sz-1]
			stk = stk[:sz-1]
			oper1 := stk[sz-2]
			stk = stk[:sz-2]

			var res int64
			switch c {
				case "+":
				res = oper1 + oper2
				case "-":
				res = oper1 - oper2
				case "*":
				res = oper1 * oper2
				default:
				res = oper1 / oper2	
			}
			stk = append(stk, res)
		} else {
			num, _ := strconv.ParseInt(c, 10, 64)
			stk = append(stk, num)
		}
	}

	return int(stk[0])
}
