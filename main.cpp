#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void heapAdjust(vector<int>&nums,int heapSize,int i){
    int maxIndex = i,l = i*2+1,r=i*2+2;
    if(l<heapSize&&nums[l]>nums[maxIndex])
        maxIndex = l;
    if(r<heapSize&&nums[r]>nums[maxIndex])
        maxIndex= r;
    if(maxIndex!=i){
        swap(nums[i],nums[maxIndex]);
        heapAdjust(nums,heapSize,maxIndex);
    }
}
void buildHeap(vector<int>& nums,int heapSize,int k){
    for(int i = heapSize/2;i>=0;i--){
        heapAdjust(nums,heapSize,i);
    }
}
int heapSort(vector<int>& nums, int k){
    int heapSize = nums.size();

    buildHeap(nums,heapSize,k);

    for(int i=1;i<k;i++){
        swap(nums[0],nums[heapSize-i]);
        heapAdjust(nums,heapSize-i,0);
    }

    return nums[0];
}



int findKthLargest(vector<int>& nums, int k)
{

    return heapSort(nums,k);
}

int main() {
    vector<int> num = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << findKthLargest(num, 4);
}