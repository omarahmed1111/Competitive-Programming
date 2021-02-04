#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())

ll mod = 1e9+7;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    ll x,y,n;
    cin>>x>>y>>n;
    bool v = (n/3)%2==0;
    ll ans = 0;
    if(n%3==0){
        ans = y-x;
        if(v) ans = -ans;
    }
    else if(n%3==1){
        ans = x;
        if(!v) ans = -ans;
    }
    else {
        ans = y;
        if(!v) ans = -ans;
    }
    cout<<(ans%mod+mod)%mod;


}