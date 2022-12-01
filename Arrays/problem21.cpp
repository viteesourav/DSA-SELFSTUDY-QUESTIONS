//find subArray with given sum

#include<bits/stdc++.h>

using namespace std;

//method1: using 2 pointer tech...
vector<int> findSumArr_m1(int arr[], int n, int target) {
    
    int i=0,j=0,currentSum=0;
    vector<int> v;
    
    while(currentSum >= target) {
        currentSum+=arr[j];
        j++;
    }
    while(i<n && j<n) {
        
        if(currentSum == target) {
        v.push_back(i);
        v.push_back(j-1);
        return v;
        }
        if(currentSum > target) {
            currentSum-=arr[i];
            i++;
        }
        else {
            currentSum+=arr[j];
            j++;
        }
        
    }
    v.push_back(-1);
    return v;
}


int main() {
    
    //subarray with the given sum...
    int arr[] = {1, 4, 20, 3, 10, 5};
    int n= sizeof(arr)/sizeof(arr[0]);
    int sum = 33;
    vector<int> v;
    
    //method1: using 2 pointers tech..
    v = findSumArr_m1(arr, n, sum);
    
    for(auto it = v.begin(); it!=v.end(); it++)
    cout<<*it<<endl;
    return 0;
}
