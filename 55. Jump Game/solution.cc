class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lastIdx = nums.size() - 1;
        int sofarICanReach = 0;
        for (int i = 0; i <= sofarICanReach; i++) {
            sofarICanReach = max(sofarICanReach, i + nums[i]);
            if (sofarICanReach >= lastIdx) {
                return true;
            }
        }
        return false;
    }
};
