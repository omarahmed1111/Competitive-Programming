#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define all(v)   (v.begin()),(v.end())

//get a vector of prime factorization
pair<vector<int>, map<int,int>> primeFactors(int n)
{
	vector<int> a;
    map<int,int> taken;
	// Print the number of 2s that divide n
	while (n % 2 == 0)
	{
		if(taken[2]==0)a.push_back(2);
        taken[2]++;
        
		n = n / 2;
	}

	// n must be odd at this point.  So we can skip
	// one element (Note i = i +2)
	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		// While i divides n, print i and divide n
		while (n%i == 0)
		{
			if(taken[i]==0)a.push_back(i);
            taken[i]++;
			n = n / i;
		}
	}

	// This condition is to handle the case when n
	// is a prime number greater than 2
	if (n > 2){
		a.push_back(n);
        taken[n]++;
    }
	return {a, taken};
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();
	cout.tie();
    int t;
    cin>>t;
    for(int c=1;c<=t;c++){
        int m;
        cin>>m;
        vector<pair<int,int>> p(m);
        map<int,int> have;
        for(int i=0;i<m;i++){
            cin>>p[i].first>>p[i].second;
            have[p[i].first] = p[i].second;
        }
        ll sum = 0;
        for(int i=0;i<m;i++)sum+= p[i].first*p[i].second;
        int ans = 0;
        for(int i=2;i<=sum;i++){
            pair<vector<int>, map<int,int>> a = primeFactors(i);
            bool v = false;
            int sum2 = 0;
            for(int j=0;j<a.first.size();j++){
                sum2 += a.first[j] * a.second[a.first[j]];
                if(a.second[a.first[j]] > have[a.first[j]]){
                    v=true;
                    break;
                }
            }
            
            
            if(!v && i==sum-sum2){
                ans = i;
            }
        }
        cout<<"Case #"<<c<<": "<<ans<<'\n';
    }


}