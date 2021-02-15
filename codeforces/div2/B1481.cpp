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
        int n,k;
        cin>>n>>k;
        vector<int> h(n);
        for(int i=0;i<n;i++)cin>>h[i];
        int tr = -1;
        for(int i=0;i<k;i++){
            bool v = false;
            for(int j=0;j<n-1;j++){
                if(h[j]<h[j+1]){
                    h[j]++;
                    tr = j+1;
                    v=true;
                    break;
                }
            }
            if(!v){
                tr= -1;
                break;
            }

        }
        cout<<tr<<'\n';

    }

}