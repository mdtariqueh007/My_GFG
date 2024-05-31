//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	long long int findBitwiseOR(long long int L, long long int R){
while(L < R) {
            L |= (L + 1);
        }return L; 
	
	}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        long long L, R;
        cin >> L >> R;
        Solution ob;
        cout << ob.findBitwiseOR(L, R) << endl;
    }
    return 0;
}


// } Driver Code Ends