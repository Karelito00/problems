#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

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
        int a, b;
        cin>>a>>b;
        int canta = 0, cantb = 0;
        for(auto x: s)
            (x == 'a' ? canta++ : cantb++);
        int x = 0;
        int y = 0;
        string t = "";
        int i = 0;
        while(canta > 0 && cantb > 0){
            if(canta > cantb){
                if(x < a){
                    t.push_back('a');
                    canta--;
                    x++;
                }
                else if(y < b){
                    t.push_back('b');
                    cantb--;
                    y++;
                }
                else
                    t.push_back('*');
            }
            else{
                if(y < b){
                    t.push_back('b');
                    cantb--;
                    y++;
                }
                else if(x < a){
                    t.push_back('a');
                    canta--;
                    x++;
                }
                else
                    t.push_back('*');
            }
            i++;
            if(i > a){
                if(t[i - a - 1] == 'a')
                    x--;
            }
            if(i > b){
                if(t[i - b - 1] == 'b')
                    y--;
            }
        }
        while(canta > 0){
            if(x < a){
                t.push_back('a');
                canta--;
                x++;
            }
            else
                t.push_back('*');
            i++;
            if(i > a){
                if(t[i - a - 1] == 'a')
                    x--;
            }
        }
        while(cantb > 0){
            if(y < b){
                t.push_back('b');
                cantb--;
                y++;
            }
            else
                t.push_back('*');
            i++;
            if(i > b){
                if(t[i - b - 1] == 'b')
                    y--;
            }
        }
        cout<<t<<"\n";
    }
    return 0;
}
