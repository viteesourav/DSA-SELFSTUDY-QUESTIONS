//Arrange all zeros to first or end of an array

#include <iostream>
#include<unordered_set>

using namespace std;

void printarray(int arr[], int size) {
    for(int i=0; i<size;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void rightRotateArray(int arr[], int start, int end) {
    int temp = arr[end];
    int counter = end;
    while(counter>start) {
        arr[counter] = arr[counter-1];
        counter--;
    }
    arr[start] = temp;
}

void arrangeAllZerosToFirst(int arr[], int size) {
    
    //first lets check the boundary condiiton --> if all are zeros or there is no zeros
    int count =0;
    for(int i=0; i<size; i++) {
        if(arr[i]==0)
        count++;
    }
    
    if(count == 0 || count==size) {
        cout<<"The Array needs no Arrangment"<<endl;
    }else {
        int i=0,j=1;
        while(j<size) {
            if(arr[j]==0) {
                rightRotateArray(arr,i,j);
                i++;
            }
            j++;
        }
    }
}

void arrangeByIndexPostn(int arr[], int size) {
    
    //method1: using set
    
    // unordered_set<int> s;
    
    // for(int i=0; i< size; i++)
    // s.insert(arr[i]);
    
    // for(int i=0;i<size; i++) {
        
    //     if(s.find(i) != s.end()) {
    //         arr[i]=i;
    //     }else {
    //         arr[i]=-1;
    //     }
    // }
    
    //method 2: using exchange logic: S(1)
    
    for(int i=0;i<size; i++) {
        
        if(arr[i] != -1 && arr[i]!=i) {
            
            int x = arr[i];  //got the value of ele at i position.
            
            //this will make sure both at x and its element have the right value.
            while(arr[x] != -1 && arr[x] != x && x<size) {   //while because utill x is proper...
                
                int y = arr[x];  //temp storing the ele value at x postion.
                
                arr[x] = x;
                
                x=y;
            }
            
            arr[x] = x;  //putting the prooer value at x position.
            
            //end-condition if the above while loop didn't set any thing for ith position then set it to -1.
            if(arr[i] != i)
            arr[i] = -1;
        }
    }
}

void leftRotateArray(int arr[],int start, int end) {
    int temp = arr[start], counter = start;
    while(counter < end) {
        arr[counter] = arr[counter+1];
        counter++;
    }
    arr[end]=temp;
}

void arrangeAllZerosToEnd(int arr[], int size) {
    
    //boundary condition for this
    int count = 0;
    for(int i=0;i<size; i++) {
        if(arr[i] == 0)
        count++;
    }
    
    if(count == 0 || count == size) {
        cout<< "No arrangement needed";
    }else {
        int i = size-1, j= i-1;
        while(j>=0) {
            if(arr[j]==0){
                leftRotateArray(arr, j, i);
                i--;
            }
            j--;
        }
        
    }
}


int main()
{
    int arr[] = { -1, -1, 6, 1, 9,
               3, 2, -1, 4, -1 };
    int size = sizeof(arr)/sizeof(int);
    // arrangeAllZerosToFirst(arr, size);
    //arrangeByIndexPostn(arr, size);
    //arrangeAllZerosToEnd(arr, size);
    printarray(arr,size);
    return 0;
}
