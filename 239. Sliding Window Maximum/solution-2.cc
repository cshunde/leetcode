#include <deque>
#include <vector>
using namespace std;

class Solution {
private:
    void enQueue(deque<int> &sw, int n) {
        while (!sw.empty() && sw.back() < n) {
            sw.pop_back();
        }
        sw.push_back(n);
    }
    void deQueue(deque<int> &sw, int n) {
        if (sw.front() == n) {
            sw.pop_front();
        }
    }
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
        for (int i = 0; i < k - 1; i++) {
            enQueue(sw, nums[i]);
        }

        for (int i = k - 1; i < nums.size(); i++) {
            enQueue(sw, nums[i]);
            result.push_back(sw.front());
            deQueue(sw, nums[i-k+1]);
        }
        return result;
    }
};
