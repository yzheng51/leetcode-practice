# Balanced Binary Tree

## 描述

给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 `1` 。

```
输入：root = [3,9,20,null,null,15,7]
输出：true
```
```
输入：root = [1,2,2,3,3,null,null,4,4]
输出：false
```
```
输入：root = []
输出：true
```

提示：

- 树中的节点数在范围 `[0, 5000]` 内
- `-104 <= Node.val <= 104`

## 解法

本题属于二叉树最大深度 [Maximum Depth of Binary Tree](../maximum_depth_of_binary_tree/) 的衍生题，在向下递归判断是否平衡树的同时，需要计算左右子结点的深度差

## 代码

```cpp
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (!root) {
            return true;
        }
        if (std::abs(maxDepth(root->left) - maxDepth(root->right)) > 1) {
            return false;
        }

        return isBalanced(root->left) && isBalanced(root->right);
    }

private:
    int maxDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }

        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
```
