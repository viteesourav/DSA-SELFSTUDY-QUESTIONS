//binary-sort application: infinite arr, element position

#include<bits/stdc++.h>
using namespace std;

//Do bianrySearch logic
int binarySearch(int arr[], int l, int h, int key) {
    int low=l,high=h;
    while(low<=high) {
        int mid = (low+high)/2;
        
        if(arr[mid]== key){
            return mid;
        }
        
        if(arr[mid] < key) low = mid-1;
        else high = mid+1;
    }
    
    return -1;
}


//Idea: we know the first and second element but we dont know bounds to apply for binary search.
//start with 2nd elem and increase the bound by 2 times untill the key is < that elem that will be higer bound.
int findPostion(int arr[], int key) {
    
    int l=0, h=1, hmaxVal = arr[0];
    
    while(hmaxVal < key) {
        l=h;
        h = 2*h;
        hmaxVal = arr[h];
    }
    
    return binarySearch(arr, l, h, key);
}

int main() {
    
    //Given an infinite sorted array(i.e upper bound unknown or you can assume length you don't know..)
    //Return the position of the key element.
    
    int arr[] = {3,5,7,9,10,90,100,130,140,160,170,200};
    int key = 90;
    
    int keyPostn = findPostion(arr, key);
    cout<<keyPostn<<endl;
    
    return 0;
}