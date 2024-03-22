//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> Series(int n) {
        // Code here
        vector<int> fib(n+1,0);
        fib[1] = 1;
        
        const int mod = 1e9 + 7;
        
        for(int i = 2;i<=n;i++){
            fib[i] = (fib[i-1]%mod + fib[i-2]%mod)%mod;
        }
        
        return fib;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends