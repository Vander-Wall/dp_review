'''
题目给一个数组，来选出一些数字加起来等于给定的K，问是否存在这样的方案，若存在，返回ture else 返回false
'''

```
arr = [3, 34, 4, 12, 5 ,2]

def rec_subset(arr, i, s):
	if s == 0:
		return True;
	if i == 0:
		return s == arr[0]
	elif  arr[i]>s:   #剪支操作
		return rec_subset(arr,i-1,s)
	else:
		A = rec_subset(arr,i-1,s-a[i]) # chose
		B = rec_subset(arr,i-1,s)      # not chose
  		return A or B

def dp_subset(arr ,sum):
	# 表示创建一个二维数组  用法1：np.zeros(row,col)   用法二：np.zeros((row,col),dtype = bool) dtype 指定保存的数据类型
	subset = np.zeros((len(arr),s+1),dtype = bool)  
	subset[:,0] = True   #  ":" 代表整个，所以这个代表的是  subset[:,0] 表示的是所有行的第0个元素
	subset[0,:] = False  #  subset[0,：] 表示的是第0行的所有列
	subset[0,arr[0]] = True
	for i in range(1,len(arr))
		for s in range(1,sum+1)
			if arr[i] > s:
				subset[i,s] = subset[i-1,s]
			else:
				A = subset[i-1,s-arr[i]]
				B = subset[i-1,s]
				subset[i,s] = A or B
	r, c = subset.shape	 							#subset.shape 可以返回 row,col
	return[r - 1][c - 1]
```


<img src="https://raw.githubusercontent.com/Vander-Wall/dp_review/master/dp3.png" width = "600" height = "400" alt="" align=center />











