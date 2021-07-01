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
//// 快速选择
//int partition(vector<int> &nums, int low, int high) {
//    int temp = rand()%(high-low+1)+low;
//    swap(nums[temp],nums[low]);
//    int l = low + 1, r = high;
//    while (true) {
//        while (l <= r && nums[l] <= nums[low])l++;
//        while (l <= r && nums[r] >= nums[low])r--;
//        if (l > r)
//            break;
//        swap(nums[l], nums[r]);
//    }
//    swap(nums[low], nums[r]);
//    return r;
//}
//
//void quickSort(vector<int> &nums, int low, int high) {
//    if (low < high) {
//        int pivot = partition(nums, low, high);
//        quickSort(nums, low, pivot - 1);
//        quickSort(nums, pivot + 1, high);
//    }
//}
//
//vector<int> sortArray(vector<int> &nums) {
//    quickSort(nums, 0, nums.size() - 1);
//    return nums;
//}
//


////堆排序
void maxHeapify(vector<int> &nums, int i, int heapSize) {
    int l = i * 2 + 1, r = i * 2 + 2;
    int maxIndex = i;
    if(l<=heapSize&&nums[l]>nums[maxIndex])
        maxIndex = l;
    if(r<=heapSize&&nums[r]>nums[maxIndex])
        maxIndex = r;
    if(maxIndex!=i){
        swap(nums[i],nums[maxIndex]);
        maxHeapify(nums,maxIndex,heapSize);
    }
}

void buildMaxHeap(vector<int> &nums, int heapSize) {
    for (int i = heapSize / 2; i >= 0; i--) {
        maxHeapify(nums, i, heapSize);
    }

}

vector<int> sortArray(vector<int> &nums) {
    int heapSize = nums.size() -1;
    buildMaxHeap(nums, heapSize);

    for(int i = 0;i<heapSize;i++){
        swap(nums[0],nums[heapSize-i]);
        maxHeapify(nums,0,heapSize-i-1);
    }
    return nums;
}

int main() {
    vector<int> num = {5,2,3,1};
    sortArray(num);
    for (auto i:num)
        cout << i << " ";
}