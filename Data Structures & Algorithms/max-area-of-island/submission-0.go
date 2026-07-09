/*
intuition: seartch in 2D matrix use DFS
approach:
	1. start from 1, for each 1 (1 only, since 2 is visited and 0 is not island)
		2. make traversed block 1->2
		3. check block is non visied yet
		4. count++, res = max(res, count)
	2. end of isLand

time:	O(grid.row * grid.col)
space:	O(1) is INCORRECT because count recutrsion stack growth, then up to O(grid.row * grid.col)

*/
func maxAreaOfIsland(grid [][]int) int {
	var finalRes = 0
	rowLim := len(grid)
	colLim := len(grid[0])

	for row := 0; row < rowLim; row++ {
		for col := 0; col < colLim; col++ {
			if grid[row][col] == 1 {
				var curRes = 0
				dfs(grid, row, col, rowLim, colLim, &curRes, &finalRes)
			}
		}
	}

	return finalRes
}

// curRes and fianlRes will be updated throughout the dfs call, hence pass the pointer type
func dfs(grid [][]int, row, col, rowLim, colLim int, curRes, finalRes *int) {
	if row >= rowLim || row < 0 || col >= colLim || col < 0 || grid[row][col] != 1 {
		return
	}

	*curRes++ // increaset the real value in the pointer, rather then increase pointer itseflt
	/*
		finalRes = math.Max(curRes, finalRes)  // ❌ This doesn't update the pointer
		math.Max returns a value, but you're assigning it to the pointer itself (not dereferencing). It should be
		*finalRes = max(int(*curRes), int(*finalRes))  // ✅ Dereference and 
	
	*/
	if *curRes > *finalRes {
    	*finalRes = *curRes
	}
	grid[row][col] = 2
	// U, D, L, R
	dfs(grid, row - 1, col, rowLim, colLim, curRes, finalRes)
	dfs(grid, row + 1, col, rowLim, colLim, curRes, finalRes)
	dfs(grid, row, col - 1, rowLim, colLim, curRes, finalRes)
	dfs(grid, row, col + 1, rowLim, colLim, curRes, finalRes)
}

