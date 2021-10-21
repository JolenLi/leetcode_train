//
// Created by Jolen on 2021/6/21.
//


#include<vector>
#include<iostream>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int maxIndex(vector<int> nums,int lo,int hi)
{
    int maxNum = lo;
    for(int i=lo;i<=hi;i++)
    {
        if(nums[i]>nums[maxNum])
            maxNum = i;
    }
    return maxNum;
}
//TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//    if(nums.empty())
//        return nullptr;
//    int maxNumIndex = maxIndex(nums);
//    vector<int> leftNums,rightNums;
//    TreeNode *root = new TreeNode(nums[maxNumIndex]);
//    for(int i=0;i<maxNumIndex;i++)
//        leftNums.push_back(nums[i]);
//    for(int i=maxNumIndex+1;i<nums.size();i++)
//        rightNums.push_back(nums[i]);
//    root->left = constructMaximumBinaryTree(leftNums);
//    root->right = constructMaximumBinaryTree(rightNums);
//
//    return root;
//}

TreeNode *buildTree(vector<int>& nums,int lo,int hi)
{
    if(lo>hi)
        return nullptr;


    int maxIndex = lo,maxVal = nums[lo];
    for(int i=lo+1;i<=hi;i++)
    {
        if(nums[i]>nums[maxIndex])
            maxIndex = i;
    }

    TreeNode *root = new TreeNode(nums[maxIndex]);
    root->left = buildTree(nums,lo,maxIndex-1);
    root->right = buildTree(nums,maxIndex+1,hi);
    return root;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return buildTree(nums,0,nums.size()-1);
}


