//Leader Elements in an array --> all elements towards right less that this array

#include<bits/stdc++.h>

using namespace std;

//method1: from right to left keep track of the max Element.
void printLeaders_m1(int arr[], int n) {
    
    int max = INT_MIN;
    
    for(int j=n-1;j>=0;j--) {
        if(arr[j] > max){
            max=arr[j];
            cout<<max<<" ";
        }
    }
    cout<<endl;
}

//method2: same just append the max element in a stack.
void printLeaders_m2(int arr[], int n){
    
    int max = INT_MIN;
    stack<int> s;
    for(int j=n-1;j>=0;j--) {
        if(arr[j] > max) {
            max= arr[j];
            s.push(max);
        }
    }
    
    while(!s.empty()) {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main() {
    
    //Print all the leader Element(all element towards right is lessthan this element) of an array.
    
    int arr[] = {16, 17, 4, 3, 5, 2};
    int n= sizeof(arr)/sizeof(arr[0]);
    
    //method1: if orders doesn't matter...
    printLeaders_m1(arr, n);
    
    //method2: if order matters --> use stack;
    printLeaders_m2(arr, n);
    
    return 0;
}
