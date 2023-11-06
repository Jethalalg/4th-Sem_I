#include<iostream>

using namespace std;

int main(){
    int capacity = 10;
    int items = 4;
    int price[items + 1] = {0, 3, 7, 2, 9};
    int wt[items + 1] = {0, 2, 2, 4, 5};
    int dp[items + 1][capacity + 1];
    
    for(int i = 0; i <= items; i++){
        for(int j = 0; j <= capacity; j++){
            if(i == 0 || j == 0){
                //There's nothing to add to Knapsack
                dp[i][j] = 0;
            }
            else if(wt[i] <= j){
                //Choose previously maximum or value of current item + value of remaining weight
                dp[i][j] = max(dp[i - 1][j], price[i] + dp[i - 1][j - wt[i]]);
            }
            else{
                //Add previously added item to knapsack
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
	

    cout << "Maximum Profit Earned: " << dp[items][capacity] << "\n";
    return 0;
}

/*
0/1 Knapsack :
Time Complexity: O(N*W). 
where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
Auxiliary Space: O(N*W). 
The use of 2-D array of size ‘N*W’.
*/



/*
This code is an implementation of the 0/1 Knapsack problem using dynamic programming. The problem is about selecting items with weights and values to maximize the total value within a given capacity. Let's go through the code step by step:

1. `int capacity = 10;`
   - This line sets the maximum capacity of the knapsack to 10 units.

2. `int items = 4;`
   - This line sets the number of items available to 4.

3. `int price[items + 1] = {0, 3, 7, 2, 9};`
   - This array `price` represents the values of the items. The first element (0) is set to 0 for simplicity. The values of the items are {3, 7, 2, 9}.

4. `int wt[items + 1] = {0, 2, 2, 4, 5};`
   - This array `wt` represents the weights of the items. The first element (0) is set to 0 for simplicity. The weights of the items are {2, 2, 4, 5}.

5. `int dp[items + 1][capacity + 1];`
   - This is a 2D array `dp` used for dynamic programming. It has `items + 1` rows and `capacity + 1` columns. It will be used to store the maximum value that can be obtained with different combinations of items and capacities.

6. Nested `for` loops:
   - The code enters into a nested `for` loop to fill the `dp` array.

7. `if(i == 0 || j == 0){`
   - This condition checks if we are at the first row (i=0) or the first column (j=0) of the `dp` array. If so, it sets the value to 0 because there's no item to add or no capacity to use.

8. `else if(wt[i] <= j){`
   - This condition checks if the weight of the current item (represented by `wt[i]`) is less than or equal to the current capacity (represented by `j`). If this is true, it means we can consider adding the current item to the knapsack.

9. `dp[i][j] = max(dp[i - 1][j], price[i] + dp[i - 1][j - wt[i]]);`
   - If we can add the item, this line calculates the maximum value that can be obtained either by not adding the current item (`dp[i - 1][j]`) or by adding the current item (`price[i]`) and then considering the remaining capacity (`j - wt[i]`) and items from the previous row (`dp[i - 1][j - wt[i]]`).

10. `else{`
    - If the weight of the current item is greater than the current capacity, it means we can't add the item, so we simply copy the value from the row above to the current cell.

11. The `for` loops continue until the `dp` array is filled with the maximum values that can be obtained for different combinations of items and capacities.

12. `cout << "Maximum Profit Earned: " << dp[items][capacity] << "\n";`
    - Finally, the code prints the maximum profit that can be earned with the given items and capacity. This is found in the cell `dp[items][capacity]`.

In summary, this code uses dynamic programming to find the maximum value that can be obtained by selecting items to put in a knapsack with a given capacity while considering their weights and values. The result is stored in the `dp` array and printed at the end of the code.
*/