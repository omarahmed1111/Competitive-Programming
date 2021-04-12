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
        vector<ll> b(n+2);
        map<ll, int> mp;
        ll sum = 0;
        for(int i=0;i<n+2;i++){
            cin>>b[i];
            sum += b[i];
            mp[b[i]]++;
        } 
        sort(all(b));
        int idx = -1;
        ll no = -1;
        for(int i=0;i<n+2;i++){
            ll tmps = sum - b[i];
            mp[b[i]]--;
            if(tmps%2==0&&mp[tmps/2]>0){
                idx = i;
                no = tmps/2;
                break;
            }
            mp[b[i]]++;
        }
        if(idx==-1){
            cout<<-1<<'\n';
        }
        else{
            vector<ll> a;
            int idx2 = -1;
            for(int i=0;i<n+2;i++){
                if(b[i]==no&&idx2!=idx){
                    idx2 = i;
                    break;
                }
            }
            for(int i=0;i<n+2;i++){
                if(i!=idx&&i!=idx2){
                    a.push_back(b[i]);
                }
            }
            for(int i=0;i<n;i++)cout<<a[i]<<" ";
            cout<<'\n';
        }
    
        
        
    }
    
}