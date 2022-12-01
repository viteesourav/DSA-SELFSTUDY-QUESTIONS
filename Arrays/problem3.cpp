//using binary-search to find the sum, rotation-count and min in Array

#include <iostream>

using namespace std;

bool searchSumInArray(int arr[], int size, int searchSum) {
    //we will use 2-pointer tech to search the sum.
    //finding the pivort
    int h=0;
    for(h=0;h<size-1;h++) {
        if(arr[h] > arr[h+1])
        break;
    }
    int l= h+1;
    
    //this condition is valid since one will increase and the other will decrease...
    while(l!=h) {
        
        if(arr[l]+arr[h] == searchSum)
        return true;
        
        if(arr[l]+arr[h] > searchSum) {  //reduce the sum value by decrease the max number..
            h=(size+h-1)%size;
        } else {
            l= (l+1) %size;
        }
        
    }
    return false;
}

int findRotationCount(int arr[], int size) {
    //We will use binary search to find the location of the sortest element.
    int l=0,h=size-1;
    
    while(l<=h) {
        int mid = (l+h)/2;
        
        if(arr[mid] <= arr[(size+mid-1)%size]) {
            return mid;
        } else {
            if(arr[mid] <= arr[h])
            h=mid-1;
            else
            l=mid+1;
        }
    }
    return 0;
}

int findMin(int arr[], int l, int h) {
    //we will use an efficient method to find the min element.
    //using binary search with a differnt condition.
    while(l<h) {
        int mid= (l+h)/2;
        
        if(arr[mid] == arr[h])
        h--;
        else if(arr[mid] > arr[h])
        l = mid+1;
        else
        h=mid;
    }
    return arr[h];
}

int main()
{
    int arr[] = {5, 18, 12, 15, 2, 2, 4, 5, 6};
    int size = sizeof(arr)/sizeof(int);
    // int searchSum = 2;
    // if(searchSumInArray(arr, size, searchSum)){
    //     cout<< "Found";
    // }else {
    //     cout<< "Not Found";
    // }
    
    //cout<<"Rotation Count: "<<findRotationCount(arr, size);
    
    cout<<"Find min Element: "<<findMin(arr, 0 , size-1);
    

    return 0;
}
