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
        int n,m;
        cin>>n>>m;
        vector<int> a(n),b(n), c(m);
        vector<int> bs(n+9), need(n+9), have(n+9);
        vector<vector<int>> indeces(n+1);
        vector<int> idxOver(n+1);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++){
            cin>>b[i];
            bs[b[i]]++;
            idxOver[b[i]]=i;
            if(a[i]!=b[i]){
                need[b[i]]++;
                indeces[b[i]].push_back(i);
            }
        }
        for(int i=0;i<m;i++){
            cin>>c[i];
            have[c[i]]++;
        }
        bool v = true;
        for(int i=0;i<=n;i++){
            if(have[i]<need[i]){
                v=false;
                break;
            }
        }
        if(!v){
            cout<<"NO\n";
            continue;
        }
        int over = 0;
        for(int i=0;i<m;i++){
            if(bs[c[i]]==0)over++;
            else {
                over=0;
            }
        }
        if(over>0){
            cout<<"NO\n";
            continue;
        }
        int lastc = c[m-1];
        int idx = -1;
        vector<int> left;
        vector<int> ans(m);
        for(int i=0;i<m;i++){
            
            int sz1 = indeces[c[i]].size()-1;
            if(sz1<0){
                if(bs[c[i]]==0)
                    left.push_back(i);
                else{
                    
                    ans[i] = idxOver[c[i]];
                    idx = ans[i];
                }    
            }
            else{
                ans[i] = indeces[c[i]][sz1];
                idx = ans[i];
                indeces[c[i]].pop_back();
            }
            
        }
        idx = max(0,idx);
        for(int i=0;i<left.size();i++)ans[left[i]]=idx;
        cout<<"YES\n";
        for(int i=0;i<m;i++)cout<<ans[i]+1<<" ";
        cout<<'\n';

    }

}