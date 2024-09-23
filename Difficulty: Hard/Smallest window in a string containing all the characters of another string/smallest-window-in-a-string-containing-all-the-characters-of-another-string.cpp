//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string t)
    {
        // Your code here
        
        
        int n = s.length();

        if(t.length() > n){
            return "-1";
        }

        vector<int> mp(256,0);

        for(char ch :  t){
            mp[ch]++;
        }

        int requiredCount = t.length();

        int minWindowSize = INT_MAX;
        int startInd = 0;

        int i = 0;

        for(int j = 0;j<n;j++){

            char ch = s[j];

            if(mp[ch]>0){
                requiredCount--;
            }

            mp[ch]--;

            while(requiredCount==0){
                int currWindowSize = j - i + 1;

                if(currWindowSize<minWindowSize){
                    minWindowSize = currWindowSize;
                    startInd = i;
                }

                mp[s[i]]++;

                if(mp[s[i]]>0){
                    requiredCount++;
                }

                i++;
            }
        }
        
        
        if(minWindowSize>=INT_MAX){
            return "-1";
        }
        else{
            return s.substr(startInd,minWindowSize);
        }
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends