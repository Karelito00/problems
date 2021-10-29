#include <bits/stdc++.h>

using namespace std;

int const MAXn = 1e6 + 10;
int n;
long long arr[MAXn];

string game(){
    int cantimp = 0;
    bool par = false;
    for(int i = 0; i < n; i++){
        if(arr[i] % 2 != 0){
            cantimp++;
        }
        else
            par = true;
    }
    if(cantimp == 0)
        return "Second";
    if(cantimp % 2 != 0)
        return "First";
    if(cantimp % 2 == 0 && !par)
        return "First";
    return "First";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    cout<<game();
    return 0;
}
