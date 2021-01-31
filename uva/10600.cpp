#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())

vector<vector<pair<int,int>>> g;

struct union_set{
    vector<int> parent, rank;
    union_set(int n){
        parent = vector<int>(n+9);
        rank = vector<int>(n+9);
        for(int i=0;i<=n;i++)parent[i]=i;
    }
    int find_parent(int p){
        if(parent[p]==p) return p;
        return parent[p] = find_parent(parent[p]);
    }
    void connect(int a, int b){
        a = find_parent(a);
        b = find_parent(b);
        if(a!=b){
            if(rank[a]<rank[b])swap(a,b);
            parent[b]=a;
            if(rank[a]==rank[b])rank[a]++;
        }
    }

};

struct edge{
    int u,v,w;
    edge(int a, int b, int c){
        u=a, v=b, w=c;
    }
    bool operator<(edge &b){
        return w<b.w;
    }
};
vector<edge> mst;
int kruskal(int n, bool build, edge cur=edge(0,0,0)){
    union_set u(n);
    vector<edge> edges;
    map<pair<int,int>, bool> vis;
    for(int i=1;i<=n;i++){
        for(int j=0;j<g[i].size();j++){
            if(!vis[{i, g[i][j].first}]&&!vis[{g[i][j].first, i}]){
                edge tmp = edge(i, g[i][j].first, g[i][j].second);
                if((tmp.u == cur.u && tmp.v==cur.v) || (tmp.v == cur.u && tmp.u==cur.v))tmp.w = 500;
                edges.push_back(tmp);
                vis[{i,g[i][j].first}] = true;
            }
        }
    }
    sort(all(edges));
    int cost=0;
    for(edge e : edges){
        
        if(u.find_parent(e.u) != u.find_parent(e.v)){
            cost+= e.w;
            u.connect(e.u, e.v);
            if(build)mst.push_back(e);
        }
    }
    return cost;
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    int t;
    cin>>t;
    while(t--){
        mst = vector<edge>();
        int n,m;
        cin>>n>>m;
        g = vector<vector<pair<int,int>>>(n+9);
        for(int i=0;i<m;i++){
            int a,b,c;
            cin>>a>>b>>c;
            g[a].push_back({b,c});
            g[b].push_back({a,c});
        }
        int cost1= kruskal(n, true);
        cout<<cost1<<' ';
        int cost2 = INT_MAX;
        for(int i=0;i<mst.size();i++){
            edge cur = mst[i];
            cost2 = min(cost2, kruskal(n, false, cur));
        }
        cout<<cost2<<'\n';

    }


}

/*
2
5 8
1 3 75
3 4 51
2 4 19
3 2 95
2 5 42
5 4 31
1 2 9
3 5 66
9 14
1 2 4
1 8 8
2 8 11
3 2 8
8 9 7
8 7 1
7 9 6
9 3 2
3 4 7
3 6 4
7 6 2
4 6 14
4 5 9
5 6 10
*/