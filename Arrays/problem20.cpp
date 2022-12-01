//Peak Elements --> binarySearch Logic

#include<bits/stdc++.h>

using namespace std;

//method1: using one for loop..
int findPeakPost_m1(int arr[], int n) {   //O(n)  O(1)
    
    if(n==1) return 0;
    //check the first and last element for peak..
    if(arr[0] >= arr[1]) return 0; // first element as peak...
    if(arr[n-1] >= arr[n-2]) return n-1; //last element as peak...
    
    for(int i=1; i<=n-2;i++) {
        if((arr[i-1] < arr[i]) && (arr[i+1] < arr[i])) return i;
    }
    return -1;
}

//method2: using binary search  O(logn) O(1)
int findPeakPost_m2(int arr[], int n) {
    
    int l=0,h=n-1;
    
    while(l<=h) {
        int mid = (l+h)/2;
        if((arr[mid-1] < arr[mid]) && (arr[mid+1] < arr[mid])) return mid;
        
        if(arr[mid-1] >= arr[mid]) h=mid-1;
        else if(arr[mid+1] >= arr[mid]) l=mid+1;
    }
    return -1;
}

int main() {
    
    //find the peak element post...
    
    int arr[] = {10, 20, 15, 2, 23, 90, 67};
    int n= sizeof(arr)/sizeof(arr[0]);
    int op1 =0,op2=0;
    //method1: using the normal for loop.
    op1 = findPeakPost_m1(arr, n);
    
    //method2: using binary search method..
    op2 = findPeakPost_m2(arr, n);
    
    cout<<op1<<endl<<op2<<endl;
    return 0;
}
