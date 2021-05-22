/******************************************************************************
Date: 22 May 2021
Author: Nehal Ram
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void merge_sort(int *arr, int start, int end);
void merge(int *arr, int start, int mid, int end);
void display(int *arr, int len);

int main()
{
    int list[5] = {2, 5, 7, 3, 4};
    int start = 0, end = 5;
    display(list, end);
    merge_sort(list, start, end - 1);
    display(list, end);
    return 0;
}

void display(int *arr, int len) {
    int i = 0;
    for (i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge_sort(int *arr, int start, int end) {
    int mid = 0;
    if (start < end) {

        mid = start + (end - start) / 2;
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        
        merge(arr, start, mid, end);
    }
}

void merge(int *arr, int start, int mid, int end) {
    
    int *temp1 = (int *)malloc(sizeof(int) * (mid - start + 1));            // 0 - 0 + 1 = 1
    int *temp2 = (int *)malloc(sizeof(int) * (end - mid));                  // 1 - 0 = 1
    
    int i = 0;
    int a = 0, b = 0;
    
        
    for(i = 0; i < (mid - start + 1); i++) {
        temp1[i] = arr[start + i] ;
    }
    
        
    for(i = 0; i < (end - mid); i++) {
        temp2[i] = arr[mid + i + 1 ];
    }
    
    
    i = start;
    while(a < (mid - start + 1) && b < (end - mid)) {
        arr[i++] = temp1[a] <  temp2[b] ?  temp1[a++] : temp2[b++];
    }
    
    while(a < (mid - start + 1)) {
        arr[i++] = temp1[a++];
    }
    
    
    while(b < (end - mid)) {
        arr[i++] = temp2[b++];
    }
}
