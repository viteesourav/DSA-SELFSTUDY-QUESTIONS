//Find the duplicates in the array

#include<bits/stdc++.h>
using namespace std;

//print the arr
void printArr(int arr[], int n) {
    for(int i=0;i<n;i++) cout<<arr[i]<< " ";
    cout<<endl;
}


//method1: using hashSet to store the visited nodes. T-O(n) S- O(n)
int findDuplicate_method1(int arr[], int n) {
    
    unordered_set<int> s;
    for(int i=0;i<n;i++) {
        if(s.find(arr[i]) != s.end()) {
            return arr[i];break;
        }
        s.insert(arr[i]);
    }
    return -1;
}

//method2: sort the entire arr and then compare the array for adjasent equal values. O(n), O(1)
int findDuplicate_method2(int arr[], int n) {
    
    //sort it 
    sort(arr, arr+n);
    printArr(arr, n);
    
    int key = arr[0];
    for(int i=1;i<n;i++) {
        if(arr[i] == key) return key;
        else key = arr[i];
    }
    return -1;
}


//method3: using XOR Logic...
// x^x = 0 but x^y = z and x^z = y

int findDuplicate_method3(int arr[], int n) {
    
    int res = 0;
    for(int i=0;i<n-1;i++) {
        res=res^(i+1)^arr[i];  //XOR between (index+1) and arr[index] and res.
    }
    res = res^arr[n-1];
    return res;
}

//method4: using indexing menthod
//for ele at index, go to arr[ele] and change the sign of the value to -ve.
//if again you see negative at the same location, break and retrun. (use abs as we are going out of bound of the arr in case if ele > arr_size)

int findDuplicate_method4(int arr[], int n) {
    
    for(int i=0;i<n;i++) {
        int index = (arr[abs(arr[i])]); //going to the location of the ele.
        if(index < 0)        //check if it is negative.
        return arr[i];  //if yes return it.
        arr[abs(arr[i])] = -arr[abs(arr[i])]; //if no make it nagative.
    }
    return -1;
}


int main() {
    
    //first we have an array with 1 duplicate and we need to find it.
    int arr[] = {1, 5, 3, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int duplicate = 0;
    
    //using hashSet
    //duplicate = findDuplicate_method1(arr, n);
    //using sorting and then index comparision
    //duplicate = findDuplicate_method2(arr, n);
    //using XOR Logic
    //duplicate = findDuplicate_method3(arr, n);
    //using indexing
    duplicate = findDuplicate_method4(arr, n);
    
    
    
    cout<<"duplicate number: "<<duplicate<<endl;
    
    return 0;
    
}