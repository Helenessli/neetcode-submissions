class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (auto c : s) {
            if (c == '(') {
                stk.push(')');
            }
            else if (c == '[') {
                stk.push(']');
            }
            else if (c == '{') {
                stk.push('}');
            }
            else {
                // c is a closing bracket
                if (stk.empty() || stk.top() != c) {
                    return false;
                }

                stk.pop();
            }
        }

        return stk.empty();
    }
};