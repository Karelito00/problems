#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e4 + 1;

char mat[MAXn][MAXn];

set < int > row[MAXn];
set < int > column[MAXn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin>>n>>m>>q;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>mat[i][j];
            if(mat[i][j] == 'X'){
                row[i].insert(j);
                column[j].insert(i);
            }
        }
    }
    while(q--){
        int x, y;
        char type;
        cin>>x>>y>>type;
        if(type == 't'){
            if(mat[x][y] == '.'){
                mat[x][y] = 'X';
                row[x].insert(y);
                column[y].insert(x);
            }
            else{
                mat[x][y] = '.';
                row[x].erase(y);
                column[y].erase(x);
            }
        }
        else if(type == 'e'){
            auto pos = row[x].lower_bound(y);
            if(pos == row[x].end())
                cout<<"No bad seeds found\n";
            else
                cout<<*pos - y<<"\n";
        }
        else if(type == 'w'){
            if(row[x].empty()){
                cout<<"No bad seeds found\n";
                continue;
            }
            auto pos = row[x].lower_bound(y);
            if(*pos != y && pos == row[x].begin())
                cout<<"No bad seeds found\n";
            else{
                if(*pos != y)
                    pos--;
                cout<<y - *pos<<"\n";
            }
        }
        else if(type == 's'){
            auto pos = column[y].lower_bound(x);
            if(pos == column[y].end())
                cout<<"No bad seeds found\n";
            else
                cout<<*pos - x<<"\n";
        }
        else if(type == 'n'){
            if(column[y].empty()){
                cout<<"No bad seeds found\n";
                continue;
            }
            auto pos = column[y].lower_bound(x);
            if(*pos != x && pos == column[y].begin())
                cout<<"No bad seeds found\n";
            else{
                if(*pos != x)
                    pos--;
                cout<<x - *pos<<"\n";
            }
        }
    }
    return 0;
}
