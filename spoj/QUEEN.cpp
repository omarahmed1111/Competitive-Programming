#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())

char grid[1009][1009];
int vis[1009][1009];
int solve(int x, int y, int stx, int sty, int test){
    memset(vis, -1, sizeof vis);
    int dep=1;
    queue<pair<int,int>> q;
    q.push({stx, sty});
    vis[stx][sty]=0;
    while(!q.empty()){
        int sz = q.size();
        while (sz--)
        {
            pair<int,int> cur = q.front();
            q.pop();
            if(grid[cur.first][cur.second] == 'F')return dep-1;
            for(int i=cur.first+1;i<x;i++){
                if(grid[i][cur.second] == 'X')break;
                if(vis[i][cur.second]==-1){
                    q.push({i, cur.second});
                    vis[i][cur.second]=vis[cur.first][cur.second]+1;
                }
                if(vis[i][cur.second]!=vis[cur.first][cur.second]+1)break;
                
            }
            for(int i=cur.first-1;i>=0;i--){
                if(grid[i][cur.second] == 'X')break;
                if(vis[i][cur.second]==-1){
                    q.push({i, cur.second});
                    vis[i][cur.second]=vis[cur.first][cur.second]+1;
                }
                if(vis[i][cur.second]!=vis[cur.first][cur.second]+1)break;
            }
            for(int i=cur.second+1;i<y;i++){
                if(grid[cur.first][i] == 'X')break;
                if(vis[cur.first][i]==-1){
                    q.push({cur.first, i});
                    vis[cur.first][i]=vis[cur.first][cur.second]+1;
                }
                if(vis[cur.first][i]!=vis[cur.first][cur.second]+1)break;
            }
            for(int i=cur.second-1;i>=0;i--){
                if(grid[cur.first][i] == 'X')break;
                if(vis[cur.first][i]==-1){
                    q.push({cur.first, i});
                    vis[cur.first][i]=vis[cur.first][cur.second]+1;
                }
                if(vis[cur.first][i]!=vis[cur.first][cur.second]+1)break;
            }
            for(int i=cur.first+1, j=cur.second+1;i<x&&j<y;i++,j++){
                if(grid[i][j] == 'X')break;
                if(vis[i][j]==-1){
                    q.push({i, j});
                    vis[i][j]=vis[cur.first][cur.second]+1;
                }
                if(vis[i][j]!=vis[cur.first][cur.second]+1)break;
            }
            for(int i=cur.first-1,j=cur.second-1;i>=0&&j>=0;i--,j--){
                if(grid[i][j] == 'X')break;
                if(vis[i][j]==-1){
                    q.push({i, j});
                    vis[i][j]=vis[cur.first][cur.second]+1;
                }
                if(vis[i][j]!=vis[cur.first][cur.second]+1)break;
            }
            for(int i=cur.first+1, j=cur.second-1;i<x&&j>=0;i++, j--){
                if(grid[i][j] == 'X')break;
                if(vis[i][j]==-1){
                    q.push({i, j});
                    vis[i][j]=vis[cur.first][cur.second]+1;
                }
                if(vis[i][j]!=vis[cur.first][cur.second]+1)break;
            }
            for(int i=cur.first-1, j=cur.second+1;i>=0&&j<y;i--, j++){
                if(grid[i][j] == 'X')break;
                if(vis[i][j]==-1){
                    q.push({i, j});
                    vis[i][j]=vis[cur.first][cur.second]+1;
                }
                if(vis[i][j]!=vis[cur.first][cur.second]+1)break;
            }
        }
        dep++;
        
    }
    return -1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    int testCases=0;
    cin>>testCases;
    int test = 1;
    while(testCases--){
        int x,y;
        cin>>x>>y;
        int stx, sty;
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                cin>>grid[i][j];
                if(grid[i][j]=='S')stx=i,sty=j;
            }
        }
        int ans = solve(x, y, stx, sty, test);
        cout<<ans<<'\n';
        test++;

    }


}