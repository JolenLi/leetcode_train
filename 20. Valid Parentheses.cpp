//
// Created by Jolen on 2022/3/11.
//

unordered_map<char, char> pairs = {
        {')', '('},
        {']', '['},
        {'}', '{'}
};

bool isValid(string s) {
    stack<char> stk;
    for (int i = 0; i < s.size(); i++) {
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
