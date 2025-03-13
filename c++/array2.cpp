/*
Given an integer array nums, move all 0s to the end of it while maintaining the relative order of the non-zero elements.
You must do this without making copy fo the elements
*/
/*
taking array of elements [0,3,4,0,9,0]
Two tracker approach -
take two pointers i and j
- i scans every element in the array
- j marks the position where the next zero will be placed

i - 0 to n-1
i=0
a[i]=0, do nothing move i
i=1, j=0
a[i]=3, put a[j]=a[i], a[0]=3, j+=1
[3,0,4,0,9,0]
i=2, j=1
a[i]=4, put a[j]=a[i], a[1]=4, j+=1
[3,4,4,0,9,0]
i=3, j=2
a[i]=0, do nothing i+=1
i=4, j=2
a[i]=9, a[j]=a[i], a[2]=9, j+=1
[3,4,9,0,0,0]
i=5, j=3
a[i]=0, do nothing, i+=1
i=6, j=3
a[i]=0, do nothing, i+=1
-->out of loop
now for all elements from j=3, initialize with zero because if we had [0,3,4,0,0,0] as array
we would have ended up with [3,4,4,0,0,0] and j would have been 2. so we need this cleanup step

*/

#include <iostream>
#include <stdio.h>

using namespace std;

void move_zero_to_end(int* arr,int n){

    int i,j=0;
    for(i=0;i<n;i++){
        if(arr[i]!=0){
            arr[j]=arr[i];
            j+=1;
        }
    }

    while(j<n){
        arr[j]=0;
        j+=1;
    }

}

int main(){

    int arr[100], n,i=0;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"\n Enter the elements of the array: ";
    for(i=0;i<n;i++){
        cin>>arr[i];
        cout<<" ";
    }
    //needn't return explicitly when u pass array to function it is passed by reference
    move_zero_to_end(arr,n);
    for(i=0;i<n;i++){
        cout<<(arr[i]);
        cout<<" ";
        
    }
    return 0;
}



