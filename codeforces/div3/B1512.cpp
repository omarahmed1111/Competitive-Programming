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
        int n;
        cin>>n;
        vector<vector<char>> a(n, vector<char>(n));
        pair<int,int> x,y;
        bool v = false;
        for(int i = 0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
                if(a[i][j]=='*'){
                    if(!v){
                        x.first = i;
                        x.second = j;
                        v=true;
                    }
                    else{
                        y.first = i;
                        y.second = j;
                    }
                }
            }
        }
        if(x.first!=y.first&&x.second!=y.second){
            a[x.first][y.second] = '*';
            a[y.first][x.second] = '*';
        }
        else if(x.first==y.first){
            if(x.first==0){
                a[x.first+1][x.second] = '*';
                a[x.first+1][y.second] = '*';
            }
            else{   
                a[x.first-1][x.second] = '*';
                a[x.first-1][y.second] = '*';
            }
        }
        else{
            if(x.second==0){
                a[x.first][x.second+1] = '*';
                a[y.first][y.second+1] = '*';
            }
            else{   
                a[x.first][x.second-1] = '*';
                a[y.first][y.second-1] = '*';
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<a[i][j];
            }
            cout<<'\n';
        }
    }
}