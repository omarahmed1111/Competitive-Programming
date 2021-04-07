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
    for(int c = 1; c<=t;c++){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int cost = 0;
        for(int i=0;i<n-1;i++){
            int mnIdx = n+1;
            int mnN = 200;
            for(int j=i;j<n;j++){
                if(a[j]<mnN){
                    mnN = a[j];
                    mnIdx = j;
                }
            }
            
            cost += (mnIdx-i+1);
            reverse(a.begin()+i, a.begin()+mnIdx+1);
        
        }
        cout<<"Case #"<<c<<": "<<cost<<'\n';
    }


}