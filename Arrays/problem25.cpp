//Amount of Rain collected between the blocks

/* LOGIC BUILDING:

3 0 0 2 0 4

leftMax = [3 3 3 3 3 4]

rightMax = [4 4 4 4 4 4]

water = [0 3 3 1 3 0] = add -> 10.

we need 2 arrs:   O(n) O(n)

leftMax =  max_till_a[i-1] or a[i] if a[i] > max_till_a[i-1]

RightMax = max_till_a[i+1] or a[i] if a[i] > max_till_a[i+1]

water_collected_at_i = min(leftMAx_at_i, rightMax_at_i) - arr[i]


O(1) space solution:  (*very important !! very nice solution*)

check id ptr1 < ptr2 --> compare with the left max 
				if more update the left max
				else cal the water.
else compare with the right max 
				if more than update the right Max
				else cal the water.

2 4 0 5 2 6 1 3
          =      Exited since ptr1= ptr2.

leftMax = 0 --> 2  --> 4 ---> 5

rightMax = 0 --> 3

water_collected = 2 + 4 + 3  = 9.

*/


//algo function:

long long trappingWater(int arr[], int n){
        // code here
        
        //This is first Solution with space O(n)
        //leftMaxArr --> stores the max element from left side of i.
        //rightMaxArr --> stores the max element from right side of i.
        
        // int leftMaxArr[n], rightMaxArr[n];
        
        // int leftMax = INT_MIN;
        // for(int i=0;i<n;i++) {
        //     if(arr[i] >= leftMax) {
        //         leftMax = arr[i];
        //     }
        // leftMaxArr[i] = leftMax;
        // }
        
        // int rightMax = INT_MIN;
        // for(int i=n-1;i>=0;i--) {
        //     if(arr[i] >= rightMax) rightMax = arr[i];
        //     rightMaxArr[i] = rightMax;
        // }
        
        // long long water_collect = 0;
        // for(int i=0;i<n;i++) {
        //     water_collect += min(leftMaxArr[i], rightMaxArr[i]) - arr[i];
        // }
        
        // return water_collect;
        
        //Optimised solution --> with space O(1).
        //two pointer and conditions...
        
        int leftMostMax = 0, rightMostMax = 0;
        int left=0,right=n-1;
        long long water_collected = 0;
        while(left!=right) {
            if(arr[left] < arr[right]) {
                //then we will perform comparison with the leftMostMax.
                if(arr[left] > leftMostMax) leftMostMax = arr[left];
                else water_collected += leftMostMax - arr[left];
                left++;
            }else {
                //then we will perform comparison with the rightMostMax.
                if(arr[right] > rightMostMax) rightMostMax = arr[right];
                else water_collected += rightMostMax - arr[right];
                right--;
            }
        }
       return water_collected; 
    }

