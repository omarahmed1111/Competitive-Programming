#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())
int n,m;
string s,t;


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
       
    cin>>n>>m;
    
    cin>>s>>t;
    vector<int> l(m+1), f(m+1);
    for(int i=m-1, j=n-1;i>=0&&j>=0;j--){
        if(s[j]==t[i]){
            l[i] = j;
            i--;
        }
    }
    for(int i=0, j=0;i<m&&j<n;j++){
        if(s[j]==t[i]){
            f[i] = j;
            i++;
        }
    }
    int mx = 0;
    for(int i=1;i<m;i++){
        mx = max(mx, abs(l[i]-f[i-1]));
    }
    cout<<mx;
}