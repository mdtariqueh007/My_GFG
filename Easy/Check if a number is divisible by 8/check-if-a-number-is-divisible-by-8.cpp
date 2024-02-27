//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int DivisibleByEight(string s){
        //code here
        int n = s.length();
        
        string temp = "";
        int i = n - 1;
        int cnt = 3;
        while(i>=0 && cnt--){
            temp = s[i] + temp;
            i--;
        }
        
        int num = 0;
        
        num = num*10 + (temp[0]-'0');
        if(temp.size()>=2)num = num*10 + (temp[1]-'0');
        if(temp.size()==3)num = num*10 + (temp[2]-'0');
        
        if(num%8==0){
            return 1;
        }
        else{
            return -1;
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
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.DivisibleByEight(S)<<"\n";
    }
}
// } Driver Code Ends