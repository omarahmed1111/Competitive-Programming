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
        ll p,a,b,c;
        cin>>p>>a>>b>>c;
        if(p%a==0||p%b==0||p%c==0){
            cout<<0<<'\n';
            continue;
        }
        ll first = (p/a+1)*a - p;
        ll second = (p/b+1)*b - p;
        ll th = (p/c+1)*c - p;
        cout<<min(first,min(second,th))<<'\n';
    }
}