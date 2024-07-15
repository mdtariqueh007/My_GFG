//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        
        if(s>9*d){
            return "-1";
        }
        
        vector<int> ans(d);
        
        s -= 1;
        
        for(int i = d-1;i>0;i--){
            if(s>9){
                ans[i] = 9;
                s -= 9;
            }
            else{
                ans[i] = s;
                s = 0;
            }
        }
        
        ans[0] = s + 1;
        
        string res = "";
        
        for(int x  :ans){
            res += to_string(x);
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends