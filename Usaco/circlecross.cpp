#include <bits/stdc++.h>

using namespace std;

int const MAXn = 5e4 + 10, TB = sqrt(MAXn * 2);
int arr[MAXn * 2];
int f[MAXn];
struct query{
    int l;
    int r;
    bool operator < (const query &var) const {
        return (var.l / TB != l / TB ? var.l / TB > l / TB : var.r > r);
    }
}mo[MAXn];

long long num;
long long sol;

void up(int id, int k){
    f[id] += k;
    (f[id] == 1 ? num++ : num--);
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    freopen("main.in", "r", stdin);
    freopen("main.out", "w", stdout);
	int n;
	cin>>n;
	for(int i = 1; i <= n * 2; i++){
        cin>>arr[i];
        if(!f[arr[i]]){
            f[arr[i]]++;
            mo[arr[i]].l = i;
        }
        else{
            f[arr[i]]--;
            mo[arr[i]].r = i;
        }
	}
	sort(mo + 1, mo + n + 1);
	int l = 1;
	int r = 0;
	for(int i = 1; i <= n; i++){
        int nl = mo[i].l, nr = mo[i].r;
        while(r < nr) up(arr[++r], 1);
        while(l < nl) up(arr[l++], -1);
        while(r > nr) up(arr[r--], -1);
        while(l > nl) up(arr[--l], 1);
        sol += num;
	}
	cout<<sol / 2;
	return 0;
}
