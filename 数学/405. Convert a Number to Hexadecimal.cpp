//
// Created by Jolen on 2022/3/29.
//

//
// Created by Jolen on 2021/6/25.
//



//
// Created by Jolen on 2021/6/24.
//



//// 二分查找


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>


using namespace std;

char convert(int i) {
    if (i < 10)
        return '0' + i;
    else
        return 'a' + i - 10;
}

string toHex(int num) {
    if (num == 0)return "0";
    string ans = "";
    unsigned a = num;
    while (a != 0) {
        ans += convert(a & 15);
        a >>= 4;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    cout << toHex(26) << endl;
}