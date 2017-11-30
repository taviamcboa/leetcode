class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int numRows = image.size(); 
        int numCols = image[0].size(); 
        
        vector<vector<bool>> visited(numRows, std::vector<bool>(numCols, false));
        
        queue<pair<int, int>> bfs; 
        
        bfs.push(make_pair(sr, sc)); 
        
        while(!bfs.empty()){
            pair<int, int> current = bfs.front(); 
            
            int row = current.first; 
            
            int column = current.second; 
            
            int currentColor = image[row][column]; 
            
            if(row + 1 < numRows){
                if(visited[row + 1][column] == false && currentColor == image[row + 1][column]){
                    bfs.push(make_pair(row + 1, column)); 
                }
            }
            if(row - 1 >= 0 ){
                if(visited[row - 1][column] == false && currentColor == image[row - 1][column]){
                    bfs.push(make_pair(row - 1, column)); 
                }
            }
            if(column + 1 < numCols){
                if(visited[row][column + 1] == false && currentColor == image[row][column + 1]){
                    bfs.push(make_pair(row, column + 1)); 
                }
            }
            if(column - 1 >= 0){
                if(visited[row][column - 1] == false && currentColor == image[row][column - 1]){
                    bfs.push(make_pair(row, column - 1)); 
                }
            }
            
            bfs.pop();
            
            visited[row][column] = true;
            image[row][column] = newColor; 

        }
        
        return image; 
    }
};