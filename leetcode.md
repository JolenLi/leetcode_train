



利用 **x ^ 1s = ~x** 的特点，可以将一个数的位级表示**翻转**；

利用 **x ^ x = 0** 的特点，可以**将三个数中重复的两个数去除**，只留下另一个数。



利用 x & 0s = 0 和 x & 1s = x 的特点，可以实现掩码操作。

利用 x | 0s = x 和 x | 1s = 1s 的特点，可以实现设值操作。

n&(n-1) 去除 n 的位级表示中最低的那一位 1。

n&(-n) 得到 n 的位级表示中最低的那一位 1。

#### [完全二叉树的节点个数](https://leetcode-cn.com/problems/count-complete-tree-nodes/)

递归+位运算

二分查找



#### [15. 三数之和](https://leetcode-cn.com/problems/3sum/)

固定+双指针



#### [1. 两数之和](https://leetcode-cn.com/problems/two-sum/)

哈希表（map）



#### [25. K 个一组翻转链表](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/)

迭代/递归 



#### [11. 盛最多水的容器](https://leetcode-cn.com/problems/container-with-most-water/)

双指针


136. Single Number
     位运算
     
     

#### [236. 二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)

LCA公共祖先



#### [494. 目标和](https://leetcode-cn.com/problems/target-sum/)

Dp    背  包。 子集和问题 

#### [28. Implement strStr()](https://leetcode-cn.com/problems/implement-strstr/)

KMP





#### [72. Edit Distance](https://leetcode-cn.com/problems/edit-distance/)

**解决两个字符串的动态规划问题，一般都是用两个指针** **`i,j`** **分别指向两个字符串的最后，然后一步步往前走，缩小问题的规模**。





#### [300. 最长递增子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)





#### [303. 区域和检索 - 数组不可变](https://leetcode-cn.com/problems/range-sum-query-immutable/)

前缀和





#### [347. 前 K 个高频元素](https://leetcode-cn.com/problems/top-k-frequent-elements/)

堆排序，快速排序，快速选择



#### [451. 根据字符出现频率排序](https://leetcode-cn.com/problems/sort-characters-by-frequency/)

堆排序，快速排序超时

优先队列













## 笔记



链表：快慢指针，反转链表，反转N组，回文链表（序列化）

二叉树：前中后序遍历（递归），搜索树（中序遍历升序，增删改查）

#### [142. 环形链表 II](https://leetcode-cn.com/problems/linked-list-cycle-ii/)

快慢指针相遇点与起始点同时移动，会在环头相遇

快慢指针第二次相遇的次数等于环长



#### [96. Unique Binary Search Trees](https://leetcode-cn.com/problems/unique-binary-search-trees/)

二叉树dp

#### [95. Unique Binary Search Trees II](https://leetcode-cn.com/problems/unique-binary-search-trees-ii/)

#### [1373. Maximum Sum BST in Binary Tree](https://leetcode-cn.com/problems/maximum-sum-bst-in-binary-tree/)

返回指针

```
int *traverse(TreeNode *root) 
int *res = new int[]{1, INT_MAX, INT_MIN, 1};
```



#### [297. Serialize and Deserialize Binary Tree](https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/)

序列化，使用引用列表数组来改值

```
TreeNode *deser(queue<string> &strQue) 
```



#### [743. Network Delay Time](https://leetcode-cn.com/problems/network-delay-time/)

djkstra模版

