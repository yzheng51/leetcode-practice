# Same Tree

## 描述

给你两棵二叉树的根节点 `p` 和 `q` ，编写一个函数来检验这两棵树是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

```
输入：p = [1,2,3], q = [1,2,3]
输出：true
```
```
输入：p = [1,2], q = [1,null,2]
输出：false
```
```
输入：p = [1,2,1], q = [1,1,2]
输出：false
```

提示：

- 两棵树上的节点数目都在范围 `[0, 100]` 内
- `-104 <= Node.val <= 104`

## 解法

递归算法，注意根节点的 `NULL` 情况

## 代码

```cpp
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q) {
            return true;
        }
        if (!p || !q) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        return isSameTree(p->left, q->left) && isSameTree(q->right, p->right);
    }
};
```
