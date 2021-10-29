#include <bits/stdc++.h>

using namespace std;

char sol[25];
long long arr[25];
long long arr1[25];
int n;
int n1, n2;
long long total;
struct par{
    char s[13];
};

unordered_map < long long , par > mapa;

void backtracking1(int cant, long long suma){
    if(cant == n1 - 1 && mapa.find(suma) == mapa.end()){
        for(int i = 0; i < cant; i++)
            mapa[suma].s[i] = sol[i];
        return;
    }
    if(cant == n1 - 1)
        return;
    for(int i = 1; i <= 4; i++){
        if(i == 1){
            sol[cant] = '+';
            suma += arr[cant + 1];
        }
        else if(i == 2){
            sol[cant] = '-';
            suma -= arr[cant + 1];
        }
        else if(i == 3){
            sol[cant] = '.';
            suma += 2 * arr[cant + 1];
        }
        else if(i == 4){
            sol[cant] = '~';
            suma -= 2 * arr[cant + 1];
        }
        cant++;
        backtracking1(cant, suma);
        cant--;
        if(i == 1){
            sol[cant] = 0;
            suma -= arr[cant + 1];
        }
        else if(i == 2){
            sol[cant] = 0;
            suma += arr[cant + 1];
        }
        else if(i == 3){
            sol[cant] = 0;
            suma -= 2 * arr[cant + 1];
        }
        else if(i == 4){
            sol[cant] = 0;
            suma += 2 * arr[cant + 1];
        }
    }
}

void backtracking2(int cant, long long suma){
    if(cant == n2 - 1){
        if(mapa.find(total - (suma + arr1[0])) != mapa.end()){
            for(int i = 0; i < n1 - 1; i++)
                cout<<mapa[total - (suma + arr1[0])].s[i];
            cout<<"+";
            for(int i = 0; i < cant; i++)
                cout<<sol[i];
            exit(0);
        }
        if(mapa.find(total - (suma - arr1[0])) != mapa.end()){
            for(int i = 0; i < n1 - 1; i++)
                cout<<mapa[total - (suma - arr1[0])].s[i];
            cout<<"-";
            for(int i = 0; i < cant; i++)
                cout<<sol[i];
            exit(0);
        }
        if(mapa.find(total - (suma - (2 * arr1[0]))) != mapa.end()){
            for(int i = 0; i < n1 - 1; i++)
                cout<<mapa[total - (suma - (2 * arr1[0]))].s[i];
            cout<<"~";
            for(int i = 0; i < cant; i++)
                cout<<sol[i];
            exit(0);
        }
        if(mapa.find(total - (suma + (2 * arr1[0]))) != mapa.end()){
            for(int i = 0; i < n1 - 1; i++)
                cout<<mapa[total - (suma + (2 * arr1[0]))].s[i];
            cout<<".";
            for(int i = 0; i < cant; i++)
                cout<<sol[i];
            exit(0);
        }
        return;
    }
    for(int i = 1; i <= 4; i++){
        if(i == 1){
            sol[cant] = '+';
            suma += arr1[cant + 1];
        }
        else if(i == 2){
            sol[cant] = '-';
            suma -= arr1[cant + 1];
        }
        else if(i == 3){
            sol[cant] = '.';
            suma += 2 * arr1[cant + 1];
        }
        else if(i == 4){
            sol[cant] = '~';
            suma -= 2 * arr1[cant + 1];
        }
        cant++;
        backtracking2(cant, suma);
        cant--;
        if(i == 1){
            sol[cant] = 0;
            suma -= arr1[cant + 1];
        }
        else if(i == 2){
            sol[cant] = 0;
            suma += arr1[cant + 1];
        }
        else if(i == 3){
            sol[cant] = 0;
            suma -= 2 * arr1[cant + 1];
        }
        else if(i == 4){
            sol[cant] = 0;
            suma += 2 * arr1[cant + 1];
        }
    }
}

void backtracking3(int cant, long long suma){
    if(cant == n - 1){
        if(suma == total){
            for(int i = 0; i < cant; i++)
                cout<<sol[i];
            exit(0);
        }
        return;
    }
    if(cant == n - 1)
        return;
    for(int i = 1; i <= 4; i++){
        if(i == 1){
            sol[cant] = '+';
            suma += arr[cant + 1];
        }
        else if(i == 2){
            sol[cant] = '-';
            suma -= arr[cant + 1];
        }
        else if(i == 3){
            sol[cant] = '.';
            suma += 2 * arr[cant + 1];
        }
        else if(i == 4){
            sol[cant] = '~';
            suma -= 2 * arr[cant + 1];
        }
        cant++;
        backtracking3(cant, suma);
        cant--;
        if(i == 1){
            sol[cant] = 0;
            suma -= arr[cant + 1];
        }
        else if(i == 2){
            sol[cant] = 0;
            suma += arr[cant + 1];
        }
        else if(i == 3){
            sol[cant] = 0;
            suma -= 2 * arr[cant + 1];
        }
        else if(i == 4){
            sol[cant] = 0;
            suma += 2 * arr[cant + 1];
        }
    }
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>total;
    if(n <= 3){
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        backtracking3(0,arr[0]);
        cout<<"impossible";
        return 0;
    }
    n1 = n/2, n2 = n - n1;
    for(int i = 0; i < n/2; i++)
        cin>>arr[i];
    for(int i = 0; i < n2; i++)
        cin>>arr1[i];
    backtracking1(0,arr[0]);
    for(int i = 0; i < n; i++)
        sol[i] = '0';
    backtracking2(0,0);
    cout<<"Impossible";
    return 0;
}
