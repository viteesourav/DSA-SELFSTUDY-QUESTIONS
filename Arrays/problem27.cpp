//Max Product subarray

/*
                     LOGIC BUILDING

6 -3 -10 0 2


ALGO:

*maintain two counter --> minVal and maxVal,
* if a negative number comes sawp the above two.
* check what is the maxVal and minVal now.

maxVal = max(arr[i], maxVal*arr[i]);
minVal = min(arr[i], minVal*arr[i]);

* check if the maxVal is more than the 
existing product array.
*return productArr.

*/

//Algo:

long long maxProduct(vector<int> arr, int n) {
	    // code here
	    //we will take 2 variables to keep track of the max and min Product.
	    //NOTE: When a neg comes, max becomes min and min become max.
	    //update them accordingly and take the maxProduct and return it.
	    long long maxProdVal = arr[0], minProdVal = arr[0], maxProd = arr[0];
	    
	    for(int i=1;i<n;i++) {
	        
	        //if arr[i] < 0 swap min and max.
	        if(arr[i] < 0)
	        swap(maxProdVal, minProdVal);
	        
	        //updating the max and min.
	        maxProdVal = max((long long)arr[i], maxProdVal*arr[i]);
	        minProdVal = min((long long)arr[i], minProdVal*arr[i]);
	        
	        //taking the maxProd out of maxProdVal
	        maxProd = max(maxProd, maxProdVal);
	    }
	    return maxProd;
	}