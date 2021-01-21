#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())

int min4(int x, int y, int z, int w){
    return min(x, min(y, min(z, w)));
}

char grid[25][25];

map<pair<int,int>,int> ids;

struct node{
    int x;
    int y;
    ll mask;
    int dirty;
    node(int a, int b, int c, ll d){
        x=a, y=b, mask=d, dirty=c;
    }
};
int solve2(int x, int y, int dirty, int stx, int sty){
    map<ll, bool> vis[25][25];
    queue<node> q;
    ll mask = 0;
    node first(stx, sty, dirty, mask); 
    q.push(first);
    int dep = 0;
    vis[stx][sty][mask]=true;
    while(!q.empty()){
        int sz = q.size();
        while(sz--){
            node cur = q.front();
            q.pop();

            if(cur.dirty==0) return dep;
            if(cur.x+1<x && grid[cur.x+1][cur.y]!='x' && !vis[cur.x+1][cur.y][cur.mask]){
                vis[cur.x+1][cur.y][cur.mask] = true;
                int new_dirty = cur.dirty;
                ll new_mask = cur.mask;
                bool check = cur.mask&(1<<ids[{cur.x+1, cur.y}]);
                if(grid[cur.x+1][cur.y]=='*'&&!check){
                    new_dirty--;
                    new_mask = (cur.mask|(1<<ids[{cur.x+1,cur.y}]));
                }
                
                node n(cur.x+1, cur.y, new_dirty, new_mask);    
                
                q.push(n);
            }
            if(cur.x-1>=0 && grid[cur.x-1][cur.y]!='x' && !vis[cur.x-1][cur.y][cur.mask]){
                vis[cur.x-1][cur.y][cur.mask] = true;
                int new_dirty = cur.dirty;
                ll new_mask = cur.mask;
                bool check = cur.mask&(1<<ids[{cur.x-1, cur.y}]);
                if(grid[cur.x-1][cur.y]=='*' && !check){
                    new_dirty--;
                    new_mask = (cur.mask|(1<<ids[{cur.x-1,cur.y}]));
                }
                node n(cur.x-1, cur.y, new_dirty, new_mask);
                
                q.push(n);
            }
            if(cur.y-1>=0 && grid[cur.x][cur.y-1]!='x' && !vis[cur.x][cur.y-1][cur.mask]){
                vis[cur.x][cur.y-1][cur.mask] = true;
                int new_dirty = cur.dirty;
                ll new_mask = cur.mask;
                bool check = cur.mask&(1<<ids[{cur.x, cur.y-1}]);
                if(grid[cur.x][cur.y-1]=='*' && !check){
                    new_dirty--;
                    new_mask = (cur.mask|(1<<ids[{cur.x,cur.y-1}]));
                }
                node n(cur.x, cur.y-1, new_dirty, new_mask);

                q.push(n);
            }
            if(cur.y+1<y && grid[cur.x][cur.y+1]!='x' && !vis[cur.x][cur.y+1][cur.mask]){
                vis[cur.x][cur.y+1][cur.mask] = true;
                int new_dirty = cur.dirty;
                ll new_mask = cur.mask;
                bool check = cur.mask&(1<<ids[{cur.x, cur.y+1}]);
                if(grid[cur.x][cur.y+1]=='*' && !check){
                    new_dirty--;
                    new_mask = (cur.mask|(1<<ids[{cur.x,cur.y+1}]));
                }
                node n(cur.x, cur.y+1, new_dirty, new_mask);
                q.push(n);
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
    int x=1,y=1;
    while(true){
        cin>>x>>y;
        if(x==0&&y==0)return 0;
        swap(x,y);
        int id = 1;
        int dirty = 0;
        int stx=0, sty=0;
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                cin>>grid[i][j];
                if(grid[i][j]== '*'){
                    dirty++;
                    ids[{i,j}] = id;
                    id++;
                }
                if(grid[i][j]== 'o'){
                    stx=i;
                    sty=j;
                }
            }
        }
        
            int ans = solve2(x, y, dirty, stx, sty);
            cout<<ans<<'\n';
        
        
    }


}