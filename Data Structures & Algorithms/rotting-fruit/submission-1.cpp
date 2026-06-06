class Solution {
public:
    int x[4] = {-1,1,0,0};
    int y[4] = {0,0,-1,1};

    bool isValid(int i , int j , int n  , int m){
        if(i<0 or i>= n or j<0 or j>=m){
            return false;
        }
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        int fresh = 0 ;

        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        int minutes = 0 ;
        while(!q.empty() && fresh>0){
            int sz = q.size();
            while(sz--){
                auto [i,j] = q.front();
                q.pop();

                for(int k = 0 ; k<4 ; k++){
                    int row = i + x[k];
                    int col = j + y[k];

                    if(isValid(row,col, n, m) && grid[row][col] ==1){
                        grid[row][col] = 2;
                        fresh--;
                        q.push({row,col});
                    }
                }
                
            }
            minutes++;
        }
        return fresh == 0 ?minutes:-1;        
    }
};
