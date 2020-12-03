#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    int a1,a2,a3,a4,a5,a6;
    cin>>a1>>a2>>a3>>a4>>a5>>a6;
    ll ans = (a1+a2+a3);
    ans = ans * ans;
    ans = ans - a1*a1- a3*a3 - a5*a5;
    cout<<ans;

}