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
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    string m;
    cin>>m;
    ll first = 0;
    int last = -1;
    for(int i=0;i<n;i++){
        if(m[i]=='1'){
            first+= a[i];
            last = i;
        }
    }
    vector<ll> sum(n+1);
    for(int i=n-1;i>=0;i--){
        sum[i] = sum[i+1] + a[i] * (m[i]-'0');
    }
    ll tot = 0;
    for(int i=0;i<=last;i++){
        if(m[i]=='1'){
            first = max(first, tot+sum[i]-a[i]);
        }
        
        tot+=a[i];
    }
    cout<<first<<'\n';
    
    
    

}