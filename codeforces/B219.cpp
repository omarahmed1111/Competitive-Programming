#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();

    ll x,y;
    cin>>x>>y;
    
    ll z = x-y;
    string a = to_string(x);
    string b = to_string(z);
    int nines = 0;
    for(int i=a.size()-1;i>0;i--){
        if(a[i]=='9')nines++;
        else break;
    }
    if(nines>=a.size()-1){
        cout<<a;
        return 0;
    }
    if(a.size()>b.size()){
        
        if(a[0]=='1'){
            string c(a.size()-1,'9');
            cout<<c;
        }
        else{
            string c(a.size(),'9');
            c[0] = a[0] - 1;
            cout<<c;
        }
        
    }
    else {
        string c,d;
        bool v = false;
        for(int i=0;i<a.size();i++){
            if(!v && a[i]==b[i])c+=a[i];
            else {
                v = true;
                d+=a[i];
            }
        }
        string l(d.size(),'9');
        int nines = 0;
        for(int i=d.size()-1;i>0;i--){
            if(d[i]=='9')nines++;
            else break;
        }

        if(d.size()==1)l[0]=d[0];
        else if(nines>=d.size()-1)l[0]=d[0];
        else l[0] = d[0] - 1;
        
        string ans = c + l;
        cout<<ans;
    }


}