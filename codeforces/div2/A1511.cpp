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
       int n;
       cin>>n;
       vector<int> a(n);
       for(int i=0;i<n;i++)cin>>a[i];
       int up = 0;
       for(int i=0;i<n;i++){
           if(a[i]==1||a[i]==3)up++;
       }
       cout<<up<<'\n';

    }
}