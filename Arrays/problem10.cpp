//Array Arrangment --> +ve at even and -ve at odd --> **Hoare's Partition of Quick Sort**
//Once see the difference between problem6 and this one...

#include<bits/stdc++.h>
using namespace std;

void printArr(int arr[], int n){
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}

//method1: using the hoare's partition of Quick sort tech
//two pointers one track the positive and the othre track the negative 
//scan the entire array and swap.
void arrangeArr_method1(int arr[], int n) {
    
    //i track +ve and j track -ve
    int i=0,j=1;
    
    while(true) {
        
        //Find the index of the no who is negative at even place.
        while(i<n && arr[i]< 0)
        i+=2;
        
        //find the index of the number who is negative at odd place.
        while(j<n && arr[j] > 0)
        j+=2;
        
        //now we just exchange those two....
        if(i<n && j<n)
        swap(arr[i], arr[j]);
        else 
        break;
    }
    
    //T-> O(n^2) S-->O(1). 
}

//my method: method2 O(n) and O(1)
//segregate all the -ve and +ve number using 2 pointer tech.
//then use two pointer to alternatively swap the numbers
void arrangeArr_method2(int arr[], int n) {
    
    int neg= -1;
    
    for(int i=0;i<n;i++){
        if(arr[i]<0){
            neg++;
            swap(arr[neg],arr[i]);
        }
    }
    
    //now neg points at the last index of the negative number.
    for(int i=0,j=neg+1;j<n;j++){
        if(arr[i]<0) {
            swap(arr[i],arr[j]);
            i+=2;
        }
    }
}



int main() {
    
    //arranging the number such that +ve at even and -ve at odd.
    int arr[] = {1, -3, 5, 6, -3, 6, 7, -4, 9, 10};
    int n= sizeof(arr)/sizeof(arr[0]);
    
    //arrangeArr_method1(arr,n);
    arrangeArr_method2(arr,n);
    
    printArr(arr, n);
    
    
    return 0;
}