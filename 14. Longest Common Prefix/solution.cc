class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        } 
        if (strs.size() == 1) {
            return strs[0];
        }
        string prefix;
        for (int i = 0; i < strs[0].length(); i++) {
            int j = 1;
            for (; j < strs.size(); j++) {
                if (i >= strs[j].length() || strs[0][i] != strs[j][i]) {
                    break;
                }
            }
            if (j < strs.size()) {
                break;
            }
            prefix += strs[0][i];
        }
        return prefix;
    }
};
