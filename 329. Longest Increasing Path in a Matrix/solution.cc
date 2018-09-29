class Solution {
private:
    struct Elem {
        int val;
        int row;
        int col;
        Elem(int i, int j, int value): row(i), col(j), val(value) {}
    };
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m, n;
        if ((m = matrix.size()) == 0 || (n = matrix[0].size()) == 0 )  {
            return 0;
        }
        vector<Elem> elems;
        elems.reserve(m*n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                elems.push_back(Elem(i, j, matrix[i][j]));
            }
        }
        sort(elems.begin(), elems.end(), [](const Elem &lhs, const Elem &rhs) {
            return lhs.val > rhs.val;
        });

        vector<int> dp(m*n, 0);
        int maxLengthSofar = 0;
        for (auto iter = elems.begin(); iter != elems.end(); iter++) {
            int row = iter->row;
            int col = iter->col;

            int maxLen = 1;
            // up
            if (row > 0 && matrix[row-1][col] > iter->val) {
                maxLen = max(maxLen, 1 + dp[(row-1)*n+col]);
            }
            // down
            if (row < m-1 && matrix[row+1][col] > iter->val) {
                maxLen = max(maxLen, 1 + dp[(row+1)*n+col]);
            }
            // left
            if (col > 0 && matrix[row][col-1] > iter->val) {
                maxLen = max(maxLen, 1 + dp[row*n+col-1]);
            }
            // right
            if (col < n-1 && matrix[row][col+1] > iter->val) {
                maxLen = max(maxLen, 1 + dp[row*n+col+1]);
            }
            dp[row*n+col] = maxLen;
            maxLengthSofar = max(maxLengthSofar, maxLen);
        }
        return maxLengthSofar;
    }
};
