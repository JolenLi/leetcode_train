//
// Created by Jolen on 2021/6/26.
//
#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>

#include <bitset>

using namespace std;
int getSum(int a, int b) {
    if(a==0)
        return b;
    if(b==0)
        return a;
    return getSum(a^b,(unsigned )(a&b)<<1);
}
int main() {
    cout << getSum(2,3) << endl;
}
