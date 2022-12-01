//Adjant swaps can make an array sorted ?

#include<bits/stdc++.h>
using namespace std;

bool isSortedArr(int arr[], int brr[], int n) {
    
    //if arr[i]>arr[i+1] and swap allowed swap it.
    for(int i=0;i<=n-2;i++) {
        if(arr[i] > arr[i+1]) {
            if(brr[i]==1) swap(arr[i], arr[i+1]);
        }
    }
    
    //see if the arr is sorted or not.
    for(int i=0;i<=n-2;i++) {
        if(arr[i]>arr[i+1]) return -1;
    }
    return 0;
}

int main() {
    
    //can arr be sorted by adjacent swaps ?
    //brr[i] = 1 the swap(arr[i], arr[i+1]) allowed.
    
    int arr[] = {2, 3, 1, 4, 5, 6};
    int brr[] = {0, 1, 1, 1, 1};
    int n = sizeof(arr)/sizeof(int);
    
    bool result = isSortedArr(arr, brr, n);
    
    cout<<result<<endl;  //true can be sorted, false cannot be sorted.
    
    return 0;
}