#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())

// a < b
// 1 smaller
// 2 bigger
// 0 equal
int cmp(string &a, string &b){
    if(a.size() < b.size()) return 1;
    if(b.size() < a.size()) return 2;
    for(int i=0;i<a.size();i++){
        if(a[i]<b[i]) return 1;
        else if(b[i]<a[i]) return 2;
    }
    return 0;
}

string getMin(string &a, string &b){
    
    for(int i=0;i<10;i++){
        string tmp = a + (char)('0'+i);
        
        if(cmp(tmp, b) == 2) return tmp;
    }
    return "";
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    int t;
    cin>>t;
    for(int c=1;c<=t;c++){
        int n;
        cin>>n;
        vector<string> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        int op = 0;
        for(int i=1;i<n;i++){
            if(cmp(a[i], a[i-1]) == 0){
                op++;
                a[i] = a[i] + '0';
            }
            
            else if(cmp(a[i], a[i-1]) == 1){
                string x = a[i];
                string y = a[i-1];
                if(x.size() == y.size()){
                    op++;
                    string temp = x + '0';
                    a[i] = temp;
                }
                else if(x.size()+1 == y.size()){
                    string ans = getMin(x, y);
                    if(ans==""){
                        a[i] = x+'0'+'0';
                        op+=2;
                    }
                    else{
                        a[i] = ans;
                        op++;
                    }
                }
                else{
                    int last = x.size();
                    string z = "";
                    for(int j=0;j<last;j++)z+=y[j];
                    
                    if(cmp(x,z) == 2){
                        int rem = y.size() - last;
                        for(int j=0;j<rem;j++){
                            x = x + '0';
                            op++;
                        }
                        a[i] = x;
                    }
                    else if(cmp(x,z) == 1){
                        int rem = y.size() - last;
                        for(int j=0;j<rem;j++){
                            x = x + '0';
                            op++;
                        }
                        op++;
                        x = x + '0';
                        a[i] = x;
                    }
                    else{
                        int firstNonNine = -1;
                        for(int j=y.size()-1;j>=last;j--){
                            if(y[j]!='9'){
                                firstNonNine = j;
                                break;
                            }
                        }
                        if(firstNonNine==-1){
                            int rem = y.size() - last;
                            for(int j=0;j<rem;j++){
                                x = x + '0';
                                op++;
                            }
                            op++;
                            x = x + '0';
                            a[i] = x;
                        }
                        else{
                            for(int j=last;j<firstNonNine;j++){
                                x = x + y[j];
                                op++;
                            }
                            x = x + (char)(y[firstNonNine] + 1);
                            op++;
                            for(int j=firstNonNine+1;j<y.size();j++){
                                x = x + '0';
                                op++;
                            }
                            a[i] = x;
                        }
                    }
                }
            }
        }
        cout<<"Case #"<<c<<": "<<op<<'\n';
    }


}