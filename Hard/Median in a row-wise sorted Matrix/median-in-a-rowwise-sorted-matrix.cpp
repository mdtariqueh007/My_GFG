//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{ 
    private:
    int cntSmallerEqual(vector<vector<int>>&mat,int mid){
        int cnt = 0;
        
        for(int i = 0;i<mat.size();i++){
            cnt += upper_bound(mat[i].begin(),mat[i].end(),mid) - mat[i].begin();
        }
        
        return cnt;
    }
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here   
        
        int low = INT_MAX, high = INT_MIN;
        
        for(int i = 0;i<R;i++){
            low = min(low,matrix[i][0]);
            high = max(high,matrix[i][C-1]);
        }
        
        int req = (R*C)/2;
        
        while(low<=high){
            int mid = low + (high -low)/2;
            
            int cnt = cntSmallerEqual(matrix,mid);
            
            if(cnt<=req){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends