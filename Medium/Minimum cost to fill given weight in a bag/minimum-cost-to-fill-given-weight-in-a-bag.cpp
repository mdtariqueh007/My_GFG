//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
    private:
    int dp[201][201];
    int helper(int ind,vector<int>&cost,int w){
        if(w==0){
            return 0;
        }
        
        if(dp[ind][w]!=-1){
            return dp[ind][w];
        }
        
        if(ind>=cost.size() || ind+1>w){
            return 1e9;
        }
        
        int pick = 1e9, notPick = 1e9;
        
        if(cost[ind]!=-1 && (ind+1)<=w){
            pick = cost[ind] + helper(ind,cost,w-ind-1);
        }
        
        notPick = helper(ind+1,cost,w);
        
        return dp[ind][w] = min(pick,notPick);
        
    }
  public:
    int minimumCost(int n, int w, vector<int> &cost) {
        // code here
        
        memset(dp,-1,sizeof(dp));
        
        return helper(0,cost,w);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends