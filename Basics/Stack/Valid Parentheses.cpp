#include <bits\stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(const string& s) {
        stack<char> validar;
        for (char i : s) {
            if (i == '(' || i == '{' || i == '[') {
                validar.push(i);
            } else {
                if (!validar.empty() && valido(validar.top(), i)) {
                    validar.pop();
                } else {
                    return false;
                }
            }
        }
        return validar.empty();
    }
    static bool valido(const char& a, const char& b) {
        return (a == '(' && b == ')') || (a == '{' && b == '}') || (a == '[' && b == ']');
    }
};