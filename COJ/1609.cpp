#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1001];
void backtracking(int sum, int cant){
    if(sum == n){
        cout<<n<<" = ";
        cout<<arr[1]<<" ";
        for(int i = 2; i < cant; i++)
            cout<<"+ "<<arr[i]<<" ";
        cout<<"\n";
    }
    for(int i = arr[cant - 1]; i <= n; i++){
        if(sum + i <= n){
            arr[cant] = i;
            backtracking(sum + i, cant + 1);
            arr[cant] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--){
        cin>>n;
        arr[0] = 1;
        backtracking(0,1);
        if(t != 0)
            cout<<"\n";
    }
    return 0;
}
