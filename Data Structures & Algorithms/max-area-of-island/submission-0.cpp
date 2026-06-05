class Solution {
public:

    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};

    bool isValid(int i , int j , int n , int m){
        if(i<0 or i>= n or j<0 or j>=m){
            return false;
        }
        return true;
    }

    int dfs(vector<vector<int>>&a , int i , int j , int n , int m , vector<vector<bool>>& vis){
        vis[i][j] = 1;
        int area =  1;

        //explore in all directions
        for(int k = 0 ; k<4 ; k++){
            int row = i + x[k];
            int col = j + y[k];
            if(isValid(row,col, n, m) and a[row][col] == 1 and vis[row][col] == 0){
                area += dfs(a,row,col, n , m,vis);
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>vis(n);

        for(int i = 0 ; i<n ; i++){
            vector<bool>t(m,0);
            vis[i] = t;

            
        }
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j] == 1 and vis[i][j] == 0){
                  int area =  dfs(grid,i,j,n,m,vis);
                    ans = max(ans,area);
                }
            }
        }




       return ans;
        
    }
};
