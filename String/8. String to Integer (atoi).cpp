//
// Created by Jolen on 2021/6/24.
//


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

using namespace std;


int myAtoi(string str) {
    int start = 0, end = str.size();
    bool positive = true;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != ' ') {
            start = i;
            for (int j = i + 1; j < str.size(); j++)
                if (!isdigit(str[j])) {
                    end = j;
                    break;
                }
            break;
        }
    }
    if (str[start] == '-')
        positive = false;
    else if (str[start] != '+' && !isdigit(str[start]))
        return 0;

    long long num = 0;
    if(str[start]=='-'||str[start]=='+')
        start++;
    for (; start < end; start++) {
        if (positive)
            num = num * 10 + str[start] - '0';
        else
            num = num * 10 - str[start] + '0';

        if (num > INT_MAX||num<INT_MIN)
            return positive?INT_MAX:INT_MIN;
    }
    return num;
}

int main() {
    string str = "   -42  ";
    cout << myAtoi(str) << endl;
}

