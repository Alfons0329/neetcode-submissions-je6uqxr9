/*
repeated sub problem

if amoutn - coin[i] exist, then add its combination up!

*/
func coinChange(coins []int, amount int) int {
	dp := make([]int, amount+1)
    
    // Initialize all values to amount+1 (impossible marker)
    for i := 0; i <= amount; i++ {
        dp[i] = amount + 1
    }
    dp[0] = 0  // Base case: 0 coins needed for amount 0
	
	for i := 1 ; i <= amount; i++ {
        for _, c := range(coins) {
			if i - c >= 0 {
				// can make up to the amount
				dp[i] = min(dp[i], dp[i - c] + 1)
			} 
		}
	}

	// cannot satisfies the result
	if dp[amount] == amount+1 {
		return -1
	}

	return dp[amount]
}
