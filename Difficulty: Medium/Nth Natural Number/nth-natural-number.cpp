//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long findNth(long long n) {
        // code here.
        vector<int> ans;
        long long d=0;
        while(n!=0)
         {
             int f;
             f=n%9;
             ans.insert(ans.begin(),f);
             n=n/9;
         }
         for(int i=0;i<ans.size();i++)
         {
             d=d*10+ans[i];
         }
         return d;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, ans;
        cin >> n;
        Solution obj;
        ans = obj.findNth(n);
        cout << ans << endl;
    }
}

// } Driver Code Ends