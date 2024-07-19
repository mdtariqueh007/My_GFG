//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n) {
        // Your code here
        
        vector<pair<int,int>> temp;
        
        for(int i = 0;i<n;i++){
            temp.push_back({arr[i].value,arr[i].weight});
        }
        
        sort(temp.begin(),temp.end(),[&](pair<int,int>a,pair<int,int>b){
            double val1 = a.first*1.0/a.second*1.0;
            double val2 = b.first*1.0/b.second*1.0;
            
            return val1>val2;
        });
        
        
        int curr = 0;
        double profit = 0;
        
        for(int i = 0;i<n;i++){
            if(curr + temp[i].second<=W){
                profit += temp[i].first;
                curr += temp[i].second;
                
            }
            else{
                profit += ((temp[i].first*1.0)/(temp[i].second*1.0)) * (W - curr)*1.0;
                break;
            }
        }
        
        return profit;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(6) << fixed;
    while (t--) {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++) {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends