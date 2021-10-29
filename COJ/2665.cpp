#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

priority_queue < int , vector < int > , greater < int > > rang;

struct cat{
    int ini;
    int fin;
    bool operator < (const cat &var) const {
        if(var.ini != ini)
            return var.ini > ini;
        return var.fin > fin;
    }
}arr[42501];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    while(cin>>n>>m){
        int total = n + m;
        int sol = 0;
        for(int i = 0; i < n; i++)
            cin>>arr[i].ini>>arr[i].fin;

        for(int j = n; j < total; j++){
            cin>>arr[j].ini;
            arr[j].fin = 1002;
        }
        sort(arr, arr + total);
        // SWEEP LINE
        for(int i = 0; i < total; i++){
            if(arr[i].fin != 1002)
                rang.push(arr[i].fin);
            else{
                while(!rang.empty() && rang.top() < arr[i].ini)
                    rang.pop();
                if(!rang.empty()){
                    sol++;
                    rang.pop();
                }
            }
        }
        cout<<sol<<"\n";
        while(!rang.empty()) rang.pop();
    }
    return 0;
}
