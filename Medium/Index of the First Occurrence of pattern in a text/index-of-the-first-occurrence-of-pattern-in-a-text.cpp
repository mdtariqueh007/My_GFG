//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    private:
    vector<int> LPS(string&s){
        int n = s.length();
        
        vector<int> lps(n,0);
        
        int len = 0;
        
        int i = 1;
        
        while(i<n){
            if(s[i]==s[len]){
                len++;
                lps[i] = len;
                i++;
            }else{
                if(len!=0){
                    len = lps[len-1];
                }else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        return lps;
    }
  public:
    int findMatching(string text, string pat) {
        // Code here
        
        int m = pat.size();
        
        string str = pat + "#" + text;
        
        vector<int> lps = LPS(str);
        
        for(int i = 0;i<lps.size();i++){
            if(lps[i]==m){
                return (i-m-m);
            }
        }
        
        return -1;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string text, pat;
        cin >> text >> pat;
        Solution obj;
        cout << obj.findMatching(text, pat) << endl;
    }
    return 0;
}
// } Driver Code Ends