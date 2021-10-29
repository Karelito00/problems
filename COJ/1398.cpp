#include <bits/stdc++.h>
#define f first
#define s second
#define mp make_pair

using namespace std;

int const MAXn = 2e4 + 2;
typedef pair < int , int > par;

int automata[MAXn][3];
par from[MAXn][3];
bool visited[MAXn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        if(s == "1"){
            cout<<s<<"\n";
            continue;
        }
        int tm = s.size();
        int m = 0;
        for(int i = 0; i < tm; i++)
            m = (m * 10) + s[i] - '0';
        for(int i = 0; i < m; i++){
            automata[i][0] = (i * 10) % m;
            automata[i][1] = ((i * 10) + 1) % m;
        }
        queue < par > cola;
        cola.push(mp(1, 1));
        from[1][1] = mp(0, -1);
        bool sol = false;
        int state = 0, k = -1;
        while(!cola.empty()){
            par v = cola.front();
            cola.pop();
            for(int i = 0; i < 2; i++){
                int to = automata[v.f][i];
                if(visited[to]) continue;
                from[to][i] = v;
                if(to == 0){
                    sol = true;
                    state = to, k = i;
                    break;
                }
                visited[to] = true;
                cola.push(mp(to, i));
            }
            if(sol) break;
        }
        vector < int > num;
        while(k != -1){
            num.push_back(k);
            int aux = state;
            state = from[state][k].f;
            k = from[aux][k].s;
        }
        for(int i = num.size() - 1; i >= 0; i--) cout<<num[i];
        cout<<"\n";
        while(!cola.empty()) cola.pop();
        fill(visited, visited + m, 0);
        for(int i = 0; i < m; i++){
            automata[i][0] = automata[i][1] = 0;
            from[i][0] = from[i][1] = mp(0, 0);
        }
    }
    return 0;
}
