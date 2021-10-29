#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
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
        int tm = s.size();
        int canta = 0, cantb = 0;
        int posa = -1, posb = -1;
        for(int i = 0; i < tm; i++){
            if(s[i] == 'A'){
                canta++;
                if(posa != -1)
                    canta += (i - posa) - 1;
                posb = -1;
                posa = i;
            }
            else if(s[i] == 'B'){
                cantb++;
                if(posb != -1)
                    cantb += (i - posb) - 1;
                posa = -1;
                posb = i;
            }
        }
        cout<<canta<<" "<<cantb<<"\n";
    }
    return 0;
}
