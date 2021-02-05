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
    if(n<=2){
        cout<<-1;
        return 0;
    }
    if(n%2==0){
        ll t = n/2;
        ll m = t*t-1;
        ll k = t*t+1;
        cout<<m<<" "<<k;
    }
    else {
        ll t = n * n;
        ll m = t/2;
        ll k = (t+1)/2;
        cout<<m<<" "<<k;
    }


}