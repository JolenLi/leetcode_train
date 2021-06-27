//
// Created by Jolen on 2021/6/27.
//

//
// Created by Jolen on 2021/6/27.
//

//
// Created by Jolen on 2021/6/26.
//




//// dp


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>


using namespace std;

int numDecodings(string s) {
    if (s[0] == '0')
        return 0;
    vector<int> memo(s.size() + 1, 0);
    memo[0] = 1, memo[1] = 1;
    for (int i = 2; i <= s.size(); i++) {
        if (s[i - 1] == '0') {
            if (s[i - 2] - '0' <= 2 && s[i - 2] - '0' > 0)
                memo[i] = memo[i - 2];
            else
                return 0;
        } else if (s[i - 2] == '1' || (s[i - 2] == '2' && (s[i - 1] - '0') <= 6))
            memo[i] = memo[i - 2] + memo[i - 1];
        else
            memo[i] = memo[i - 1];
    }
    return memo[s.size()];
}

int main() {
    cout << numDecodings("226") << endl;
}

