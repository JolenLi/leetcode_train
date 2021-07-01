//
// Created by Jolen on 2021/7/1.
//
//// sort


#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>


using namespace std;

//
//int partition(vector<char> &chars, int low, int high, unordered_map<char, int> &freq) {
//    int temp = rand() % (high - low + 1) + low;
//    swap(chars[temp], chars[low]);
//    int i = low + 1, j = high;
//    while (true) {
//        while (i <= j && freq[chars[i]] <= freq[chars[low]])i++;
//        while (i <= j && freq[chars[j]] >= freq[chars[low]])j--;
//        if (i > j)break;
//        swap(chars[i], chars[j]);
//    }
//    swap(chars[low], chars[j]);
//    return j;
//}
//
//void quickSort(vector<char> &chars, int low, int high, unordered_map<char, int> &freq) {
//    if (low < high) {
//        int pivot = partition(chars, low, high, freq);
//        quickSort(chars, low, pivot - 1, freq);
//        quickSort(chars, pivot + 1, high, freq);
//    }
//}
//
//string frequencySort(string s) {
//    unordered_map<char, int> freq;
//    for (char &c:s)
//        freq[c]++;
//    vector<char> uniqueChar;
//    for (auto &it:freq)
//        uniqueChar.push_back(it.first);
//
////    quickSort(uniqueChar,0,uniqueChar.size()-1,freq);
//    string ans = "";
//    for (auto &ch:uniqueChar) {
//        for (int i = 0; i < freq[ch]; i++)
//            ans = ch + ans;
//    }
//
//    return ans;
//}
void maxHeapify(vector<char> &nums, unordered_map<char, int> &freq, int i, int heapSize) {
    int l = i * 2 + 1, r = i * 2 + 2;
    int maxIndex = i;
    if (l < heapSize && freq[nums[l]] > freq[nums[maxIndex]])
        maxIndex = l;
    if (r < heapSize && freq[nums[r]] > freq[nums[maxIndex]])
        maxIndex = r;
    if (maxIndex != i) {
        swap(nums[i], nums[maxIndex]);
        maxHeapify(nums, freq, maxIndex, heapSize);
    }
}

void buildMaxheap(vector<char> &nums, unordered_map<char, int> &freq, int heapSize) {
    for (int i = heapSize / 2; i >= 0; i--)
        maxHeapify(nums, freq, i, heapSize);
}

string frequencySort(string s) {
    unordered_map<char, int> freq;
    for (char &c:s)
        freq[c]++;
    vector<char> uniqueChar;
    for (auto &it:freq)
        uniqueChar.push_back(it.first);
    buildMaxheap(uniqueChar, freq, uniqueChar.size());
//    quickSort(uniqueChar,0,uniqueChar.size()-1,freq);

    string ans = "";
    for (int i = 0; i < uniqueChar.size(); i++) {
        for (int j = 0; j < freq[uniqueChar[0]]; j++)
            ans = ans + uniqueChar[0];
        swap(uniqueChar[0], uniqueChar[uniqueChar.size() - i - 1]);
        maxHeapify(uniqueChar, freq, 0, uniqueChar.size() - i - 1);
    }

//    for (auto &ch:uniqueChar) {
//        for (int i = 0; i < freq[ch]; i++)
//            ans = ch + ans;
//    }

    return ans;
}

////   优先队列
//75. Sort Colors

int main() {
    string str = "Aabb";
    cout << frequencySort(str) << endl;
}