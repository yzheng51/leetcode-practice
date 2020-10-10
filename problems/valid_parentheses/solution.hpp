#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stk;
        for (auto ch : s) {
            if (ch == '(') {
                stk.push(')');
            } else if (ch == '[') {
                stk.push(']');
            } else if (ch == '{') {
                stk.push('}');
            } else {
                if (stk.empty() || ch != stk.top()) {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};
