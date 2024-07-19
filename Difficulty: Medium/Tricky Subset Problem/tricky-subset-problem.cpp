//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isPossible(long long S, long long N, long long X, long long A[])
    {
        // code here
        typedef long long ll;
        
        ll pre = S;
        
        vector<ll> temp;
        
        
        temp.push_back(pre);
        
        
        for(int i = 0;i<N;i++){
            ll curr = pre + A[i];
            
            temp.push_back(curr);
            
            pre = pre + curr;
            
            if(pre>=X){
                break;
            }
        }
        
        for(int i = temp.size()-1;i>=0;i--){
            if(temp[i]<=X){
                X -= temp[i];
            }
        }
        
        return X==0LL;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long S, N, X;
        cin>>S>>N>>X;
        long long A[N];
        for(long long i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        if(ob.isPossible(S, N, X, A))
            cout<<"yes\n";
        else
            cout<<"no\n";
    }
    return 0;
}
// } Driver Code Ends