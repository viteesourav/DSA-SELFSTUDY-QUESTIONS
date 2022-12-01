//Range Intersection Problem: Max no of Platforms required 


/*                          Logic Building

   9:00 9:10 9:40 9:50 11:00 11:20 11:30 12:00 15:00 18:00 19:00 20:00

P1  A1    D1  A2                           D2    A5          D5          
P2                 A3          D3                       A6         D6  
P3                       A4          D4                                     


logic:

1 -> find a complete time line of the trains. merge both the arr and sort it.
2 ->  platform will assume a stack.
 --> arrival means push in the stack, dep means pop out of the stack.

stack -> 
maxTop = 3;


//approach:
//This is an example of range intersection problem.(**very important**)
we know the time will be max of 0000 to 2359.

lets take a range 2 more than that. and implement the logic of range intersection.

so lets takes a array with this ranage.
timeLine[2361] = {0}.

now iterate over the arrival time and dept time.
 --> for arrvial time, increment that place in timeLine by 1.
 --> for dept time, decrement the place followed by that time by 1. *imp*

*imp--> it's the logic of range intersection problem.
basically on this if you take the prefix sum, like how we are doing below,
you will get no of intersecting of ranges for that point. 

--> for maxPlatform,
loop through timeLine,
 -- calculate the prefix sum for all.
End

loop through timeLine,
-- and find the max prefixSum value.
end

*/

Running algo:

int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	//we will solve this using the range intersection logic
    	//time ranges from 0000 to 2359, we will take range 0 to 2360
    	int platform[2361] = {0};  //initialise all with zeros
    	for(int i=0;i<n;i++) {
    	    //incrementing for every arrival...
    	    platform[arr[i]]++;
    	    //decrementing for every departure...
    	    platform[dep[i]+1]--; //note decrement the immediate next postion.
    	}
    	
    	//now take the PrefixSum of the entire array..
    	for(int i=1;i<2361;i++){
    	    platform[i] += platform[i-1];
    	}
    	
    	//now find the max prefix-sum
    	int maxPlatform = platform[0];
    	for(int i=0;i<2361;i++) {
    	    maxPlatform = max(maxPlatform, platform[i]);
    	}
    	return maxPlatform;
    }