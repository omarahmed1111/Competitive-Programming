#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    int n;
    cin>>n;
    vector<ll> p(n);
    ll ans = 0;
    for(int i=0;i<n;i++){
        cin>>p[i];
        ans ^= p[i];
    }
    for(int i=1;i<=n;i++){
        if((n-i)%2 == 1){
            ans ^= i;
        }
    }
    vector<ll> save(n+1);
    for(int i=1;i<=n;i++)save[i] = save[i-1]^i;

    for(int i=1;i<=n;i++){
        int total = n-i+1;
        int f = total/i;
        if(f%2==1){
            ans^= save[i-1];
        }
        ans^= save[max(0, total%i-1)]; 
    }
    cout<<ans<<'\n';

    
    


}