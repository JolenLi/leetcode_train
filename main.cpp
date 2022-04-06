//
// Created by Jolen on 2021/6/24.
//
//
// Created by Jolen on 2021/6/23.
//



//// dp


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include <unordered_set>

using namespace std;


vector<pair<unsigned long long, unsigned long long>> curNums;
set<pair<unsigned long long, unsigned long long>> visited;
map<pair<unsigned long long, unsigned long long>, int> surTime;


int check(pair<unsigned long long, unsigned long long> a, pair<unsigned long long, unsigned long long> target) {
    if (a == target)
        return 1;

    if (a.first >= target.first || a.second >= target.second)
        return -1;
    if (a.first * 2 > target.first && a.second * 2 > target.second &&
        (target.first - a.first) != (target.second - a.second))
        return -1;
    else return 0;
}

unsigned long long sss = 999;

long long GetMinCalculateCount(long long sourceX, long long sourceY, long long targetX, long long targetY) {
    curNums.push_back({sourceX, sourceY});
    pair<unsigned long long, unsigned long long> target = {targetX, targetY};
    vector<pair<unsigned long long, unsigned long long>> backNums;
    backNums.push_back(target);
    long long count = 0;
    long long counts = 1;
    long long j = 0;
    long long x = 0;
    while (j < curNums.size()) {
        long long i = curNums.size();
        cout<<i<<endl;
        long long y = backNums.size();
        for (; x < y; x++) {
            pair<unsigned long long, unsigned long long> temp ={ backNums[x].first-1, backNums[x].second-1};

            if(surTime[temp] ==0){
                surTime[temp]= counts;
                backNums.push_back(temp);
            }

            if(backNums[x].first%2==0&&backNums[x].second%2==0){
                temp ={ backNums[x].first/2, backNums[x].second/2};
                if(surTime[temp] ==0){
                    surTime[temp]= counts;
                    backNums.push_back(temp);
                }

            }
        }
        counts++;
//        cout<<i<<endl;
        for (; j < i; j++) {
            int ans = check(curNums[j], target);

            if(surTime[curNums[j]]>0)
                return count+surTime[curNums[j]];
            if (ans == 1)
                return count;
            else if (ans == 0) {
                pair<unsigned long long, unsigned long long> temp = {curNums[j].first + 1, curNums[j].second + 1};
                if (!visited.count(temp)) {
                    visited.insert(temp);
                    curNums.push_back(temp);
                }

                temp = {curNums[j].first * 2, curNums[j].second * 2};
                if (!visited.count(temp)) {
                    visited.insert(temp);
                    curNums.push_back(temp);
                }

            }
        }
        count++;
    }
    return -1;
}

int main() {
//    cout<<sss<<endl;
    cout << GetMinCalculateCount(1, 1, 9999999, 9999999) << endl;
}