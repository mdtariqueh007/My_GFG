//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        if(prices.size()==1) return 0;
        int profit = prices[1] - prices[0];
        int minVal = prices[0];
        for(int i = 1;i<prices.size();i++){
            profit = max(profit,prices[i]-minVal);
            minVal = min(minVal,prices[i]);
        }

        if(profit<0) return 0;
        return profit;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> prices;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            prices.push_back(number);
        }

        Solution ob;
        int ans = ob.maximumProfit(prices);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends