//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<long long> jugglerSequence(long long n) {
        // code here
        vector<long long> ans;
        
        long long a = n;
        ans.push_back(a);
        while(a!=1){
            long long b = 0;
            if(a%2==0){
                b = floor(sqrt(a));
            }else{
                
                b = floor(sqrt(a)*sqrt(a)*sqrt(a));
            }
            
            ans.push_back(b);
            
            a = b;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        Solution ob;
        vector<long long> ans = ob.jugglerSequence(n);
        for (long long u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends