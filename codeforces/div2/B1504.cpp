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
        string a,b;
        cin>>a>>b;
        bool inverted = false;
        int lastIdx = -1;
        vector<pair<int,int>> c(n+1);
        for(int i=0;i<n;i++){
            if(a[i]!=b[i])lastIdx=i;
            c[i+1] = c[i];
            if(a[i]=='0')c[i+1].first++;
            else c[i+1].second++;
        }
        if(lastIdx==-1){
            cout<<"YES\n";
            continue;        
        }   
        bool no = false;

        for(int i=lastIdx;i>=0;i--){
            if(i%2==0){ //odd place
                if( (a[i]!=b[i]&&!inverted) || (a[i]==b[i]&&inverted) ) no=true;
            }
            else{
                
                if( (a[i]!=b[i]&&!inverted) || (a[i]==b[i]&&inverted) ){
                    if(c[i+1].first!=c[i+1].second)no=true;
                    inverted = !inverted;
                } 
            }
        }
        if(no)cout<<"NO\n";
        else cout<<"YES\n";
    }


}