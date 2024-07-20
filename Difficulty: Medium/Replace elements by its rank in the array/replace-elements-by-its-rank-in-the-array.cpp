//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        
        
        vector<int> temp = arr;
        
        sort(temp.begin(),temp.end());
        
        int rank = 1;
        unordered_map<int,int> mp;
        for(int x : temp){
            if(mp.find(x)==mp.end()){
                mp[x] = rank++;
            }
        }
        
        vector<int> ans;
        
        for(int x : arr){
            ans.push_back(mp[x]);
        }
        
        return ans;


    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends