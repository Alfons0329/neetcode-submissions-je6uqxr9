class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // rows[i][num] = true if number (num+1) exists in row i
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        // cols[j][num] = true if number (num+1) exists in column j
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        // subBoxes[k][num] = true if number (num+1) exists in sub-box k
        vector<vector<bool>> subBoxes(9, vector<bool>(9, false));

        for (int i = 0 ; i < 9; i++) {
            for (int j = 0 ; j < 9; j++) {
                int curNum = board[i][j] - '1'; // convert char digit to int digit, mapping to 0 base
                if (curNum < 0) {
                    continue; // '.' is before '0'
                }
                
                int subBoxIndex = (i / 3) * 3 + (j / 3); // convert 2d array to 1d (the row * total_col + col), each of them is 3x3
                if (rows[i][curNum] ||
                    cols[j][curNum] ||
                    subBoxes[subBoxIndex][curNum]) {
                    return false;
                }

                rows[i][curNum] = true;
                cols[j][curNum] = true;
                subBoxes[subBoxIndex][curNum] = true;
            }
        }

        return true;
    }
};
