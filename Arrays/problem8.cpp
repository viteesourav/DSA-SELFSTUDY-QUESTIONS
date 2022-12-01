//veryIMP --> sliding window 2-pointer technique in Arrays

#include<bits/stdc++.h>
using namespace std;
void printarr(int arr[], int n){
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}
//sliding window tech use it when 
//1) you have a window size.
//2) want to perfrom some operation on the sub-array.
//3) find max/min or max sum or min of that sub-array in the window size.
// T-> O(n) S-> (1)
//method1: it is just used the sliding window tech using 2 pointers to find the min swap.
int minSwapToBringTogether_method1(int arr[], int n, int k) {
    int window_size = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] <= k)
        window_size++;
    }
    //in the first window, find the number of unwanted element.
    int noOfBadEleInWindow = 0;
    for(int i=0;i<window_size;i++){
        if(arr[i] > k)
        noOfBadEleInWindow++;
    }
    int min_badElement = noOfBadEleInWindow;
    //no take two pointer --> one at start of the window and one at the end and slide the window and .
    //update the noOfBadEleInWindow accordingly.
    for(int i=0,j=window_size-1;j<=n;j++,i++) {
        if(arr[i] > k) noOfBadEleInWindow--;
        if(arr[j] > k) noOfBadEleInWindow++;
        min_badElement = min(min_badElement, noOfBadEleInWindow);  //take the min noOfBadEle in the window.
    }
    return min_badElement;
}
//method2: same tech but using a snowball counter.
//it gets bigger if cond satisfy in the window sized array else it will get small.
int minSwapToBringTogether_method2(int arr[], int n, int k) {
    int windowSize = 0; //size of the window first zero.
    //to find the window size..
    for(int i=0;i<n;i++)
    {
        if(arr[i]<=k)
        windowSize++;
    }
    //find the bad element count in the first windwow.
    int snowball = 0; // keep track of bad element in the arr.
    for(int i=0;i<windowSize;i++) {
        if(arr[i] > k)
        snowball++;
    }
    int min_swap = snowball; //keep track of the min of the snowball in each iteration.,
    //slide the window gradually and modify the snowball size.
    for(int i=windowSize-1;i<=n;i++) {
        if(arr[i] > k) snowball++;
        if(arr[i-windowSize] >k) snowball--;
        min_swap = min(min_swap, snowball);
    }
    return min_swap;
}
int maxSumForKsubset(int arr[], int n, int k) {
    int windowSize = k, max_sum=0;
    //find the max sum for the first window..
    for(int i=0;i<windowSize;i++) {
        max_sum+=arr[i];
    }
    int sum = max_sum; // keep track of the sum of the window elements.
    //now slide the window and compare the sum with the max_sum
    for(int i=windowSize;i<n;i++) {
        sum = sum + arr[i] - arr[i-windowSize];
        max_sum = max(max_sum, sum);
    }
    return max_sum;
}
int main() {
    int arr[] = {2,1,5,6,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    //Given an int k, min swap required to bring all elements of k together..
    int k=3;
    //int min_swap = minSwapToBringTogether_method1(arr, n, k); //2-pointer method
    // int min_swap = minSwapToBringTogether_method2(arr, n, k);  // sliding window tech using snowball counter.
    // cout<<min_swap<<endl;
    //printarr(arr, n);
    //Given an array find the max sum for the k subset of ele in arr..
    int max_sum = maxSumForKsubset(arr, n, k);
    cout<< max_sum << endl;
    return 0;
}