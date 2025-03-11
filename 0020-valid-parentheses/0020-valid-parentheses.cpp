#include <iostream>
#include <stack>
#include <unordered_map>
class Solution {
public:
bool isValid(const std::string& s) {
    std::stack<char> stack;
    std::unordered_map<char, char> matchingBrackets = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char c : s) {
        // If the character is a closing bracket
        if (matchingBrackets.find(c) != matchingBrackets.end()) {
            // Check if the stack is empty or the top of the stack does not match
            if (stack.empty() || stack.top() != matchingBrackets[c]) {
                return false;
            }
            stack.pop();
        } else {
            // If it's an opening bracket, push it onto the stack
            stack.push(c);
        }
    }

    // If the stack is empty, all brackets were matched correctly
    return stack.empty();
}
};
