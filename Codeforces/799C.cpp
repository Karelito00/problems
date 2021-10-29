#include <bits/stdc++.h>
#define mx(a,b) (a > b ? a : b)

using namespace std;

int const MAXn = 1e5 + 5,
            lg = log2(MAXn);

int n,c,d;

struct par{
    int cost,bty;
    bool operator < (const par &var) const {
        return var.cost > cost;
    }
}diam[MAXn],coins[MAXn];
int RMQC[MAXn][lg];
int RMQD[MAXn][lg];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>c>>d;
    int contc = 0, contd = 0;
    for(int i=0;i<n;i++){
        int b,cost1;
        char x;
        cin>>b>>cost1>>x;
        if((x == 'D' && cost1 > d) || (x == 'C' && cost1 > c))
            continue;
        if(x == 'D'){
            contd++;
            diam[contd] = par{cost1,b};
        }
        else{
            contc++;
            coins[contc] = par{cost1,b};
        }
    }
    sort(coins+1,coins+contc+1);
    sort(diam+1,diam+contd+1);
    for(int i=1;i<=contc;i++)
        RMQC[i][0] = coins[i].bty;
    for(int i=1;i<=contd;i++)
        RMQD[i][0] = diam[i].bty;
    for(int e=1;(1<<e)<=contc;e++){
        for(int i=1;i<=contc-(1<<e)+1;i++){
            RMQC[i][e] = mx(RMQC[i][e-1],RMQC[i+(1<<(e-1))][e-1]);
        }
    }
    for(int e=1;(1<<e)<=contd;e++){
        for(int i=1;i<=contd-(1<<e)+1;i++){
            RMQD[i][e] = mx(RMQD[i][e-1],RMQD[i+(1<<(e-1))][e-1]);
        }
    }

    long long best = -1;
    if(contc != 0 && contd != 0){
        int dist1 = log2(contc);
        int dist2 = log2(contd);
        best = mx(RMQC[1][dist1],RMQC[contc-(1<<dist1)+1][dist1]) + mx(RMQD[1][dist2],RMQD[contd-(1<<dist2)+1][dist2]);
    }
    for(int i=1;i<=contc;i++){
        int dif = c - coins[i].cost;
        int pos = upper_bound(coins+1,coins+contc+1,par{dif,0}) - coins - 1;
        if(pos < 1)
            continue;
        if(i <= pos){
            int fin = i - 1;
            if(fin > 0){
                int dist = log2(fin);
                best = mx(best,coins[i].bty+mx(RMQC[1][dist],RMQC[fin-(1<<dist)+1][dist]));
            }
            fin = i + 1;
            if(fin <= pos){
                int dist = log2(pos - fin + 1);
                best = mx(best,coins[i].bty+mx(RMQC[fin][dist],RMQC[pos-(1<<dist)+1][dist]));
            }
        }
        else{
            int dist = log2(pos);
            best = mx(best,coins[i].bty+mx(RMQC[1][dist],RMQC[pos-(1<<dist)+1][dist]));
        }
    }
    for(int i=1;i<=contd;i++){
        int dif = d - diam[i].cost;
        int pos = upper_bound(diam+1,diam+contd+1,par{dif,0}) - diam - 1;
        if(pos < 1)
            continue;
        if(i <= pos){
            int fin = i - 1;
            if(fin > 0){
                int dist = log2(fin);
                best = mx(best,diam[i].bty+mx(RMQD[1][dist],RMQD[fin-(1<<dist)+1][dist]));
            }
            fin = i + 1;
            if(fin <= pos){
                int dist = log2(pos - fin + 1);
                best = mx(best,diam[i].bty+mx(RMQD[fin][dist],RMQD[pos-(1<<dist)+1][dist]));
            }
        }
        else{
            int dist = log2(pos);
            best = mx(best,diam[i].bty+mx(RMQD[1][dist],RMQD[pos-(1<<dist)+1][dist]));
        }
    }
    cout<<(best == -1 ? 0 : best);
    return 0;
}
