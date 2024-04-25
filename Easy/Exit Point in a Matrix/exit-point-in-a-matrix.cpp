//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        vector<int> ans;
        
        
        queue<pair<int,int>> q;
        q.push({0,0});
        
        int dir = 0;
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            
            q.pop();
            
            int nrow, ncol;
            
            if(matrix[row][col]==1){
                matrix[row][col] = 0;
                if(dir==0){
                    nrow = row + 1;
                    ncol = col;
                    dir = 1;
                }
                else if(dir==1){
                    nrow = row;
                    ncol = col - 1;
                    dir = 2;
                }
                else if(dir==2){
                    nrow = row - 1;
                    ncol = col;
                    dir = 3;
                }
                else if(dir==3){
                    nrow = row;
                    ncol = col + 1;
                    dir = 0;
                }
            }else{
                
                if(dir==0){
                    nrow = row;
                    ncol = col + 1;
                }
                else if(dir==1){
                    nrow = row + 1;
                    ncol = col;
                }
                else if(dir==2){
                    nrow = row;
                    ncol = col - 1;
                }
                else if(dir==3){
                    nrow = row - 1;
                    ncol = col;
                }
            }
            
            if(nrow<0 || ncol<0 || nrow>=n || ncol>=m){
                ans.push_back(row);
                ans.push_back(col);
                
                break;
            }
            
            q.push({nrow,ncol});
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends