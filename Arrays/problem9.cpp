//Arranging the Array in max-min order -> ***multiplication modulus method***

#include<bits/stdc++.h>
using namespace std;
void printarr(int arr[], int n){
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
}
//arrange the element of the array in the max/min form wise...
//method1: using 2 pointer tech wiht T-> O(n) and S-> O(n)
void arrangeInMaxMinForm(int arr[], int n) {
    int b[n];
    int i=0,j=n-1;
    int k=0;
    while(j>=i) {
        if(k%2==0)
        b[k++]=arr[j--];
        else
        b[k++]=arr[i++];
    }
    for(i=0;i<k;i++)
    arr[i]=b[i];
}
//method2: using the multiplication modulus method.
//this will be T->O(n) and S->O(1)
//here using the formula to merge element by element of output array and input array.
void arrangeInMaxMinForm_method2(int arr[], int n) {
    int min=0,max_element = arr[n-1]+1,max=n-1;
    //iterating and putting the formula for even position where we have max element
    // and odd position where we have min element.
    for(int i=0;i<n;i++) {
        if(i%2==0) {
            arr[i] = arr[i] + (arr[max]%max_element)*max_element;
            max--;
        }else {
            arr[i] = arr[i] + (arr[min]%max_element)*max_element;
            min++;
        }
    }
    cout<<"print the array afte the formula modification: "<<endl;
    printarr(arr, n);
    //now dividing by max_element to get the output array
    for(int i=0;i<n;i++)
    arr[i]=arr[i]/max_element;
}
int main() {
    int arr[] = {1,3,4,5,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    //sort the array this algo runs only on sorted array
    sort(arr, arr+n);
    cout<<"sorted array: "<<endl; printarr(arr, n);
    cout<<endl;
    //after this we can use two method:
    // arrangeInMaxMinForm(arr, n);
    // printarr(arr, n);
    arrangeInMaxMinForm_method2(arr, n);
    printarr(arr, n);
    return 0;
}