//small demo on how pointers works

#include <iostream>

using namespace std;

void incre(int* a) {
    cout<<"Before increment: "<<*a<<" "<<a<<endl;
    //This is wrong way. it will not increment a by 1.
    //*a++;
    //Right way...
    *a= *a+1;
    cout<<"After increment: "<<*a<<" "<<a<<endl;
}

int main()
{
    cout<<"Checking the pointers"<<endl;
    
    
    //This is get clarifaiction on how exactly we need to pass address to a function.
    //catch it using pointer and how to increment the pointer by 1
    
    int a=5;
    
    int *p = &a;
    
    cout<<a<<" "<<p<<endl;
    
    incre(&a);
    
    cout<<a<<" "<<&a<<endl;

    return 0;
}
