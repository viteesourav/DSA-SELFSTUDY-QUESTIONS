//move all zeros at the end - efficent methods (refer problem5.cpp)

#include <iostream>
#include<vector>

using namespace std;

void swap(int* a, int* b) {
    int temp = *a;
    *a=*b;
    *b = temp;
}

void printarr(int arr[], int n) {
    int i=0;
    while(i < n) {
        cout<<arr[i]<<" ";
        i++;
    }
    cout<<endl;
}

//method1: use vector, remove 0's then add it back :P

void moveAllZerosAtEnd_method1(int a[], int n) {
    
    vector<int> v;
    int count=0;
    for(int i=0;i<n;i++) {
        v.push_back(a[i]);
    }
    
    for(int i=0;i<n;i++) {
        if(v[i]==0){
        v.erase(v.begin()+i);
        i--;
        count++;
        }
    }
    
    for(int i=0;i<count;i++){
        v.push_back(0);
    }
    
    for(int i=0;i<n;i++) {
        a[i]=v[i];
    }
}

//method2: use a variable to track the 0 and replace them with non-zero numbers
void moveAllZerosAtEnd_method2(int a[], int n) {
    int j=0; //track the non-zeros...
    for(int i=0; i < n; i++) {
        if(a[i]!=0) {                   //swap all non-zero elements with j and increment it.
            swap(&a[j], &a[i]);
            j++;
        }
    }
}

//method3: using stable_partition. (using vector..) algorithm or can use the below logic and write iterative method.
//logic: run a counter replace the a[counter] with a[i] and increment counter..
// then from counter to n-1 fill with zeros.

void moveAllZerosAtEnd_method3(int a[], int n){
    
    //see notes for the vector method.
    //iterative method.
    int counter = 0;
    for(int i=0;i<n;i++) {
        if(a[i] != 0){
            a[counter] = a[i];
            counter++;
        }
    }
    for(int i=counter;i<n;i++) {
        a[i] = 0;
    }
}

int main()
{
    int a[] = {5, 6, 0, 4, 6, 0, 9, 0, 8 };
    int n= sizeof(a)/sizeof(a[0]);
    //moveAllZerosAtEnd_method1(a, n);
    //moveAllZerosAtEnd_method2(a, n);
    moveAllZerosAtEnd_method3(a, n);
    printarr(a, n);
    return 0;
}
