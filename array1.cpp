/*
Given an int array nums, return an array answer such that answer[i] is equal to product of all the elements
of nums except nums[i]
*/
/*
Initial code 
#include <iostream>

using namespace std;

int product_except_num_ind(int ar[], int l){ - need to use int* for dynamic memory alloc
    int p[100],i,j; - use new for allocating memory dynamically (heap) so that it persits after func ends 
                      and later use delete [] to free it or use vector<int> which automatically manages memory
    
    for(i=0;i<l;i++){
        p[i]=1;
        for(j=0;j<l;j++){   - O(N^2) complexity 
            if(i==j)
                continue;
            else    
                p[i]*=ar[i]; 
        }
    }

    return(p); - cant do this cause arrays in c++ cant be returned directly. 
                 stored in stack memory which gets destroyed once function ends
                 arr p is in func stack memory which gets deleted once func ends so we can no longer return
                 as its not valid memory
}

int main(){

    int i,l,a[100];
    cout<<"Enter number of elements in array";
    cin>>l;
    cout<<"\nEnter the elements of the array :";
    for(i=0;i<l;i++){
        cin>>a[i];
    }
    cout<<product_except_num_ind(a);
}

*/


#include <iostream>

using namespace std;

void product_except_num_ind(int arr[], int res[], int l) {
    if (l == 0) return;  // Handle edge case: empty array

    // Left product array
    int left[l];
    left[0] = 1;  // Leftmost element has no left products
    for (int i = 1; i < l; i++) {
        left[i] = left[i - 1] * arr[i - 1];
    }

    // Right product array
    int right[l];
    right[l - 1] = 1;  // Rightmost element has no right products
    for (int i = l - 2; i >= 0; i--) {
        right[i] = right[i + 1] * arr[i + 1];
    }

    // Compute final result array
    for (int i = 0; i < l; i++) {
        res[i] = left[i] * right[i];
    }
}

int main() {
    int l;
    cout << "Enter number of elements in array: ";
    cin >> l;

    if (l <= 0) {  // Edge case: invalid size
        cout << "Error: Invalid size. Exiting..." << endl;
        return 1;
    }

    int arr[l], res[l];  // Declare fixed-size arrays

    cout << "Enter the elements: ";
    for (int i = 0; i < l; i++) {
        cin >> arr[i];
    }

    // Call function
    product_except_num_ind(arr, res, l);

    // Print result
    cout << "Output array: ";
    for (int i = 0; i < l; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}





