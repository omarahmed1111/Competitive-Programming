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
        ll n,k;
        cin>>n>>k;
        if(k==1){
            cout<<1<<'\n';
            continue;
        }
        if(n%2==0){
            ll ans = k%n;
            if(ans==0)ans = n;
            cout<<ans<<'\n';
        }
        else{
            ll r = n/2;
            k--;
            ll ans = 0;
            
            ll twos = (k/r);
            ll left = k - k/r;
            ans = 1 + 2*twos + left;
        
            ans = ans%n;
            if(ans==0)ans = n;
            cout<<ans<<'\n';

        }
    }

}