#include <string>
using namespace std;

class Solution {
 public:
  string addStrings(string num1, string num2) {
    string result;
    result.reserve(std::max(num1.size() + 1, num2.size() + 1));
    int carry = 0;

    string::const_reverse_iterator iter1 = num1.crbegin();
    string::const_reverse_iterator iter2 = num2.crbegin();
    for (; iter1 != num1.crend() && iter2 != num2.crend(); iter1++, iter2++) {
      int q = (*iter1 - '0') + (*iter2 - '0') + carry;
      carry = 0;
      if (q >= 10) {
        q -= 10;
        carry = 1;
      }
      result.push_back(q + '0');
    }
    while (iter1 != num1.crend()) {
      int q = (*iter1 - '0') + carry;
      carry = 0;
      if (q >= 10) {
        q -= 10;
        carry = 1;
      }
      result.push_back(q + '0');
      iter1++;
    }
    while (iter2 != num2.crend()) {
      int q = (*iter2 - '0') + carry;
      carry = 0;
      if (q >= 10) {
        q -= 10;
        carry = 1;
      }
      result.push_back(q + '0');
      iter2++;
    }
    if (carry != 0) {
      result.push_back(carry + '0');
      carry = 0;
    }
    reverse(result.begin(), result.end());
    return result;
  }
};
