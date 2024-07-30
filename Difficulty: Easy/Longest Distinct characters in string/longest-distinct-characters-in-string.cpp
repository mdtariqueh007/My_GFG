//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    // your code here
    unordered_set<char> st;
    
    int left = 0;
    
    int ans = 0;
    
    for(int i = 0;i<S.length();i++){
        
        while(st.find(S[i])!=st.end()){
            st.erase(S[left]);
            left++;
        }
        st.insert(S[i]);
        
        ans = max(ans, i - left + 1);
        
    }
    
    return ans;
}