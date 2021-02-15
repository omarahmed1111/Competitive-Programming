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
        int px,py;
        cin>>px>>py;
        string s;
        cin>>s;
        int x1 = 0,y1=0,x2=0,y2=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='R')x1++;
            if(s[i]=='U')y1++;
            if(s[i]=='D')y2++;
            if(s[i]=='L')x2++;
        }
        bool v = true;
        if(px>0&&x1<px)v=false;
        if(py>0&&y1<py)v=false;
        if(px<0&&x2<abs(px))v=false;
        if(py<0&&y2<abs(py))v=false;
        if(v)cout<<"YES\n";
        else cout<<"NO\n";
        
    }

}