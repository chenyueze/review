/*************************************************************************
	> File Name: 15-binary_search.cpp
	> Author: chenyueze
	> Mail: chen_buzhou@163.com
	> Created Time: 日  9/ 6 10:30:10 2020
 ************************************************************************/
#include <stdio.h>

int f(int x){
    return x * x;
}

int binary_search_f(int (*f)(int), int y){
    int l = 0, r = y;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(f(mid) > y) r = mid - 1;
        if(f(mid) == y) return mid;
        if(f(mid) < y) l = mid + 1;
    }
    return -1;
}

int binary_search(int *arr, int n, int x){
    int l = 0, r = n;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(arr[mid] > x) r = mid - 1;
        if(arr[mid] == x) return mid;
        if(arr[mid] < x) l = mid + 1;
    }
    return -1;
}

int main(){
    int n, x, y;
    /*int arr[100] = {0};
    printf("请输入n\n");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("输入 arr[%d]\n", i);
        scanf("%d", &arr[i]);
    }
    printf("输入 x\n");
    scanf("%d", &x);
    printf("---- : %d", binary_search(arr, n - 1, x));
    */
    printf("输入 y\n");
    scanf("%d", &y);
    x = binary_search_f(f, y);
    printf("%d * %d = %d\n", x, x, y);
    return 0;
}
