#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

struct cmp{
    bool operator () (const int &a, const int &b) const {
        return a > b;
    }
};

int arr1[55];
int arr2[55];
bool mark[55];
int match[55];
int match2[55];
int n, sol;

bool DFS(int v, bool hh){
    for(int i = 1; i <= n; i++){
        if(arr2[i] > arr1[v]) break;
        if(mark[i]) continue;
        if(arr2[i] < arr1[v]){
           mark[i] = true;
           if(!match[i] || DFS(match[i], hh)){
                if(!match2[v]) sol += 2;
                match[i] = v;
                match2[v] = i;
                return 1;
           }
        }
        else if(!hh){
            mark[i] = true;
            if(!match[i] || DFS(match[i], true)){
                if(match2[v]) sol--;
                else sol++;
                match[i] = v;
                return 1;
           }
        }
    }
    return 0;
}

void hungary(){
    for(int i = 1; i <= n; i++){
        DFS(i, false);
        fill(mark + 1, mark + n + 1, 0);
    }
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    for(int u = 1; u <= t; u++){
        cin>>n;
        for(int i = 1; i <= n; i++)
            cin>>arr1[i];
        for(int i = 1; i <= n; i++)
            cin>>arr2[i];
        sort(arr1 + 1, arr1 + n + 1, cmp());
        sort(arr2 + 1, arr2 + n + 1);
        hungary();
        cout<<"Case "<<u<<": "<<sol<<"\n";
        sol = 0;
        fill(match + 1, match + n + 1, 0);
        fill(match2 + 1, match2 + n + 1, 0);
    }
    return 0;
}
