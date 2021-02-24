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
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        deque<int> q;
        vector<bool> places(n+1);
        
        int first = n;
        for(int i=n-1;i>=0;i--){
            if(a[i]==first){
                q.push_front(a[i]);
                places[a[i]]=true;
                bool v = false;
                for(int j=first;j>=1;j--){
                    if(places[j]==false){
                        first=j;
                        v=true;
                        break;
                    }
                    
                }
                if(!v)break;
                while(!q.empty()){
                    cout<<q.front()<<" ";
                    q.pop_front();
                }
                continue;
            }
            q.push_front(a[i]);
            places[a[i]]=true;
        }
        while(!q.empty()){
            cout<<q.front()<<" ";
            q.pop_front();
        }
        cout<<'\n';
    }

}