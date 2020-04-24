# dp_review

###题意：一串数字里选出不相邻的数加起来和最大

动态规划，递归的话，会出现重叠子问题，所以解决重叠子问题的方法，就是记忆化，用数组存起来哦

代码如下： 
```python
'''

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

'''

import numpy as np

arr = [1, 2, 4, 1, 7 ,8, 3]

def rec_opt(arr,i):
    if i == 0:
        return arr[0]
    elif i == 1:
        return max(arr[0],arr[1])
    else:
        A = rec_opt(arr,i - 2) + arr[i] # chose
        B = rec_opt(arr,i - 1)          # not chose
        return max(A,B)

def dp_opt(arr):
    opt = np.zeros(len(arr))
    opt[0] = arr[0]
    opt[1] = max(arr[0],arr[1])
    for i in range(2,len(arr)):
        A = opt[i-2] + arr[i] # chose
        B = opt[i-1]          # not chose 
        opt[i] = max(A,B)
    return opt[len(arr) - 1]


print("arr len = " , len(arr))
print(dp_opt(arr))
print(rec_opt(arr,6))

```


#python 代码解释：
三、import A as B
        这种方式为给引入的包A定义一个别名B，例如：
eg:
import numpy as np 


numpy 用法 ：NumPy(Numerical Python) 是 Python 语言的一个扩展程序库，支持大量的维度数组与矩阵运算，此外也针对数组运算提供大量的数学函数库。
numpy.zeros（创建0矩阵）
返回给定形状和类型的新数组，用零填充。
opt = np.zeros(len(arr)) # 表示初始化一个长度为数组arr的长度的数组，里面全部填0

<img src="https://raw.githubusercontent.com/Vander-Wall/dp_review/master/dp3.png" width = "500" height = "300" alt="" align=center />
