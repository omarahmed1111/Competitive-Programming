#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    
    while(true){
        int n,m;
        cin>>n>>m;
        if(n==0&&m==0)break;
        double ans = 0.0;
        if(n<=m){
            ans = (double)(m-n+1)/(m+1);
        }
        cout<<fixed<<setprecision(6)<<ans<<'\n';
    }


}