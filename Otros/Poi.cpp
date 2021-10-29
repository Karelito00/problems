#include <bits/stdc++.h>

using namespace std;

int arr[2001];
bool mat[2001][2001];
class Elements{
public:
    int id;
    int tar;
    int points;
    Elements(int id1,int tar1,int points1){
        tar=tar1;
        id=id1;
        points=points1;
    }
    Elements(){}
    bool operator < (const Elements& hola)const{
        if(hola.points!=points)
            return hola.points < points;
        else if(tar != hola.tar)
            return hola.tar < tar;
        else
            return hola.id > id;
    }
};

Elements z[2001];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,t,p;
    cin>>n>>t>>p;
    for(int i=0;i<n;i++){
        for(int j=0;j<t;j++){
            cin>>mat[i][j];
            if(mat[i][j]==false)
                arr[j]++;
        }
    }
    for(int i=0;i<n;i++){
        int suma=0;
        int con=0;
        for(int j=0;j<t;j++){
            if(mat[i][j]){
                suma += arr[j];
                con++;
            }
        }
        z[i]=Elements(i+1,con,suma);
    }
    sort(z,z+n);
    for(int i=0;i<n;i++){
        if(p == z[i].id){
            cout<<z[i].points<<" "<<i+1;
            break;
        }
    }
    return 0;
}