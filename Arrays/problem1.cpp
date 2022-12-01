//Array Rotations

#include <iostream>

using namespace std;

int find_gcd(int,int);

void reverse_arr(int[], int, int);

void swap_transverse(int[], int, int, int);

void printArray(int arr[], int size) {
    for(int i=0;i<size; i++) {
        cout<<arr[i]<<" ";
    }
}

void rotate(int arr[], int size, int d) {
    //method_1: using temp arr
    // int temp[size], k=0;
    // for(int i=d;i<size;i++) {
    //     temp[k++] = arr[i]; 
    // }
    // for(int i=0; i<d;i++){
    //     temp[k++] = arr[i];
    // }
    // for(int i=0; i<size;i++){
    //     arr[i] = temp[i];
    // }
    
    //method_2: using ele shifting...
    // int k=0;
    // while(k<d) {
    //     int temp = arr[0];
    //     for(int i=0;i<size-1;i++){
    //         arr[i] = arr[i+1];
    //     }
    //     arr[size-1]=temp;
    //     k++;
    // }
    
    //Method_3: Jugling alogo... O(n) O(1)
    // d= d%size;
    // cout<<"d: "<<d<<endl;
    // int gcd= find_gcd(d,size);
    // cout<<"gcd: "<<gcd<<endl;
    // for(int i=0; i<gcd; i++) {
    //     int temp = arr[i];
    //     int j=i;
    //     while(1){
    //         int k= j+d;
    //         if(k >= size)
    //         k= k-size;
    //         if(k==i)
    //         break;
    //         arr[j]=arr[k];
    //         j=k;
    //     }
    //     arr[j]=temp;
    // }
    
    //Method_4: using reversal logic:  O(n) O(1)
    // d=d%size;
    // reverse_arr(arr, 0, d-1);
    // reverse_arr(arr, d, size-1);
    // reverse_arr(arr, 0, size-1);
    
    //Method_5: Block Swap:
    int i,j;
    if(d==0 || d==size)
    return;
    if(d> size)
    d=d%size;
    
    i=d;   //Block A start index.
    j=size-d;  // Block B start index.
    
    while(i!=j) {
        
        if(i < j) {   //A Block is smaller
            
            swap_transverse(arr, d-i,(d-i)+j,i);
            j=j-i;
        } else {   //A is bigger block.
            swap_transverse(arr, d-i, d, j);
            i=i-j;
        } 
    }
    
    //Final block swapping A and B.
    swap_transverse(arr, d-i, d, i);
    
}

int find_gcd(int a, int b) {
    if(b==0) {
        return a;
    } else {
        return find_gcd(b, a%b);
    }
}

void reverse_arr(int arr[], int start, int end) {
    int mid = (start+end)/2;
    for(int i=start; i<=mid; i++) {
        int temp= arr[i];
        arr[i]=arr[end-i+start];
        arr[end-i+start]=temp;
    }
}

void swap_transverse(int arr[], int fi, int si, int d) {
    int temp;
    for(int i=0;i<d;i++) {
        temp = arr[fi+i];
        arr[fi+i]=arr[si+i];
        arr[si+i]=temp;
    }
    cout<<endl;
    printArray(arr,7);
    cout<<endl;
}

//using the continous swapping method for forward shifting !!
void cyclicRoate(int arr[], int size) {
    int i=0,j = size-1;
    while (i!=j) {
        int temp;
        temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
    }
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int size = sizeof(arr)/sizeof(int);
    int d= 2;
    //rotate(arr, size, d);
    cyclicRoate(arr,size);
    printArray(arr, size);
    return 0;
}
