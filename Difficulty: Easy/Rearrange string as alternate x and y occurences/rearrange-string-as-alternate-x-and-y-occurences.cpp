//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
  public:
    string arrangeString(string str, int x, int y)
    {
        //code here.
        int cnt0 = 0;
        int cnt1 = 0;
        
        for(char c : str){
            if(c=='1'){
                cnt1++;
            }
            else{
                cnt0++;
            }
        }
        
        string ans = "";
        
        while(cnt0>0 || cnt1>0){
            for(int i =0;i<x && cnt0>0;i++){
                ans += "0";
                cnt0--;
            }
            for(int i = 0;i<y && cnt1>0;i++){
                ans += "1";
                cnt1--;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        int x, y;
        cin >> x >> y;
        string s;
        cin >> s;
        Solution ob;
        cout <<ob.arrangeString(s, x, y) << endl;
    }
return 0;
}


// } Driver Code Ends