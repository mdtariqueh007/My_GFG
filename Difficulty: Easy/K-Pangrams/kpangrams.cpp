//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        
        int cntAlphabets = 0;
        vector<int> cnt(26,0);
        
        for(char c : str){
            if(isalpha(c)){
                cnt[c-'a']++;
                cntAlphabets++;
            }
        }
        
        if(cntAlphabets<26) return false;
        
        int req = 0;
        for(int i = 0;i<26;i++){
            if(cnt[i]==0){
                req++;
            }
        }
        
        return req<=k;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends