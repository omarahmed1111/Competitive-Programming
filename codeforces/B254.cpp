#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    ifstream cin;
    ofstream cout;
    cin.open("input.txt");
    cout.open("output.txt");
    vector<vector<int>> jury(12),jury1(12);
    for(int i=0;i<12;i++){
        if(i==1){
            jury[i] = vector<int>(28);
            jury1[i] = vector<int>(28);
        }
        else {
            if(i<7){
                if(i%2==0){
                    jury[i] = vector<int>(31);
                    jury1[i] = vector<int>(31);
                }
                else {
                    jury[i] = vector<int>(30);
                    jury1[i] = vector<int>(30);
                }
            }
            else {
                if(i%2==1){
                    jury[i] = vector<int>(31);
                    jury1[i] = vector<int>(31);
                }
                else {
                    jury[i] = vector<int>(30);
                    jury1[i] = vector<int>(30);
                }
            }
        }
    }
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int day,mon,w,days;
        cin>>mon>>day>>w>>days;
        mon--;
        day--;
        bool v = false;
        if(mon==0&&day==0){
            v=true;
            mon=11;
            day = 30;
        }
        else if(day==0){
            mon--;
            day = jury[mon].size()-1;
        }
        else {
            day--;
        }


        for(int d=day;days>0&&d>=0;d--){
            if(v)jury[mon][d]+=w;
            else {
                jury1[mon][d]+=w;
            }
            days--;
        }
        if(mon==0){
            v=true;
            mon=11;
        }
        else mon--;

        for(int m=mon;days>0;m--){
            for(int d=jury[m].size()-1;days>0&&d>=0;d--){
                if(v)jury[m][d]+=w;
                else jury1[m][d]+=w;
                
                days--;
            }
            if(m==0){
                v=true;
                m=11;
            }
        }
        

    }
    int ans=0;
    for(int i=0;i<jury.size();i++){
        for(int j=0;j<jury[i].size();j++){
            ans = max(ans,jury[i][j]);
            ans = max(ans,jury1[i][j]);
        }
    }
    
    cout<<ans<<'\n';


}