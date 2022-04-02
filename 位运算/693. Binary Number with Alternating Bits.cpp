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


using namespace std;
bool hasAlternatingBits(int n) {
    int bit = n&1;
    while(n){
        n>>=1;
        if((n&1)==bit)
            return false;
        bit = n&1;
    }
    return true;
}

//bool hasAlternatingBits(int n) {
//    long a = n^(n>>1);
//    return (a&(a+1))==0;
//}

int main() {

    cout << hasAlternatingBits(6) << endl;
}
