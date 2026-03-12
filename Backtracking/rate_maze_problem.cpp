#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
string dir="DLRU";
int dr[4]={1, 0 , 0, -1};
int dc[4]={0, -1, 1, 0};

bool isValid(int r, int c, int n, vector<vector<int>>&maze){
    if(r>=0 && c>=0 && r<n && c<n && maze[r][c]==1)return true;
    return false;
}

void findPath(int r, int c, vector<vector<int>>&maze, string &path, vector<string>&res){
    int n = maze.size();
    // Base Case: if destination is reached , store the path
    if(r==n-1 && c==n-1){
        res.push_back(path);
        return;
    }
    
    //mark current cell as visited
    maze[r][c]=0;
    
    
    // each cell has 4 option 
    for(int i=0;i<4;i++){
        int nr=r+dr[i], nc = c+dc[i];
        if(isValid(nr, nc, n, maze)){
            path.push_back(dir[i]);
            
            // move to the next cell
            findPath(nr,nc,maze, path, res);
            
            // revert changes
            path.pop_back();
        }
    }
    // unmark current cell
    maze[r][c]=1;
}

vector<string> ratInMaze(vector<vector<int>>&maze){
    vector<string>res;
    int n = maze.size();
    string path="";
    if(maze[0][0]==1 && maze[n-1][n-1]==1){
        findPath(0,0,maze, path, res);
    }
    
    // sort the result lexicographically
    sort(res.begin(), res.end());
    return res;
}

int main(){
    //  Represents an open cell (rat can visit), and 0 represents a blocked cell (rat cannot visit).
    vector<vector<int>> maze={{1, 0, 0, 0}, {1, 1, 0, 1},{1, 1, 0, 0}, {0,1,1,1}};
    vector<string>ans=ratInMaze(maze);
    for(auto p: ans){
        cout<<p<<" ";
    }
    return 0;
}
