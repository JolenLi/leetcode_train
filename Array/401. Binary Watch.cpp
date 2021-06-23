//
// Created by Jolen on 2021/6/20.
//

#include<vector>
#include<string>
#include<iostream>

using namespace std;

int countOne(int i) {
    int cnt = 0;
    while (i) {
        i = i & (i - 1);
        cnt += 1;
    }
    return cnt;
}

vector<string> readBinaryWatch(int turnedOn) {
    vector<string> timeVec;
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 60; j++)
            if (countOne(i) + countOne(j) == turnedOn) {
                if (j < 10)
                    timeVec.push_back(to_string(i) + ":" + "0" + to_string(j) );
                else
                    timeVec.push_back(to_string(i) + ":" + to_string(j));
            }

    for(auto vec:timeVec)
    {
        cout<<vec<<endl;
    }
    return timeVec;
}


int main() {
    readBinaryWatch(1);
}