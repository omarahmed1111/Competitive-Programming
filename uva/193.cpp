#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())

map<pair<int,int>, bool> g;
vector<int> color;
set<int> gmx;
int mx = 0;
int n;
set<int> black;
void solve(int node=1){
    if(node > n){
        if(black.size()>mx){
            mx = black.size();
            gmx = black;
        }
        return;
    }
    color[node] = 0;
    solve(node+1);
    bool valid= true;
    for(int bnode: black){
        if(g[{bnode, node}] || g[{node, bnode}])valid = false;
    }
    if(valid){
        color[node] = 1;
        black.insert(node);
        solve(node+1);
        black.erase(node);
    }
    
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    int t;
    cin>>t;
    while(t--){
        mx=0;
        black = set<int>();
        gmx = set<int>();
        int m;
        cin>>n>>m;
        g = map<pair<int,int>, bool>();
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            g[{a,b}] = true;
            g[{b,a}] = true;
        }
        color = vector<int>(n+9);
        solve();
        cout<<mx<<'\n';
        int i=0;
        for(int bnode: gmx){
            cout<<bnode;
            i++;
            if(i!=gmx.size())cout<<' ';
        }
        cout<<'\n';
        
    }


}

/* 
1
6  8
1  2
1  3
2  4
2  5
3  4
3  6
4  6
5  6
*/