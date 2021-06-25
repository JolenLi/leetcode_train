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

char nextGreatestLetter(vector<char> &letters, char target) {
    int left = 0, right = letters.size();

    while (left < right) {
        int mid = left + (right - left >> 1);
        if (target >= letters[mid]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return letters[left % letters.size()];

}


int main() {
    vector<char> c = {'a', 'b', 'c', 'd'};
    cout << nextGreatestLetter(c, 'g') << endl;
}