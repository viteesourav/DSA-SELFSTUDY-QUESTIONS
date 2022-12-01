//Find unique elements in the Array

#include<bits/stdc++.h>
using namespace std;


//method1: use XOR logic. T->O(n) and S->O(1)
//basically, all elements will be in XOR with each other. Same elements will give 0 and the only left one will be the result.

int findUnique_method1(int arr[], int n) {
    
    int res = 0;
    
    for(int i=0;i<n;i++) {
        res = res ^ arr[i];
    }
    return res;
}

int main() {
    
    //first we have an array with 1 unique and we need to find it.
    int arr[] = {2, 3, 5, 4, 5, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int unique = 0;
    
    //using XOR Logic
    unique = findUnique_method1(arr, n);
    
    
    cout<<"Unique number: "<<unique<<endl;
    
    return 0;
    
}