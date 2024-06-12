//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    long long gcd(long long A, long long B){
        while(A>0 && B>0){
            if(A>B){
                A = A%B;
            }
            else{
                B = B%A;
            }
        }
        
        if(A==0){
            return B;
        }
        
        return A;
    }
    long long lcm(long long A,long long B){
        return (A*B)/gcd(A,B);
    }
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        
        return {lcm(A,B),gcd(A,B)};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends