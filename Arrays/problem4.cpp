//Hamming Distance in case of Rotation of Array

#include <iostream>

using namespace std;

int findPivort(int arr[], int size) {
    
    int l=0,h=size-1,mid = 0;
    
    while(l<=h) {
        mid = (l+h)/2;
        
        if(arr[mid] < arr[(size+mid-1)%size])
        return mid;
        
        if(arr[mid] < arr[h])
        h=mid-1;
        else 
        l= mid+1;
    }
    return -1;
}

int findMaxHam(int arr[], int size) {
    
    //crated the space for 2 times the given array !
    int brr[2*size];
    for(int i=0;i<size; i++) {
        brr[i]= brr[size+i+1] = arr[i];
    }
    
    //now finding the hamming..
    int maxHam = arr[0];
    
    for(int i=1; i< size; i++) {
        
        int currentHam = 0; // per loop we will find the ham and compare with the maxHam;
        
        for(int j=i,k=0; k<size; j++,k++) {
            if(brr[k] != brr[j%size])
            currentHam++;
        }
        
        //additional check because if this is true no need to do anything else..
        if(currentHam == size)
        return currentHam;
        
        if(currentHam > maxHam)
        maxHam = currentHam;
    }
    
    return maxHam;
    
}

//hamming better approach with space -O(1);
int findHamMax(int arr[], int size) {
    
    int maxHam = arr[0];
    
    //track the rotation...
    for(int j=1; j<size; j++) {
        
        int currentHam = 0;
        
        for(int i=0; i<size; i++) {
            if(arr[i] != arr[(i+j)%size])
            currentHam++;
        }
        
        //hamming exit case:
        if(currentHam == size)
        return currentHam;
        
        if(currentHam > maxHam)
        maxHam = currentHam;
    }
    return maxHam;
}


//This is how you relatively track the postion of any element in an rotated sorted array.
int findPostnAfterRoatation(int arr[], int rotation[][2], int noOfRotation, int index) {
    
    int i = noOfRotation-1;
    
    while(i>=0) {
        
        int leftIndex = rotation[i][0],rightIndex = rotation[i][1];
        
        if(index >= leftIndex && index <= rightIndex) {
            if(index == leftIndex)
            index = rightIndex;
            else
            index--;
        }
        i--;
    }
    return index;
}

int main()
{
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr)/sizeof(int);
    // cout<<"The smallest element is at index: "<<findPivort(arr, size);
    //cout<< "Hamming distance: "<< findMaxHam(arr, size)<<endl;
    //cout<< "Method 2 --> Hamming distance: "<< findHamMax(arr, size);
    int noOfRotation =2;
    int rotation[noOfRotation][2] = {{0,2},{0,3}};
    int eleAtIndex = 2;
    cout<< "Postition after rotation: "<< arr[findPostnAfterRoatation(arr, rotation, noOfRotation, eleAtIndex)]<<endl;
    
    return 0;
}
