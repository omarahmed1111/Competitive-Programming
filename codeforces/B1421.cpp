#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<char>> g(n, vector<char>(n));
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>g[i][j];
        vector<pair<int,int>> ans, ans2;
        if(g[0][1]!= '0')ans.push_back({1, 2});
        if(g[1][0]!= '0')ans.push_back({2, 1});
        if(g[n-1][n-2]!= '1')ans.push_back({n, n-1});
        if(g[n-2][n-1]!= '1')ans.push_back({n-1, n});
        
        if(g[0][1]!= '1')ans2.push_back({1, 2});
        if(g[1][0]!= '1')ans2.push_back({2, 1});
        if(g[n-1][n-2]!= '0')ans2.push_back({n, n-1});
        if(g[n-2][n-1]!= '0')ans2.push_back({n-1, n});

        if(ans.size()>2 && ans2.size()>2){
            cout<<0<<'\n';
        }
        else if(ans.size()<2){
            cout<<ans.size()<<'\n';
            for(int i=0;i<ans.size();i++)cout<<ans[i].first<<" "<<ans[i].second<<'\n';

        }
        else{
            cout<<ans2.size()<<'\n';
            for(int i=0;i<ans2.size();i++)cout<<ans2[i].first<<" "<<ans2[i].second<<'\n';

        }
    }


}