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
        int a,b;
        cin>>a>>b;
        string s;
        cin>>s;
        int n = a+b;
        bool v = false;
        int x=0,y=0,z=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0')x++,a--;
            else if(s[i]=='1') y++,b--;
            else z++;
        }
        if(z==0){
            bool vl = false;
            for(int i=0,j=n-1;i<j;i++,j--){
                if(s[i]!=s[j]){
                    vl = true;
                    break;
                }
            }
            if(vl||a!=0||b!=0){
                cout<<-1<<'\n';
                continue;
            }
            else{
                cout<<s<<'\n';
                continue;
            }
        }
        for(int i=0,j=n-1;i<j;i++,j--){
            if(s[i]=='?'&&s[j]!='?'){
                s[i] = s[j];
                if(s[i]=='0')a--;
                else b--;
            }
            else if(s[j]=='?'&&s[i]!='?'){
                s[j] = s[i];
                if(s[i]=='0')a--;
                else b--;
            }
        }
        if(a<0||b<0){
            cout<<-1<<'\n';
            continue;
        }
        if(n%2==1&&s[n/2]=='?'){
            if(a%2==1)s[n/2] = '0', a--;
            else if(b%2==1)s[n/2] = '1', b--;
        }
        if(a%2==1||b%2==1){
            cout<<-1<<'\n';
            continue;
        }
        for(int i=0,j=n-1;i<j;i++,j--){
            if(s[i]=='?'&&s[j]=='?'){
                if(a>1){
                    s[i] = '0';
                    s[j] = '0';
                    a = a - 2;
                }
                else if(b>1){
                    s[i] = '1';
                    s[j] = '1';
                    b  = b - 2;
                }
                else v=true;
            }
        }
        for(int i=0,j=n-1;i<j;i++,j--){
            if(s[i]!=s[j])v=true;
        }
        
        if(v||a!=0||b!=0){
            cout<<-1<<'\n';
            continue;
        }
        cout<<s<<'\n';
    
    }
}