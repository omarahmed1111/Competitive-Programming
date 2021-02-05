#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())
vector<int> a;
int sz;
int dp[3005][3005];
int solve(int idx, int prev){
    if(idx>=sz) return 0;

    int &ret = dp[idx][prev];
    if(ret!=-1) return ret;
    if(a[idx]>a[prev]){
        return ret = max(solve(idx+1, idx)+1, solve(idx+1, prev));
    }
    return ret = solve(idx+1, prev);

}

void print(int idx, int prev){
    if(idx>=sz) return;

    int ret = solve(idx, prev);
    if(ret == solve(idx+1, idx)+1){
        cout<<a[idx]<<'\n';
        print(idx+1, idx);
        return;
    }
    print(idx+1, prev);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    int t;
    cin>>t;
    cin.ignore();
    cin.ignore();
    while(t--){
        a.clear();
        string s;
        while(getline(cin, s)&&s!=""){
            int tmp = stoi(s);
            a.push_back(tmp);
        }
        memset(dp, -1, sizeof dp);
        sz = a.size();
        a.push_back(0);
        cout<<"Max hits: "<<solve(0, sz)<<'\n';
        print(0,sz);
        if(t>0)cout<<'\n';
    }


}