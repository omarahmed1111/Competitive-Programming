#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())

int compute(vector<int> &a, int n){
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
    return cost;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    int t;
    cin>>t;
    for(int c = 1; c<=t;c++){
        int n,costt;
        cin>>n>>costt;
        
        vector<int> a(n);
        for(int i=0;i<n;i++)a[i]=i+1;
        bool v = false;
        do{
            vector<int> tmp(all(a));
            int cost = compute(tmp,n);
            if(cost==costt){
                v=true;
                break;
            }
        } while(next_permutation(all(a)));
        if(!v){
            cout<<"Case #"<<c<<": IMPOSSIBLE\n";
        }
        else {
            cout<<"Case #"<<c<<": ";
            for(int i=0;i<n;i++){
                cout<<a[i]<<" ";
            }
            cout<<"\n";
        }
    }


}