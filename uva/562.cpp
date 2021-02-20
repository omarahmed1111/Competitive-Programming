#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())

int m;
vector<int> c;
int dp[109][50009];
int solve(int i, int sum1, int sum2){
    if(i>=m){
        return abs(sum1-sum2);
    }
    if(dp[i][sum1]!=-1) return dp[i][sum1];
    return dp[i][sum1] = min(solve(i+1, sum1+c[i], sum2), solve(i+1, sum1, sum2+c[i]));
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    int t;
    cin>>t;
    while(t--){
        memset(dp, -1, sizeof dp);
        cin>>m;
        c = vector<int>(m);
        for(int i=0;i<m;i++)cin>>c[i];
        cout<<solve(0,0,0)<<'\n';
    }

}

/* 
2
3
2 3 5
4
1 2 4 6
*/