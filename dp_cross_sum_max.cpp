#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
#define maxn 6666

// 本次例题： 一串数字里选出不相邻的数加起来和最大

// recursive 型   opt stands for optimal 最优的
int rec_opt(int arr[],int i){

    if(i == 0)return arr[0];
    else if(i == 1)
        return max(arr[0],arr[1]);
    else{
        int tmp1 = rec_opt(arr,i-2)+arr[i];  // 表示选了第i个，然后因为不能相邻，所以是opt【i-2】表示前i-2的最优解
        int tmp2 = rec_opt(arr,i-1);  // 表示不选，然后最优解自然就是前i-1了啦
        return max(tmp1,tmp2);
    }
}

// 非递归型
int opt[maxn];
int dp_opt(int arr[],int len){
    // debug part
    printf("len=%d\n",len);
    for(int i=0;i<len;i++){
        opt[i] = 0;
    }
    opt[0] = arr[0];  // 只有一个元素时
    opt[1] = max(arr[0],arr[1]);  // 只有2个元素时
    for(int i = 2;i < len;i++){
        int tmp1 = opt[i-2] + arr[i]; // 选
        int tmp2 = opt[i-1];          // 不选
        opt[i] = max(tmp1,tmp2);
    }
    return opt[len-1];
}

int main(){

    int arr[] = {1,2,4,1,7,8,3};
    printf("%d\n",dp_opt(arr,7));
    return 0;
}
