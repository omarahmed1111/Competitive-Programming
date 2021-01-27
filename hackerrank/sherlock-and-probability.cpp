#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    int c;
    cin>>c;
    while(c--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int> forward(n+9), backward(n+9);
        for(int i=1;i<=n;i++){
            forward[i] = forward[i-1] + (s[i-1]-'0');
        }
        for(int i=n;i>0;i--){
            backward[i] = backward[i+1] + (s[i-1]-'0');
        }
        ll nom = 0;
        ll dom = (ll)n*n;
        for(int i=1;i<=n;i++){
            if(s[i-1]=='1'){
                if(i-k-1>=0){
                    nom+= forward[i] - forward[i-k-1];
                }  
                else{
                    nom+= forward[i];
                }
                if(i+k+1<=n){
                    nom+= backward[i] - backward[i+k+1];
                }
                else {
                    nom += backward[i];
                }
                nom--;
            }
        }
        if(nom==0){
            cout<<"0/1\n";
        }
        else {
            ll g = __gcd(nom, dom);
            nom/=g;
            dom/=g;
            cout<<nom<<"/"<<dom<<'\n';
        }
    }

}