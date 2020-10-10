# Sqrt(x)

## 描述

实现 `int sqrt(int x)` 函数。

计算并返回 `x` 的平方根，其中 `x` 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

```
输入: 4
输出: 2
```
```
输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
```

## 解法 (二分法)

此题可以用二分法在 $[0, x]$ 区间中搜索。由于题目的输入是整数并且要求的输出也是整数 (舍弃小数部分)，假设 `mid` 是最终结果，那么从程序上可以将这个整数要求转化为

```cpp
mid * mid > 1 && (mid + 1) * (mid + 1) <= x
```

其中等号的位置取决与使用哪种二分法，此处的写法可以包含 `x = 0` 和 `x = 1` 的情况。由于是二分法，该算法时间复杂度为 $O(\log{n})$

> 注意这里使用**64位整型**来保存 `mid` ，其目的是为了避免整型溢出的情况
> e.g.
> 如果 `x = INT_MAX` ，那么第一个中间值将等于 `INT_MAX / 2` 。由于代码中存在 `mid * mid` ，如果编译器不将其转换为长整型就会在报错，这里为了避免这种情况直接将其定义为64位整型

## 代码 (二分法)

```cpp
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        int64_t mid = x;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (mid * mid > x) {
                right = mid - 1;
            } else if ((mid + 1) * (mid + 1) <= x) {
                left = mid + 1;
            } else {
                break;
            }
        }
        return mid;
    }
};
```

## 解法 (牛顿法)

此题也可以使用著名的牛顿法来解，我们定义函数 $f(x)$
$$
f(x)=x^2-a
$$
其中 $a$ 是程序中的 `x` ，也就是函数的输入，根据牛顿迭代法
$$
x_{n+1}=x_{n}-{f(x_{n})}/{f^\prime(x_{n})}
$$
我们可以推导出
$$
x_{n+1}=x_{n}-({x_{n}^2-a})/{2 x_{n}}=({x_{n}+a/x_{n}})/{2}
$$
其中 $x_{n}$ 对应程序中的 `res` ，$a$ 对应程序中的 `x` 。同样的，这里也以**64位整型**来保存 `res`

## 代码 (牛顿法)

```cpp
class Solution {
public:
    int mySqrt(int x) {
        int64_t res = x;
        while (res * res > x) {
            res = (res + x / res) / 2;
        }
        return res;
    }
};
```