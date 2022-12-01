//search a key in sorted rotated array

#include <iostream>

using namespace std;

void printArray(int[], int);

int searchKey(int arr[], int l, int h, int key) {
    
    if (l > h)
    return -1;
    
    int mid = (l+h)/2;
    if(arr[mid] == key) {
        return mid;
    }
    //If the first half is sorted...
    if(arr[l] < arr[mid]) {
        //search in the sorted half
        if(key > arr[l] && key < arr[mid]) {
            return searchKey(arr, l, mid-1, key);
        } else {
            //search in the unsorted half.
            return searchKey(arr, mid+1, h, key);
        }
    } else {   // If the first half is unSorted...
        //search in the other sorted half..
        if(key > arr[mid] && key < arr[h]) {
            return searchKey(arr, mid+1, h, key);
        } else {
            // search in the unsorted half..
            return searchKey(arr, l, mid-1, key);
        }
    }
}

int main()
{
    int arr[] = { 4, 5, 6, 7, 8, 9, 1, 2, 3 };
    int size = sizeof(arr)/sizeof(int);
    int key= 6;
    int search = searchKey(arr, 0, size-1, key);
    if(search == -1)
    cout<<"Element Not found !";
    else 
    cout<<"Element Found at "<< search<< " index.";
    return 0;
}

void printArray(int arr[], int size) {
    for(int i=0;i<size; i++) {
        cout<<arr[i]<<" ";
    }
}