//Binary-search to find,insert and delete in soerted array

#include<bits/stdc++.h>
using namespace std;

void ptintArr(int arr[], int n) {
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}

//using the binary search reduce time O(log n)
int findElement(int arr[], int n, int key) {
    
    int l=0,h=n-1;
    
    while(l<=h) {
        int mid = (l+h)/2;
        
        if(arr[mid] == key) return mid;
        
        if(arr[mid] > key) h=mid-1;
        else l=mid+1;
    }
    
    return -1;
}


void insertElement(int arr[], int &n, int val) {
    
   int i= n-1;
   while(arr[i] > val and i>=0) {
       arr[i+1] = arr[i];
       i--;
   }
   arr[i+1] = val;
   n++;
}

//for deleting an element. Find the postn using binary Search and then left shift all right elements.
void deleteAt(int arr[], int &n, int key) {
    
    int post = findElement(arr, n, key);
    
    if(post == -1) cout<<"Element not found cannot delete"<<endl;
    else {
        int i=post;
        while(i <= n-2){
            arr[i] = arr[i+1];
            i++;
        }
        n--;
    }
}

int main() {
    
    int arr[20] = { 5,7, 10, 8, 6, 9 };
    int cap = sizeof(arr)/sizeof(arr[0]); int n = 6;
    
    //now we are given an unsorted array. we will define insert,delete and find operation.
    sort(arr, arr+n);
    ptintArr(arr, n);
    
    //now the array is sorted,
    //find operation
    int find = findElement(arr, n, 8);
    
    if(find == -1) cout<<"Element Not Found"<<endl;
    else cout<<"Element Found"<<endl;
    
    //adding an element in the sorted array.
    insertElement(arr, n, 3 );
    ptintArr(arr, n);
    
    //delete the element at a particular index.
    deleteAt(arr, n, 7 );
    ptintArr(arr, n);
    
    
    return 0;
}