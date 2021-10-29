#include <bits/stdc++.h>

using namespace std;

int n;
int ABI[1050][1050];
int ult_val[1050][1050];

void update(int x, int y, int val){
    for(int i = x;i <= n;i += (i&-i)){
        for(int j = y;j <= n;j += (j&-j)){
            ABI[i][j] += val;
        }
    }
}

int query(int x,int y){
    int sum = 0;
    for(int i = x;i > 0;i -= (i&-i)){
        for(int j = y;j > 0;j -= (j&-j)){
            sum += ABI[i][j];
        }
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)
            fill(ABI[i]+1,ABI[i]+1+n,0), fill(ult_val[i]+1,ult_val[i]+1+n,0);
        while(1){
            string s;
            cin>>s;
            if(s == "END")
                break;
            if(s == "SET"){
                int x, y, val;
                cin>>x>>y>>val;
                x++, y++;
                update(x,y,val-ult_val[x][y]);
                ult_val[x][y] = val;
            }
            else{
                int x1,y1,x2,y2;
                cin>>x1>>y1>>x2>>y2;
                x1++, y1++, x2++, y2++;
                cout<<query(x2,y2) - query(x1-1,y2) - query(x2,y1-1) + query(x1-1,y1-1)<<"\n";
            }
        }
    }
    return 0;
}
