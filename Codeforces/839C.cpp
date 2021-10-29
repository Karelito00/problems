#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
const int MAXn = 1e6 + 10;

int n;
vector < int > adya[MAXn];

ld dfs(int v = 0, int p = -1){
	ld sum = 0;
	for(auto to: adya[v])
		if(to != p)
			sum += dfs(to, v) + 1;
	return sum ? (sum / (adya[v].size() - (p != -1))) : 0;
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i = 1; i < n; i++){
		int n1, n2;
		cin>>n1>>n2;
		n1--, n2--;
		adya[n1].push_back(n2);
		adya[n2].push_back(n1);
	}
	cout<<fixed<<setprecision(6)<<dfs();
	return 0;
}
