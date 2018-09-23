class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lower = lowerBound(nums, 0, nums.size() - 1, target);
        if (lower >= nums.size() || nums[lower] != target) {
            return vector<int> {-1, -1};
        }
        int upper = lowerBound(nums, lower, nums.size() - 1, target+1);
        return vector<int> {lower, upper - 1};
    }
private:
    int lowerBound(const vector<int>& nums, int begin, int end, int target) {
        while (begin <= end) {
            int mid = (begin + end) >> 1;
            if (nums[mid] < target) {
                begin = mid + 1;
            } else if (nums[mid] >= target) {
                end = mid - 1;
            }
        }
        return begin;
    }
};
