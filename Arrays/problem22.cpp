//Triplet in an array with the given sum

#include<bits/stdc++.h>

using namespace std;

//method1: using a loop and  2 pointer tech...
vector<int> findTripleSumArr_m1(int arr[], int n, int target) {
    
    //lets sort the element
    sort(arr, arr+n);
    vector<int> v;
    
    for(int i=0;i<=n-3;i++) {
        
        int sum = target - arr[i];
        
        //now inside use the 2-pointer tech for finding sum in a sorted array...
        int l=i+1,r= n-1;
        while(l < r) {
            if(sum == (arr[l] + arr[r])) {
                v.push_back(arr[i]);
                v.push_back(arr[l]);
                v.push_back(arr[r]);
                return v;
            }
            if((arr[l] + arr[r]) > sum) r--;
            else l++;
        }
    }
    v.push_back(-1);
    return v;
}

//method2: we can use a hashset to look for the element between i+1 and j-1
vector<int> findTripleSumArr_m2(int arr[], int n, int target) {
    
    vector<int> v;
    
    for(int i=0;i<n;i++) {
        
        unordered_set<int> s;
        int currentSum = target -arr[i];
        for(int j=i+1;j<n;j++) {
            if(s.find(currentSum-arr[j]) != s.end()) {
                v.push_back(arr[i]);
                v.push_back(currentSum-arr[j]);
                v.push_back(arr[j]);
                return v;
            }
            else {
                s.insert(arr[j]);
            }
        }
    }
    v.push_back(-1);
    return v;
}

int main() {
    
    //Find triplets with the given sum...
    int arr[] = { 1, 4, 45, 6, 10, 8 };
    int n= sizeof(arr)/sizeof(arr[0]);
    int sum = 22;
    vector<int> v1,v2;
    
    //method1: using loop and a 2 pointers tech..
    v1 = findTripleSumArr_m1(arr, n, sum);
    
    //method2: using hashset..
    v2 = findTripleSumArr_m2(arr, n, sum);
    
    for(auto it = v1.begin(); it!=v1.end(); it++)
    cout<<*it<<" ";
    cout<<endl;
    for(auto it = v2.begin(); it!=v2.end(); it++)
    cout<<*it<<" ";
    cout<<endl;
    return 0;
}
