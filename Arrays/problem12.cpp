//Find Sum-Pair in the given array

#include<bits/stdc++.h>
using namespace std;

void ptintArr(int arr[], int n) {
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}

//method1: using 2-pointer tech  O(nlogn) or O(n2) --depending the sorting algo.
void findSumPair_method1(int arr[], int n, int sum) {
    
    //first sort the array...
    sort(arr, arr+n);
    ptintArr(arr, n);
    
    int i=0,j=n-1;
    while(i<=j) {
        int t= arr[i]+arr[j];
        if(t== sum){
            cout<<arr[i]<<" "<<arr[j]<<endl;
            break;
        }
        if(t > sum) j--;
        else if(t<sum) i++;
    }
}

//method2: lets use the set to store the counter sum of element -o(n)
void findSumPair_method2(int arr[], int n, int sum) {
    
    unordered_set<int> s;
    for(int i=0;i<n;i++) {
        int counter = sum -arr[i];
        if(s.find(counter) != s.end()) {
            cout<<arr[i]<<" "<<counter<<endl;break;
        }else {
            s.insert(arr[i]);
        }
    }
}

//method3: using the map.
void findSumPair_method3(int arr[], int n, int sum) {
    
    map<int, int> map;
    for(int i=0;i<n;i++) {
        int counter = sum -arr[i];
        if(map.find(counter) != map.end()) {
            cout<<arr[i]<<" "<<counter<<endl;break;
        }else {
            map.insert({arr[i], counter});
        }
    }
}

int main() {
    
    int arr[] = {1, 4, 45, 6, 10, 8 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 16;
    //method1: use the 2 pointer tech by sorting the arr.
    //findSumPair_method1(arr, n, sum);
    //method2: use the set and store the seen element in it. if found then print the pair.
    //findSumPair_method2(arr, n, sum);
    //method3: use hashMAp same above logic but using map.
    findSumPair_method3(arr, n, sum);
    
    
    return 0;
}