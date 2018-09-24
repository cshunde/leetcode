class Solution {
public:
    int kInversePairs(int n, int k) {
        const int kMod = 1000000007;
        vector<int> row(k+1, 0);
        row[0] = 1;
        for (int i = 2; i <= n; i++) {
            vector<int> preRow(k+1, 0);
            preRow.swap(row);
            row[0] = 1;
            int preNSum = preRow[0];
            for (int j = 1; j <= k; j++) {
                preNSum += preRow[j];
                if (j >= i) {
                    preNSum -= preRow[j-i];
                    if (preNSum < 0) {
                        preNSum += kMod;
                    }
                }
                if (preNSum >= kMod) {
                    preNSum -= kMod;
                }
                row[j] = preNSum;
            }
        }
        return row[k];
    }
};

// 思路：
// 动态规划
