//
// Created by Jolen on 2022/4/1.
//

//
// Created by Jolen on 2021/6/20.
//

#include<iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
vector<int> days;

//// 单调栈
vector<int> dailyTemperatures(vector<int> &temperatures) {
    days = vector<int>(temperatures.size(), 0);
    stack<int> stk;
    for (int cur = 0; cur < temperatures.size(); cur++) {
        while(!stk.empty()&&temperatures[cur]>temperatures[stk.top()]){
            int prev = stk.top();
            days[prev] = cur-prev;
            stk.pop();
        }
        stk.push(cur);
    }
    return days;
}

//// 从右向左，dp
//int getDay(vector<int> &temperatures, int curDay, int targetDay) {
//    if (targetDay >= days.size())
//        return 0;
//    if (temperatures[curDay] < temperatures[targetDay])
//        return targetDay - curDay;
//    else if (days[targetDay] == 0)
//        return 0;
//    else
//        return getDay(temperatures, curDay, targetDay + days[targetDay]);
//}
//
//vector<int> dailyTemperatures(vector<int> &temperatures) {
//    days =  vector<int>(temperatures.size(), 0);
//    for (int i = temperatures.size() - 1; i >= 0; i--) {
//        days[i] = getDay(temperatures, i, i + 1);
//    }
//    return days;
//}

int main() {

}
