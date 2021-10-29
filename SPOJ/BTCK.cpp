#include <bits/stdc++.h>

using namespace std;

long long z[11];
long long k;
bool visited[11];
int sol[11];
int cant;

void backtracking(long long suma, int pos){
    if(pos == 10){
        if(suma <= k && cant == 0){
            for(int i = 0; i < pos; i++)
                cout<<sol[i]<<" ", cant++;
        }
        return;
    }
    for(int i = 0; i <= 9; i++){
        if(!visited[i] && suma + (z[pos] * i) <= k && cant == 0){
            visited[i] = true;
            sol[pos] = i;
            backtracking(suma + (z[pos] * i), pos + 1);
            visited[i] = false;
            sol[pos] = 0;
        }
    }
}

int arr2[] = {2,6,8,9,7,5,4,3,1,0};

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        for(int i = 0; i < 10; i++){
            cin>>z[i];
        }
        cin>>k;
        backtracking(0,0);
        if(cant == 0)
            cout<<-1;
        cout<<"\n";
        cant = 0;
        fill(sol,sol+10,0);
    }
    return 0;
}
