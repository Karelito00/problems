#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int const MAXn = 1e5 + 2;

char sol[MAXn];
queue < int > cola[27];
int cant[27];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        fill(cant, cant + 26, 0);
        string s;
        cin>>s;
        int mark = 0;
        int n = s.size();
        for(int i = 0; i < n; i++){
            cola[s[i] - 'a'].push(i + 1);
            cant[s[i] - 'a']++;
        }
        int id = -1;
        for(int i = 0; i <= 25; i++)
            if(cant[i]&1) mark++, id = i;
        if(mark >= 2){
            cout<<-1<<"\n";
            for(int i = 0; i <= 25; i++)
                while(!cola[i].empty()) cola[i].pop();
            continue;
        }
        int con = 1;
        for(int i = 0; i <= 25; i++){
            int aux = cant[i] / 2;
            while(aux--){
                sol[con] = (char)(i + 'a');
                sol[n - con + 1] = sol[con];
                con++;
            }
        }
        if(id != -1) sol[n / 2 + 1] = id + 'a';
        for(int i = 1; i <= n; i++){
            cout<<cola[sol[i] - 'a'].front()<<" ";
            cola[sol[i] - 'a'].pop();
        }
        cout<<"\n";
        fill(sol + 1, sol + n + 1, 0);
    }
    return 0;
}
