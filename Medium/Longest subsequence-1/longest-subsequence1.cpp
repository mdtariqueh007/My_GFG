//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
    private:
    int helper(int ind,vector<int>&arr,int last){
        if(ind==arr.size()){
            return 0;
        }
        
        int take = 0;
        int notTake = helper(ind+1,arr,last);
        
        if(abs(last-arr[ind])==1 || last==-1){
            take = 1 + helper(ind + 1,arr,arr[ind]);
        }
        return max(take,notTake);
    }
  public:
    int longestSubseq(int n, vector<int> &a) {
        // code here
        
        return helper(0,a,-1);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> a(n);
        Array::input(a, n);

        Solution obj;
        int res = obj.longestSubseq(n, a);

        cout << res << endl;
    }
}

// } Driver Code Ends