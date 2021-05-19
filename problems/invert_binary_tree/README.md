# Invert Binary Tree

## 描述

翻转一棵二叉树。

输入：
```
     4
   /   \
  2     7
 / \   / \
1   3 6   9
```
输出：
```
     4
   /   \
  7     2
 / \   / \
9   6 3   1
```

## 解法

递归，类似归并排序。翻转完子节点后，再来反转父节点

## 代码

```cpp
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return root;
        }
        invertTree(root->left);
        invertTree(root->right);
        std::swap(root->left, root->right);

        return root;
    }
};
```
