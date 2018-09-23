#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }
        if (nums.size() == 0) {
            return vector<int>{};
        }
        vector<int> result;
        result.reserve(nums.size() - k + 1);

        deque<int> sw;
        for (int i = 0; i < k; i++) {
            while (sw.size() > 0 && sw.back() < nums[i]) {
                sw.pop_back();
            }
            sw.push_back(nums[i]);
        }

        for (int i = 0; i < nums.size() - k; i++) {
            result.push_back(sw.front());
            if (nums[i] == sw.front()) {
                sw.pop_front();
            }
            while (sw.size() > 0 && sw.back() < nums[i+k]) {
                sw.pop_back();
            }
            sw.push_back(nums[i+k]);
        }
        result.push_back(sw.front());
        return result;
    }
};
