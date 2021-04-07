#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())
bool isPali(string s){
    for(int i=0,j=s.size()-1;i<j;i++,j--){
        if(s[i]!=s[j])return false;
    }
    return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        bool v = false;
        int sz = s.size();
        int idx = 0;
        for(int i=0;i<sz;i++)if(s[i]!='a')v=true, idx=i;
        if(!v){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        string n = 'a' + s;
        if(!isPali(n)){
            cout<<n<<'\n';
        }
        else cout<<s+'a'<<'\n';

    }


}