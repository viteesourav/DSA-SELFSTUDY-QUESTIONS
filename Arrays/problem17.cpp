//Min no of jumps required to reach the end of the array

#include <bits/stdc++.h>

using namespace std;

//best solution...O(n).

int minJumps(int arr[], int n) {
    
    //check the boundary conditions..
    if(n <= 1) return 0; //only one element no jump needed.
    else if(arr[0] == 0) return -1; //can't move ahead if first element is zero.
    
    int stepsCount = arr[0];
    int maxJumpPostn = arr[0];
    int jump = 1;
    
    int i =1;
    
    while(i<= n-1) {
        
        if(i==n-1) return jump;
        maxJumpPostn = max(maxJumpPostn, i+arr[i]);
        stepsCount--;
        
        if(stepsCount == 0) {
            jump++;
            if(maxJumpPostn == i) return -1; //you landed on a 0. can't move ahead.
            stepsCount = maxJumpPostn-i;
        }
        i++;
    }
    
    return -1;
}
 
int main()
{
    //Find the min no of jumps required to reach the end.
    int arr[] = {2, 3, 1, 1, 2, 4, 2, 0, 1, 1};
    int n= sizeof(arr)/sizeof(arr[0]);
    
    int out = minJumps(arr, n);
    
    cout<<out<<endl;

    return 0;
}
