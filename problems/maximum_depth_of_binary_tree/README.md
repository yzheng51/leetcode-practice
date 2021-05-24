# Maximum Depth of Binary Tree

## 描述

给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

给定二叉树 `[3,9,20,null,null,15,7]`，
```
    3
   / \
  9  20
    /  \
   15   7
```
返回它的最大深度 3 。

## 解法

基于dfs模板，将深度 `res` 保存为结果变量，每次通过取最大来得到树的深度

## 代码

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int res = 0;
        maxDepthHelper(res, 0, root);

        return res;
    }

private:
    void maxDepthHelper(int &res, int curr, TreeNode *root) {
        if (!root) {
            return;
        }
        res = std::max(res, curr + 1);
        maxDepthHelper(res, curr + 1, root->left);
        maxDepthHelper(res, curr + 1, root->right);
    }
};
```
