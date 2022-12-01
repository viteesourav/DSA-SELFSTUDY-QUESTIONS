//Equilibrium Sum ---> concept of PrefixSum and Suffix Sum

#include<bits/stdc++.h>

using namespace std;

//using two arrays to store the prefixSum and suffixSum and then compare index with same value O(n) and O(n)
int findEqSum_method1(int arr[], int n) {
    
    int prefixSum[n], suffixSum[n];
    prefixSum[0] = arr[0];
    suffixSum[n-1] = arr[n-1];
    
    int ans = INT_MIN;
    
    //now i got arr with all right sum for an index i
    for(int i=1;i<n;i++)
    prefixSum[i]=prefixSum[i-1]+arr[i];
    
    for(int j=n-2;j>=0;j--){
        suffixSum[j] = suffixSum[j+1]+arr[j];
        if(suffixSum[j]==prefixSum[j]){
            ans = max(ans, suffixSum[j]);  //take the max Eq sum in case you have more than 1 eq sum in the arr.
        }
    }
    return ans;
}


//method2 : using accumulate...  O(n) O(1).
int findEqSum_method2(int arr[], int n) {
    
    int ans = INT_MIN;
    
    //we will get the entire sum of arr at once..
    int sum = accumulate(arr, arr+n, 0);
    
    int prefixSum = 0;
    
    for(int i=0;i<n;i++) {
        prefixSum+=arr[i];
        if(prefixSum == sum) {
            ans = max(ans, sum);
        }
        sum-=arr[i];
    }
    return ans;
}

int main() {
    
    //Finding the equilibrium max sum i.e suffixSum for index i = prefixSum for index i
    
    int arr[] = {-2, 5, 3, 1, 2, 6, -4, 2 };
    int n= sizeof(arr)/sizeof(arr[0]);
    int maxEqSum1 = 0;
    int maxEqSum2 = 0;
    //method1: when extraspace is allowed..
    maxEqSum1 = findEqSum_method1(arr, n);
    //method2: when extraspace is not allowed.. (use accumulate)
    maxEqSum2 = findEqSum_method2(arr, n);
    
    cout<<maxEqSum1<<endl<<maxEqSum2<<endl;
    return 0;
}
