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
        map<int,vector<int>> ans;
        for(int i=1;i<=n;i++)ans[i] = vector<int>(n+1);
        int matches = n*(n-1)/2;
        int host = 1;
        int wins = matches/n;
        for(int i=1;i<=n;i++){
            for(int j=0, plays=i+1;j<wins;j++,plays++){
                int p = plays%n;
                if(p==0)p=n;
                ans[i][p] = 1;
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(ans[i][j]==1)cout<<1<<' ';
                else if(ans[j][i]==1)cout<<-1<<' ';
                else cout<<0<<' ';
            }
        }
        cout<<'\n';

    }

}