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
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    while(n--){
        short sum = 0;
        for(int i = 0; i < 5; i++){
            bool aux;
            cin>>aux;
            if(aux) sum++;
        }
        if(sum == 0)
            cout<<"Beginner";
        else if(sum == 1)
            cout<<"Junior Developer";
        else if(sum == 2)
            cout<<"Middle Developer";
        else if(sum == 3)
            cout<<"Senior Developer";
        else if(sum == 4)
            cout<<"Hacker";
        else
            cout<<"Jeff Dean";
        cout<<"\n";
    }
    return 0;
}
