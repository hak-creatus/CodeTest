//
//  CT10816.cpp
//  CT2750
//
//  Created by 함범진 on 2022/01/12.
//

#include <iostream>

using namespace std;

int *sorted;

void merge(int *arr, int s, int mid, int e){
    int i = s;
    int j = mid + 1;
    int k = s;
    
    while(i <= mid && j <= e){
        if (arr[i] < arr[j]){
            sorted[k] = arr[i];
            i++;
        }
        else{
            sorted[k] = arr[j];
            j++;
        }
        k++;
    }
    
    if (i <= mid){
        for (int t = i; t <= mid; t++){
            sorted[k] = arr[t];
            k++;
        }
    }
    else{
        for(int t = j; t <= e; t++){
            sorted[k] = arr[t];
            k++;
        }
    }
    
    for (int i = s; i <= e; i++){
        arr[i] = sorted[i];
    }
    
    return;
}

void merge_sort(int *arr, int s, int e){
    if (s < e){
        int mid = (s + e) / 2;
        merge_sort(arr, s, mid);
        merge_sort(arr, mid + 1, e);
        merge(arr, s, mid, e);
    }
    
    return;
}

int bs(int **arr, int target, int s, int e){
    int i = s;
    int j = e;
    int mid;
    
    while(i <= j){
        mid = (i + j) / 2;
        
        if (arr[mid][0] > target){
            j = mid - 1;
        }
        else if (arr[mid][0] < target){
            i = mid + 1;
        }
        else{
            return arr[mid][1];
        }
    }
    
    return 0;
}

int main(void){
    int N;
    scanf("%d", &N);
    
    int *arr = new int[N];
    sorted = new int[N];
    for (int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
        sorted[i] = 0;
    }
    
    merge_sort(arr, 0, N - 1);
    
    delete sorted;
    
    int ** A = new int*[N];
    for (int i = 0; i < N; i++){
        A[i] = new int[2];
        for (int j = 0; j < 2; j++){
            A[i][j] = 0;
        }
    }
    
    int idx = 0;
    for (int i = 0; i < N; i++){
        if (i == 0){
            A[i][0] = arr[i];
            A[i][1] += 1;
        }
        else{
            if (A[idx][0] == arr[i]){
                A[idx][1] += 1;
            }
            else{
                idx += 1;
                A[idx][0] = arr[i];
                A[idx][1] += 1;
            }
        }
    }
    
    int s = 0;
    int e = idx;
    
    int M;
    scanf("%d", &M);
    for (int i = 0; i < M; i++){
        int target;
        scanf("%d", &target);
        printf("%d\n", bs(A, target, s, e));
    }
    
    return 0;
}
