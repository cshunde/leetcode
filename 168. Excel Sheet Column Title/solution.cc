#include <string>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        string title;
        while (n > 0) {
            char ch = (n-1) % 26 + 'A';
            title.insert(title.begin(), ch);
            n = (n-1) / 26;
        }
        return title;
    }
};