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

int strStr(string haystack, string needle) {
    int haySize = haystack.size();
    int needSize = needle.size();
    if (needSize == 0)
        return 0;

    for (int i = 0; i <= haySize - needSize; i++) {
        bool find = true;
        int temp = i;
        for (int j = 0; j < needSize; j++, temp++) {
            if (haystack[temp] != needle[j]) {
                find = false;
                break;
            }
        }
        if (find)
            return i;
    }
    return -1;
}

int main() {
    string s = "mississippi";
    string s2 = "mississippi";

    cout << strStr(s, s2) << endl;
}//
// Created by Jolen on 2021/6/24.
//

