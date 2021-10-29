#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()

using namespace std;

bool primo(int n){
    if(n == 2)
        return true;
    if(n % 2 == 0)
        return false;
    for(int i = 3; i * i <= n ; i += 2)
        if(n % i == 0)
            return false;
    return true;
}
vector < int > primos;

bool visited[20];
int arr[21];
int n;

void backtracking(int cant){
    if(cant == n && binary_search(all(primos),arr[cant - 1] + 1)){
        for(int i = 0; i < n; i++)
            cout<<arr[i]<<" ";
        cout<<"\n";
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!visited[i] && binary_search(all(primos),arr[cant - 1] + i)){
            arr[cant] = i;
            visited[i] = true;
            backtracking(cant + 1);
            visited[i] = false;
            arr[cant] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i = 2; i <= 30; i++)
        if(primo(i))
            primos.push_back(i);
    int t;
    cin>>t;
    for(int i = 1; i <= t; i++){
        cin>>n;
        cout<<"Case "<<i<<":\n";
        arr[0] = 1;
        visited[1] = true;
        backtracking(1);
    }
    return 0;
}
