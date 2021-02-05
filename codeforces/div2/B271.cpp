#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())

bool isp[1000009];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    vector<int> primes;
    for(int i=2;i<=1000000;i++){
        if(isp[i])continue;
        primes.push_back(i);
        for(int j=i;j<=1000000;j+=i)isp[j]=true;
    }
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n, vector<int>(m));
    vector<vector<int>> need(n, vector<int>(m));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>g[i][j];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            auto it = lower_bound(all(primes), g[i][j]);
            
            need[i][j] = (*it) - g[i][j];
            
        }
    }
    int ans = INT_MAX;
    for(int i=0;i<n;i++){
        int tmp = 0;
        for(int j=0;j<m;j++){
            tmp+=need[i][j];
        }
        ans = min(ans, tmp);
    }
    for(int i=0;i<m;i++){
        int tmp = 0;
        for(int j=0;j<n;j++){
            tmp+=need[j][i];
        }
        ans = min(ans, tmp);
    }
    cout<<ans<<'\n';

}