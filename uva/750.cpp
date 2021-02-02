#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())

int sol = 1;
int x,y;
vector<int> grid;
bool valid(int row, int col){
    
    if(row==x || col==y || abs(row-x) == abs(col-y))return false;
    for(int i=1;i<=8;i++){
        if(grid[i]==0)continue;
        if(col==i||row==grid[i])return false;
        if(abs(row-grid[i]) == abs(col-i))return false;
    }
    return true;
}
void solve(int col){
    if(col>=9){
        cout<<setw(2)<<sol;
        cout<<"      ";
        for(int i=1;i<=8;i++){
            cout<<grid[i];
            if(i!=8)cout<<" ";
        }
        cout<<'\n';
        sol++;
        return;
    }
    if(col==y){
        solve(col+1);
        return;
    }
    for(int row=1;row<=8;row++){
        if(valid(row, col)){
            grid[col]=row;
            solve(col+1);
            grid[col]=0;
        }
    }
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    int t;
    cin>>t;
    bool nn = false;
    while(t--){
        sol = 1;
        grid = vector<int>(9);
        cin>>x>>y;
        grid[y] =x;
        if(nn)cout<<'\n';
        nn = true;
        cout<<"SOLN       COLUMN\n";
        cout<<" #      1 2 3 4 5 6 7 8\n";
        cout<<'\n';
        solve(1);
        
    }


}