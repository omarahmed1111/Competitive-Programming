#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())
vector<vector<pair<ll,ll>>> comp;

struct node{
    int type;
    ll price;
    ll quality;
    node(int a, ll b, ll c){
        type=a, price = b, quality=c;
    }
    bool operator<(node &b){
        return quality < b.quality;
    }
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    int t;
    cin>>t;
    while(t--){
        comp.clear();
        map<string, vector<pair<ll,ll>>> g;
        int n;
        ll budget;
        cin>>n>>budget;
        for(int i=0;i<n;i++){
            string type,name;
            ll price, quality;
            cin>>type>>name>>price>>quality;
            g[type].push_back({price, quality});            
        }
        for(auto component: g){
            comp.push_back(component.second);
        }
        int tot_types = comp.size();   
        map<int, int> computer;  // type --> price
        vector<node> total;
        for(int i=0;i<comp.size();i++){
            for(int j=0;j<comp[i].size();j++){
                total.push_back(node(i, comp[i][j].first, comp[i][j].second));
            }
        }
        sort(all(total));
        reverse(all(total));
        ll quality = LONG_LONG_MAX;
        for(int i=0;i<total.size();i++){
            node cur = total[i];
            if(computer[cur.type] > cur.price || computer[cur.type]==0){
                budget = budget + computer[cur.type] - cur.price;
                computer[cur.type] = cur.price;
            }

            if(computer.size()==tot_types&&budget>0){
                quality = cur.quality;
                break;
            }
        }
        cout<<quality<<'\n';

    }


}

/*
1
18 800
processor 3500_MHz 66 5
processor 4200_MHz 103 7
processor 5000_MHz 156 9
processor 6000_MHz 219 12
memory 1_GB 35 3
memory 2_GB 88 6
memory 4_GB 170 12
mainbord all_onboard 52 10
harddisk 250_GB 54 10
harddisk 500_FB 99 12
casing midi 36 10
monitor 17_inch 157 5
monitor 19_inch 175 7
monitor 20_inch 210 9
monitor 22_inch 293 12
mouse cordless_optical 18 12
mouse microsoft 30 9
keyboard office 4 10
*/