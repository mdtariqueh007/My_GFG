//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	#define pi pair<int,pair<int,int>>
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        
        int n = grid.size();
        
        
        vector<vector<int>> dis(n,vector<int>(n,1e9));
        
        dis[0][0] = grid[0][0];
        
        priority_queue<pi,vector<pi>,greater<>> pq;
        
        pq.push({dis[0][0],{0,0}});
        
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};
        
        while(!pq.empty()){
            int d = pq.top().first;
            
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            
            pq.pop();
            
            for(int i = 0;i<4;i++){
                int nrow = row + dx[i];
                int ncol = col + dy[i];
                
                if(nrow<0 || ncol<0 || nrow>=n || ncol>=n){
                    continue;
                }
                
                if(dis[nrow][ncol]>d + grid[nrow][ncol]){
                    dis[nrow][ncol] = d + grid[nrow][ncol];
                    
                    pq.push({dis[nrow][ncol],{nrow,ncol}});
                }
            }
        }
        
        return dis[n-1][n-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends