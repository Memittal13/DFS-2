//Time O(mxn)
//Space O(mxn)
//Leetcode: yes
//Issue seen: none

class Solution {
public:
int row[8] = {0, 0, -1, 1};
int col[8] = {-1, 1, 0, 0};

void dfs(vector<vector<char>> &matrix, int r, int c){
    if(matrix[r][c]=='0')
      return;
    matrix[r][c]='0';
    for(int i=0; i<8; i++){
        int new_r = r+row[i];
        int new_c = c+col[i];
        //check boundaries
        if(new_r < 0 || new_r > matrix.size()-1 || new_c < 0 || new_c > matrix[0].size()-1){
            continue;
        }
        if(matrix[new_r][new_c] == '1'){
            
            dfs(matrix, new_r, new_c);
            
        }
    }
}
int numIslands(vector<vector<char>>& matrix) {
    int count=0;
    for(int i = 0; i< matrix.size(); i++){
        for(int j = 0; j<matrix[0].size(); j++){
            if(matrix[i][j]=='1'){
                dfs(matrix, i , j);
                count++;
            }
        }
    }
    return count;
}

};



