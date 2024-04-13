//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long x) {
        // code here
        
        string s = "";
        
        for(int i = 0;i<32;i++){
            if(x & (1<<i)){
                s = s + '1';
            }else{
                s = s + '0';
            }
        }
        
        long long ans = 0;
        
        for(int i = 0;i<32;i++){
            if(s[i]=='1'){
                ans += pow(2,31-i);
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends