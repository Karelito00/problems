#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()

using namespace std;

string s, t;
char SOLVE(){
    int tam = (int)s.size();
    /* Caso 1 */
    for(int i = 0; i < tam; i++){
        if(!binary_search(all(t),s[i]))
            break;
        else if(i == tam - 1)
            return 'B';
    }
    for(int i = 0; i < tam; i++){
        if(!binary_search(all(s),t[i]))
            break;
        else if(i == tam - 1)
            return 'A';
    }
    /* Fin Caso 1 */
    /* Caso 2 */
    int con = 1;
    for(int i=1;i<tam;i++){
        if(s[i] == s[i - 1]){
            con++;
        }
        else{
            if(con > 1 && !binary_search(all(t),s[i-1]))
                return 'A';
            con = 1;
        }
    }
    if(con > 1 && !binary_search(all(t),s[tam-1]))
        return 'A';
    /* Fin Caso 2 */
    return 'B';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c;
    cin>>c;
    while(c--){
        cin>>s>>t;
        sort(all(s));
        sort(all(t));
        cout<<SOLVE()<<"\n";
    }
    return 0;
}
