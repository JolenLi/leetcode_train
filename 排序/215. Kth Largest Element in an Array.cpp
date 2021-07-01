//
// Created by Jolen on 2021/6/27.
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

////  调库
//int findKthLargest(vector<int> &nums, int k) {
//    sort(nums.begin(),nums.end());
//    return nums[nums.size()-k];
//}


//int partition(vector<int>& a, int l, int r) {
//    int x = a[r], i = l - 1;
//    for (int j = l; j < r; ++j) {
//        if (a[j] <= x) {
//            swap(a[++i], a[j]);
//        }
//    }
//    swap(a[i + 1], a[r]);
//    return i + 1;
//}
//
//int paritition(vector<int> &nums, int low, int high) {
//
//    int l = low, h = high + 1;
//    ////  快速选择+随机
//    int i = rand() % (h - l) + l;
//    swap(nums[low],nums[i]);
//    while (l < h) {
//        while (nums[++l] < nums[low] && l < high);
//        while (nums[--h] > nums[low] && h > low);
//        if (l < h)
//            swap(nums[l], nums[h]);
//    }
//    swap(nums[low], nums[h]);
//    return h;
//}
////// 快速排序
//void sort(vector<int> &nums, int low, int high) {
//    if (low < high) {
//        int pivot = paritition(nums, low, high);
//        sort(nums, low, pivot - 1);
//        sort(nums, pivot + 1, high);
//    }
//}
//
//int findKthLargest(vector<int> &nums, int k) {
//    int l = 0, r = nums.size() - 1;
//    int target = nums.size() - k;
//    while (l < r) {
//        int pivot = paritition(nums, l, r);
//        if (pivot == target)break;
//        if (pivot > target)
//            r = pivot - 1;
//        else
//            l = pivot + 1;
//    }
//
//    return nums[target];
//}


//// 堆排序
void maxHeapify(vector<int> &nums, int i, int heapSize) {
    int l = i * 2 + 1, r = i * 2 + 2;
    int maxNum = i;
    if (l < heapSize && nums[l] > nums[maxNum])
        maxNum = l;
    if (r < heapSize && nums[r] > nums[maxNum])
        maxNum = r;
    if (maxNum != i) {
        swap(nums[i], nums[maxNum]);
        maxHeapify(nums, maxNum, heapSize);
    }
}

void buildMaxHeap(vector<int> &nums, int heapSize) {

    for (int i = heapSize / 2; i >= 0; i--) {
        maxHeapify(nums, i, heapSize);
    }
}

int findKthLargest(vector<int> &nums, int k) {
    int heapSize = nums.size();
    buildMaxHeap(nums, heapSize);

    for (int i = 1; i < k; i++) {
        swap(nums[0], nums[heapSize - i]);
        maxHeapify(nums, 0, heapSize - i);
    }

    return nums[0];
}

int main() {
    vector<int> num = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << findKthLargest(num, 4);
}