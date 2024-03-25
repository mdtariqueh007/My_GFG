//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
    private:
    void f(int n,int one,int zero,string s,vector<string>&ans){
        if(n==0){
            ans.push_back(s);
            return;
        }
        
        f(n - 1,one + 1,zero,s + "1",ans);
        
        if(one>zero){
            f(n - 1,one,zero + 1,s+"0",ans);
        }
        
        
    }
public:	
	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string> ans;
	    
	    f(n,0,0,"",ans);
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends