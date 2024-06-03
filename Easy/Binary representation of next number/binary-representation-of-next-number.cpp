//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        int n = s.length();
        int carry = 1;
        
        string ans = "";
        
        for(int i = n - 1;i>=0;i--){
            if((s[i]=='1' && carry==0) || (s[i]=='0' && carry==1)){
                ans += "1";
                carry = 0;
            }else if((s[i]=='1' && carry==1) || (s[i]=='0' && carry==0)){
                ans += "0";
            }
        }
        
        if(carry){
            ans += "1";
        }
        
        reverse(ans.begin(),ans.end());
        
        if(ans.find('1')!=string::npos){
            ans = ans.substr(ans.find('1'));
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends