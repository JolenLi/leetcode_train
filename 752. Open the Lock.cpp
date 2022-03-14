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

#include <cstring>
#include <string>
#include <unordered_set>

using namespace std;

//
//
vector<string> next(string str) {
    vector<string> nums;
    string cur;
    for (int i = 0; i < 4; i++) {
        cur = str;
        cur[i] = str[i] == '9' ? '0' : str[i] + 1;
        nums.push_back(cur);
        cur = str;
        cur[i] = str[i] == '0' ? '9' : str[i] - 1;
        nums.push_back(cur);
    }
    return nums;
}
//
//int openLock(vector<string> &deadends, string target) {
//    queue<string> tryNumber;
//    unordered_set<string> deadNumber(deadends.begin(),deadends.end());
//    if(deadNumber.count(target))
//        return -1;
//    tryNumber.push("0000");
//    int cnt = 0;
//    while (!tryNumber.empty()) {
//        int times = tryNumber.size();
//        while (times--) {
//            string cur = tryNumber.front();
//            tryNumber.pop();
//            if (deadNumber.count(cur)) continue;
//            if (cur == target) return cnt;
//            for (auto i:next(cur))
//                tryNumber.push(i);
//            deadNumber.insert(cur);
//        }
//        cnt++;
//    }
//    return -1;
//}



////  双端bfs

bool
update(unordered_set<string> &dead, unordered_set<string> &check, unordered_set<string> &path, queue<string> &que) {
    int len = que.size();
    while (len--) {
        string cur = que.front();
        que.pop();

        if (dead.count(cur) || path.count(cur)) continue;
        if (check.count(cur)) return true;
        path.insert(cur);
        vector<string> numStr = next(cur);
        for (auto &str:numStr)
            que.push(str);
    }
    return false;
}

int openLock(vector<string> &deadends, string &target) {
    unordered_set<string> s1, s2;
    queue<string> q1, q2;
    unordered_set<string> dead(deadends.begin(), deadends.end());
    q1.push("0000");
    q2.push(target);

    int times = -1;
    bool finish;
    while (!q1.empty() && !q2.empty()) {
        if (q1.size() <= q2.size())
            finish = update(dead, s2, s1, q1);
        else
            finish = update(dead, s1, s2, q2);
        if (finish)
            return times;
        times++;
    }
    return -1;
}


int main() {
    vector<string> deadends = {"5557", "5553", "5575", "5535", "5755", "5355", "7555", "3555", "6655", "6455", "4655",
                               "4455", "5665", "5445", "5645", "5465", "5566", "5544", "5564", "5546", "6565", "4545",
                               "6545", "4565", "5656", "5454", "5654", "5456", "6556", "4554", "4556", "6554"};

    string target = "5555";
    cout << openLock(deadends, target) << endl;
}

