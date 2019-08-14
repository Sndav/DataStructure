#include <stdio.h>
#define SWAP(a,b) {int t = a;a =b;b =t;}
// 插入类
void insertSort(int [],int); // 插入排序
void shellSort(int [],int); // Shell排序
// 交互类
void bubbleSort(int [],int); // 冒泡排序
void quickSort(int [],int,int); // 快速排序
// 选择类
void selectSort(int [],int); // 选择排序

void insertSort(int *array, int len){
	int i, j, temp;
	for(i = 1; i < len; i ++){
		temp = array[i];
		for(j = i - 1; j >= 0; j --){
			if(array[j] > temp)
				array[j + 1] = array[j];	
            else break;
		}
		array[j + 1] = temp;
	}
}
void bubbleSort(int a[],int n){
    int i,j,flag = 0;
    for (i=0,flag=0 ;i<n;i++,flag=0){
        for (j = 0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                SWAP(a[j], a[j+1]);
                flag=1;
            }
        }
        if(flag == 0)break;
    }
}
void shellSort(int arr[], int n){
    int i, j, k;
    int temp, gap;
    for (gap = n / 2; gap > 0; gap /= 2){
        for (i = 0; i < gap; i++){
            for (j = i + gap; j < n; j += gap)    
                if (arr[j] < arr[j - gap]){
                    temp = arr[j];
                    k = j - gap;
                    while (k >= 0 && arr[k] > temp) {
                        arr[k + gap] = arr[k];
                        k -= gap;
                    }
                    arr[k + gap] = temp;
                }
        }
    }
}
void quickSort(int a[],int low,int high){
    int i = low,j = high,temp = a[low]; 
    if( low > high)return ;
    while(i < j) {
        while((a[j] >= temp) && (i < j))
            j--; 
        a[i] = a[j];
        while((a[i] <= temp) && (i < j))
            i++; 
        a[j]= a[i];
    }
    a[i] = temp;
    quickSort(a,low,i-1);
    quickSort(a,j+1,high);
}
void selectSort(int a[],int n){
    for(int i=0; i<n-1; i++){
        int min_index = i; 
        for(int j=i+1; j<n; j++)
            if(a[j] < a[min_index])
                min_index = j;
        if( i != min_index){
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
    }
}
