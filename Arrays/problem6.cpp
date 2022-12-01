//concept of OFP(out of position) arranging the numbers positive and negative alternatively

#include <iostream>

using namespace std;

void printarr(int arr[], int n) {
    int i=0;
    while(i < n) {
        cout<<arr[i]<<" ";
        i++;
    }
    cout<<endl;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a=*b;
    *b=temp;
}

void rightRotateArr(int a[], int s, int n) {
    int temp = a[n];
    int count = n;
    while(count > s) {
        a[count]=a[count-1];
        count--;
    }
    a[s]=temp;
}

//method1: using the swap tech (order not followed)
void unorderedArrangment_method1(int arr[], int n){
    int j=-1; //keep track of my negative no.
    for(int i=0;i<n;i++) {
        if(arr[i] < 0) {
            j++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    //now you have the position for Positive and negative number..
    int pos = j+1;
    int neg = 0;
    while(neg < pos && pos > neg && arr[neg] < 0) {
        swap(&arr[neg], &arr[pos]);
        neg+=2;
        pos++;
    }
}

//method2: using the logic of outofPostion. --> Order Maintained.
void unorderedArrangment_method2(int a[], int n) {
    //outofPostion: +ve number at even and -ve number at odd.
    int OFP = -1; //initally we dont know which one is OFP.
    
    for(int i=0;i<n;i++) {
        
        //if we have OFP..
        if(OFP >= 0) {
            
            //we need to find the next number with the opposite sign of that value at OFP..
            if((a[OFP] >= 0 && a[i] < 0) || (a[OFP] < 0 && a[i] >= 0)) {
                rightRotateArr(a, OFP, i);
                
                //after right rotate perfoem this..
                if(i-OFP >= 2)
                OFP+= 2;
                else 
                OFP = -1;
            }
            
        }
        
        //if we dont have OFP..
        if(OFP==-1) {
            if(((a[i] >= 0) && (i%2 == 0)) || ((a[i] < 0) && (i%2 != 0)))
            OFP=i;
        }
    }
}

//FAR Better that out of postition concept....

//method_3: i will first try to split the array in negative and Positive by maintaining the order...
// for this this instead of using swap, i will use rightRotateArr...
void unorderedArrangment_mymethod(int a[], int n){
    int neg = -1; //keep track of the negatives side...
    
    for(int i=0; i < n-1; i++) {
        
        if(a[i] >= 0 && a[i+1] < 0) {
            if(neg != -1) {
                rightRotateArr(a, neg+1, i+1);
                neg++;
            }else {
                neg = i+1;
            }
        } else if(a[i] <0 && a[i+1] > 0) {
            if(neg != -1) {
                rightRotateArr(a, neg+1, i);
                neg++;
            }else {
                neg = i;
            }
        }
    }
    
    //After this we have one half negative and one half positive...
    int pos = neg+1;
    neg = 0;
    while(pos > neg && neg < pos && a[neg] < 0) {
        swap(&a[neg], &a[pos]);
        neg+=2;
        pos++;
    }
}

int main()
{
    int a[] = {-5, -2, 5, 2, 4, -7, 1, 8, 0, -8 };
    int n= sizeof(a)/sizeof(a[0]);
    //unorderedArrangment_method1(a, n);
    //unorderedArrangment_method2(a, n);
    unorderedArrangment_mymethod(a, n);
    printarr(a, n);
    return 0;
}
