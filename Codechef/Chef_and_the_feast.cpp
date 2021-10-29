#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        priority_queue < long long > cola;
        for(int i=0;i<n;i++){
            long long k;
            cin>>k;
            cola.push(k);
        }
        long long con = 0;
        long long suma = 0;
        while(!cola.empty()){
            long long v = cola.top();
            if(((suma + v) * (con + 1)) - (suma * con) < v)
                break;
            con++;
            suma += v;
            cola.pop();
        }
        suma *= con;
        while(!cola.empty()){
            suma += cola.top();
            cola.pop();
        }
        cout<<suma<<"\n";
    }
    return 0;
}
//Greedy Priority queue
