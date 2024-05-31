//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
        
        vector<int> cnt(27,0);
        
        for(char c : s){
            cnt[c-'a'+1]++;
        }
        
        int x = 0, y = 0;
        
        for(int i = 1;i<=26;i++){
            if(!(i&1) && !(cnt[i]&1) && cnt[i]>0){
                x++;
            }
            else if((i&1) && (cnt[i]&1) && cnt[i]>0){
                y++;
            }
        }
        
        return (x+y)&1?"ODD":"EVEN";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends