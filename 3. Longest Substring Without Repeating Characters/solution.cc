class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lastShow[256];
        for (int i = 0; i < 256; i++) {
            lastShow[i] = -1;
        }
        int longest = 0;
        int noRepeatLen = 0;
        int start = 0;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (lastShow[ch] < start) {
                noRepeatLen++;
                longest = max(longest, noRepeatLen);
            } else {
                start = lastShow[ch] + 1;
                noRepeatLen = i - lastShow[ch];
            }
            lastShow[ch] = i;
        }
        return longest;
    }
};
