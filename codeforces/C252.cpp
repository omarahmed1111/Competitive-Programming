#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    ll n, d;
    cin>>n>>d;
    vector<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    ll ans = 0;
    for(int i=0;i<n;i++){
        ll s = (ll)a[i] + d;
        auto it = upper_bound(a.begin()+i, a.end(), s);
        ll sz = 0;
        if(it == a.end())sz = n-i-1;
        else sz = (it-a.begin()) - i - 1;
        ans+= ((sz-1)*sz)/2;
    }
    cout<<ans<<'\n';

}