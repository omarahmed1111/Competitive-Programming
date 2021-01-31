#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())

vector<int> a;
bool solve(int idx, int n){
    if(idx>=5){
        if(n==23)return true;
        return false;
    }

    if(solve(idx+1, n*a[idx]) || solve(idx+1, n+a[idx]) || solve(idx+1, n-a[idx]))return true;
    return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    
    while(true){
        a = vector<int>(5);
        cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4];
        if(a[0]==0&&a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0)break;
        sort(all(a));
        bool valid = false;
        if(solve(1,a[0])){
            valid = true;
        }
        while(next_permutation(all(a))){
            int ans = a[0];
            if(solve(1,ans)){
                valid = true;
                break;
            }
        }
        if(valid)cout<<"Possible\n";
        else cout<<"Impossible\n";
        
        
    }
    


}

/*
1 1 1 1 1
1 2 3 4 5
2 3 5 7 11
0 0 0 0 0
*/