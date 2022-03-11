#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>

using namespace std;
unordered_map<char, char> pairs = {
        {')', '('},
        {']', '['},
        {'}', '{'}
};

bool isValid(string s) {
    stack<char> stk;
    for (int i = 1; i < s.size(); i++) {
        if (!stk.empty()) {
            char top = stk.top();
            if (top == pairs[s[i]])
                stk.pop();
            else
                stk.push(s[i]);
        } else {
            stk.push(s[i]);
        }
    }
    return stk.empty();
}

int main() {
    vector<int> num = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << findKthLargest(num, 4);
}