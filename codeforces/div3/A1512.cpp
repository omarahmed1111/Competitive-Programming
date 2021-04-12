
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
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i].first;
            a[i].second = i;
        }
        sort(all(a));
        if(a[0].first!=a[1].first){
            cout<<a[0].second+1<<'\n';
        }
        else cout<<a[n-1].second+1<<'\n';
    }
}