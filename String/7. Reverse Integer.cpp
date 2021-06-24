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
#include<unordered_map>


using namespace std;
int reverse(int x) {
    int rev = 0;
    while (x != 0) {
        if (rev < INT_MIN / 10 || rev > INT_MAX / 10) {
            return 0;
        }
        int digit = x % 10;
        cout<<digit<<" ";
        x /= 10;
        rev = rev * 10 + digit;
    }
    return rev;
}

int main()
{
    string s= "sd";
    s.size()
//    vector<vector<int>> matrix = {{2, 1, 3}
cout<<reverse(-9318)<<endl;
}