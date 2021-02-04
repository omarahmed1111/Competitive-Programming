#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    ll n;
    cin>>n;
    ll ans = 0;
    if(n%3==0){
        ll t = 3;
        while(n%t==0){
            t*=3;
        }
        ans = max((ll)1, (ll)n/t + 1);
    }
    else {
        ans = n/3 + 1;
    }

    cout<<ans;


}