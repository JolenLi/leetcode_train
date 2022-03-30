//
// Created by Jolen on 2022/3/29.
//

int minFlipsMonoIncr(string s) {
    vector<int> pre(2, 0);
    vector<int> now(2, 0);
    vector <vector<int>> dp(s.size(), vector<int>(2, 0));
    pre[0] = s[0] == '0' ? 0 : 1;
    pre[1] = s[0] == '1' ? 0 : 1;
    for (int i = 1; i < s.size(); i++) {
        now[0] = pre[0] + s[i] - '0';
        now[1] = min(pre[0], pre[1]) + abs(s[i] - '1');
        pre = now;
    }
    return min(now[0], now[1]);
}


int minFlipsMonoIncr(string s) {
    vector<int> zeroSuffix(s.size() + 1, 0);
    vector<int> onePrefix(s.size() + 1, 0);
    for (int i = 0; i < s.size(); i++) {
        onePrefix[i + 1] = onePrefix[i] + (s[i] == '1' ? 1 : 0);
        zeroSuffix[s.size() - i - 1] = zeroSuffix[s.size() - i] + (s[s.size() - 1 - i] == '0' ? 1 : 0);
    }
    int mini = INT_MAX;
    for (int i = 0; i <= s.size(); i++) {
        mini = min(mini, onePrefix[i] + zeroSuffix[i]);
    }
    return mini;
}