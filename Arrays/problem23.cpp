//stable_sort --> implementations

#include<bits/stdc++.h>
using namespace std;

//print the array
void printarr(int arr[], int n) {
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}

//If the compare funtion just needs two argument the you can wrtie like this and call it.
bool compare(int a, int b) {
    return (a<b);             //this will sort the arr in ascending order.
}


int main() {
    
    //We will see how to use stable_sort().
    //sort this array based on the abs diff with a number x.
    int arr[] = { 10, 5, 3, 9, 2 };
    int n = 5;
    int x = 7;
    
    //will use lambda function to define the comparae function. since we need additional parameter in that compare function.
    stable_sort(arr, arr+n, [x](int a, int b){
        return (abs(x-a) < abs(x-b));
    });
    
    printarr(arr, n);
}