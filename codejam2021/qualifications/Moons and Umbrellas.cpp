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
    for(int c=1;c<=t;c++){
        int x,y;
        string s;
        cin>>x>>y>>s;
        bool v = false;
        for(int i=0;i<s.size();i++)if(s[i]=='C'||s[i]=='J')v=true;
        if(!v){
            cout<<"Case #"<<c<<": "<<0<<'\n';
            continue;
        }
        for(int i=0;i<s.size();i++){
            for(int j=0;j<s.size();j++){
                if(s[j]=='?'){
                    if(j==0){
                        if(s[j+1]!='?'){
                            s[j]=s[j+1];
                        }
                    }
                    else if(j==s.size()-1){
                        if(s[j-1]!='?'){
                            s[j]=s[j-1];
                        }
                    }
                    else{
                        if(s[j-1]!='?'){
                            s[j] = s[j-1];
                        }
                        else if(s[j+1]!='?'){
                            s[j] = s[j+1];
                        }
                    }
                }
            }
        }
        int cost = 0;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='C'&&s[i+1]=='J')cost += x;
            else if(s[i]=='J'&&s[i+1]=='C')cost += y;
        }
        cout<<"Case #"<<c<<": "<<cost<<'\n';
    }


}