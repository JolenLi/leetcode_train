//
// Created by Jolen on 2021/7/1.
//

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

//// 堆排序
//void maxHeapify(vector<int> &nums,unordered_map<int, int> &freq, int heapSize, int i) {
//    int l = i * 2 + 1, r = i * 2 + 2;
//    int maxIndex = i;
//    if (l <= heapSize && freq[nums[l]] > freq[nums[maxIndex]])
//        maxIndex = l;
//    if (r <= heapSize && freq[nums[r]] > freq[nums[maxIndex]])
//        maxIndex = r;
//    if (maxIndex != i) {
//        swap(nums[maxIndex], nums[i]);
//        maxHeapify(nums,freq, heapSize, maxIndex);
//    }
//}
//
//void buildMaxHeap(vector<int> &nums,unordered_map<int, int> &freq, int heapSize) {
//    for (int i = heapSize / 2; i >= 0; i--) {
//        maxHeapify(nums,freq, heapSize, i);
//    }
//}
//
//vector<int> topKFrequent(vector<int> &nums, int k) {
//    unordered_map<int, int> freq;
//    vector<int> uniqueNum,ans;
//    for (auto &i:nums)
//        freq[i]++;
//    for(auto &i:freq)
//        uniqueNum.push_back(i.first);
//    int heapSize = freq.size()-1;
//    buildMaxHeap(uniqueNum,freq,heapSize);
//
//
//    for(int i = 0;i<k;i++){
//        ans.push_back(uniqueNum[0]);
//        swap(uniqueNum[0],uniqueNum[heapSize-i]);
//        maxHeapify(uniqueNum,freq,heapSize-i-1,0);
//    }
//    return ans;
//}

int partition(vector<int> &nums, int low, int high, unordered_map<int, int> &freq) {
    int i = low + 1, j = high;
    while (true) {
        while (i <= j && freq[nums[i]] <= freq[nums[low]])i++;
        while (i <= j && freq[nums[j]] >= freq[nums[low]])j--;
        if (i > j)break;
        swap(nums[i], nums[j]);
    }
    swap(nums[low], nums[j]);
    return j;
}

void quickSelect(vector<int> &nums, int low, int high, unordered_map<int, int> &freq, int k) {
    int target = nums.size() - k;
    while (low < high) {
        int pivot = partition(nums, low, high, freq);
        if (pivot == target)
            break;
        else if (pivot > target)
            high = pivot - 1;
        else
            low = pivot + 1;
    }
}
//
//void quickSort(vector<int> &nums, int low, int high, unordered_map<int, int> &freq) {
//    if (low < high) {
//        int pivot = partition(nums, low, high, freq);
//        quickSort(nums, low, pivot - 1, freq);
//        quickSort(nums, pivot + 1, high, freq);
//    }
//}

vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> freq;
    vector<int> uniqueNum, ans;
    for (auto &i:nums)
        freq[i]++;
    for (auto &i:freq)
        uniqueNum.push_back(i.first);

//    quickSort(uniqueNum, 0, uniqueNum.size() - 1, freq);
    quickSelect(uniqueNum, 0, uniqueNum.size() - 1, freq, k);
    for (int i = 1; i <= k; i++)
        ans.push_back(uniqueNum[uniqueNum.size() - i]);

    return ans;
}


int main() {
    vector<int> num = {7, 8, 4, 5, 1, 1, 1, 2, 2, 3};
    vector<int> ans = topKFrequent(num, 2);
    for (auto i:ans)
        cout << i << " ";
}