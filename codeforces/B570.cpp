#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    ll n,m;
    cin>>n>>m;
    ll a = n-m;
    ll b = m-1;
    if(a==b)cout<<max(m-1, (ll)1);
    else if(a>b) cout<< min(m+1, n);
    else cout<<max(m-1, (ll)1);

}