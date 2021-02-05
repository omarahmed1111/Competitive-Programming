#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())
string a,b;

int dp[109][109];
int solve(int i, int j){
    if(i>=a.size()||j>=b.size()) return 0;
    int &ret = dp[i][j];
    if(ret!=-1) return ret;
    
    if(a[i]==b[j]){
        ret = solve(i+1, j+1) + 1;
        return ret;
    }
    ret = max(solve(i+1, j), solve(i, j+1));
    return dp[i][j];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    int c = 1;
    while(true){
        
        getline(cin,a);
        if(a[0]=='#')break;
        
        getline(cin, b);
        memset(dp, -1, sizeof dp);
        int mx = solve(0,0);
        cout<<"Case #"<<c<<": you can visit at most "<<mx<<" cities.\n";
        c++;
    }


}