//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    vector<int> count(26,0);
	    
	    for(char c : s){
	        count[c-'a']++;
	    }
	    
	    int val = 0;
	    
	    for(int i = 0;i<26;i++){
	        if(count[i]){
	            val++;
	        }
	    }
	    
	    if(s.length()%val>1){
	        return false;
	    }
	    
	    int req = s.length()/val;
	    
	    int relax = 0;
	    
	    for(int i = 0;i<26;i++){
	        if(count[i]){
	            if(count[i]==req){
	                continue;
	            }
	            else if(count[i]==req+1){
	                if(relax){
	                    return false;
	                }
	                else{
	                    relax++;
	                }
	            }else{
	                return false;
	            }
	        }
	    }
	    
	    return true;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends