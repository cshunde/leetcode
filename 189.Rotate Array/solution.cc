#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() < 2) {
            return;
        }
        int size = nums.size();
        int shift = k % size;
        if (shift == 0) {
            return;
        }

        int cutPos = size - shift;
        reverse(nums, 0, cutPos);
        reverse(nums, cutPos, size);
        reverse(nums, 0, size);
    }
private:
   // reverse [begin, last)
    void reverse(vector<int>& nums, int begin, int last) {
        for (int i = begin, j = last - 1; i < j; i++, j--) {
            swap(nums[i], nums[j]);
        }
    }
};