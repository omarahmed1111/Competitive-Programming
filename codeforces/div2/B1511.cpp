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
       ll a,b,c;
       cin>>a>>b>>c;
       string x;
       x = x + '1';
       for(int i=0;i<a-1;i++)x = x + '0';
       string y;
       y = y + '1';
       for(int i=0;i<c-1;i++)y = y + '0';
       for(int i=0;i<(b-1)-(c-1);i++)y = '1' + y;
       cout<<x<<" "<<y<<'\n'; 
       
       
    }

}