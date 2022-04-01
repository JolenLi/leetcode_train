//
// Created by Jolen on 2022/3/31.
//

//
// Created by Jolen on 2022/3/31.
//

//
// Created by Jolen on 2022/3/31.
//

//
// Created by Jolen on 2022/3/31.
//



//
// Created by Jolen on 2022/3/11.
//


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int N = m+n-1;
    int i=m-1,j=n-1;
    while(N>=0){
        if(i<0)
            nums1[N--] = nums2[j--];
        else if(j<0)
            nums1[N--] = nums1[i--];
        else if(nums1[i]>nums2[j])
            nums1[N--] = nums1[i--];
        else
            nums1[N--] = nums2[j--];
    }
}

int main() {

}