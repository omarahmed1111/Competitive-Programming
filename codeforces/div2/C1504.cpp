#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())

bool isValid(string s){
    stack<int> st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')st.push(0);
        else{
            if(st.empty())return false;
            st.pop();
        }
    }
    if(st.empty())return true;
    return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        if(s[0]=='0'||s[n-1]=='0'){
            cout<<"NO\n";
            continue;
        }
        string a(n, '('),b(n, '(');
        int x=1,y=1;
        bool vld = true;
        for(int i=1;i<n;i++){
            if(s[i]=='1'){
                if(i==n-1 || (x>1&&y>1) || (x>1&&y==1) || (y>1&&x==1)){
                    a[i] = ')';
                    b[i] = ')';
                    x--;
                    y--;
                }
                else {
                    a[i] = '(';
                    b[i] = '(';
                    x++;
                    y++;
                }
            }
            else{
                if(x==y&&x==0){
                    vld = false;
                    break;
                }
                if(x>y){
                    a[i] = ')';
                    b[i] = '(';
                    x--;
                    y++;
                }
                else{
                    a[i] = '(';
                    b[i] = ')';
                    x++;
                    y--;
                }
            }
        }
        if(!vld){
            cout<<"NO\n";
            continue;
        }
        if(isValid(a)&&isValid(b)){
            cout<<"YES\n";
            cout<<a<<'\n'<<b<<'\n';
        }
        else{
            cout<<"NO\n";
        }

    }


}