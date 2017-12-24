class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //each source bfs
        int m = grid.size(); 
        int n = grid[0].size(); 
        int ans = 0; 
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){   
                if (grid[i][j] == 1) {
                    ans = max(ans, bfs(grid, i, j)); 
                }
            }      
        }
        return ans;  
    }
    
private:
    // source position: i, j
    int bfs(vector<vector<int>>& grid, int i, int j){
        int m = grid.size(); 
        int n = grid[0].size(); 
        
        
        queue<pair<int,int>> bfs;
        bfs.push(make_pair(i, j));
        
        //mark as visited
        grid[i][j] = 2;
        vector<int> dir({-1,0,1,0,-1});
        
        int area = 1; 
        
        while(!bfs.empty()){
            int currentX = bfs.front().first;
            int currentY = bfs.front().second;
            bfs.pop();
            
            // push four neighboring 
            for (int i = 0; i < 4; i++) {
                
                int r = currentX + dir[i];
                int c = currentY + dir[i+1];
                
                if (r >= 0 && r < m && c >= 0 && c < n && grid[r][c] == 1) {
                    grid[r][c] = 2;
                    area++;
                    bfs.push({r,c});
                }
            }
            
        }
     
        return area;    
    }
};