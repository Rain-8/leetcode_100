/*
You are given an array of prices where prices[i] is the price of a given stock on the ith day. 
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future
to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit
return 0
*/

/*
Take some random ith day.
You have to choose to things - day to buy stock, day to sell stock
such than you maximize(profit)
Profit = Sell price - Cost Price

Intuition -
- For each day you keep track of minimum price so far
- Then as you move forward you check the profit you can make if you sell today, 
  based on your minimum price
- If this profit you find is > previous max profit then you update max profit
- You need to buy first and then sell

Example -

let prices be - prices = [8, 3, 6, 2, 1, 1, 1]
Day 0:
min_price=8, nothing to do, i+=1
Day 1:
3<8 => it is definitely better to buy today then yesterday
so new min_price=3
Day 2:
6>3, no change in nim price of purchase
find profit if you sell today = 6-3=3
so max_profit =3
Day 3:
2<3, so it is better to buy today than at 3
new min_price=2
profit 2-1=1
no update to max_profit
Day 4:
1<2, better to buy today than at 2
profit = 1-1=0
no update to max_profit
Day 5:
same as day 4
Day 6:
Same as Day 4

Conclusion - Buy at Day 1 at 3 sell at Day 2 at 6 to get max_profit =3


*/

#include <iostream>
#include <stdio.h>

using namespace std;

int find_max_profit(int arr[], int n){
    int min_price=arr[0];
    int max_profit=0, i, profit;
    for(i=1;i<n;i++){
        if(arr[i]<min_price){
            min_price=arr[i];
        }
        else{
            profit=arr[i]-min_price;
            if(profit>max_profit){
                max_profit=profit;
            }
        }
        
    }

    return max_profit;
}

int main(){

    int arr[100], n, i;
    cout<<"Enter size of array: ";
    cin>>n;
    cout<<"\nEnter elements of array: ";
    for(i=0;i<n;i++){
        cin>>arr[i];
        cout<<" ";
    }
    cout<<"\nMaximum profit :"<<find_max_profit(arr,n);

}