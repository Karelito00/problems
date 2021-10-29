#include <bits/stdc++.h>
#define mn(a,b) (a < b ? a : b)
#define mx(a,b) (a > b ? a : b)
#define f first
#define s second
#define mp make_pair
#define all(v) (v).begin(),(v).end()

using namespace std;

int kth[205][205][502];
int mat[205][205];
int cant[205][205];
int p[] = {1, 0, -1};
priority_queue < int > cola;
int arr[502];

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin>>n>>m>>k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            cin>>mat[i][j];
    }
    for(int i = 1; i <= m; i++){
        kth[1][i][0] = mat[1][i];
        cant[1][i] = 1;
    }
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= m; j++){
            int c1 = 0, c2 = 0, c3 = 0;
            while((c1 < cant[i - 1][j + p[0]] || c2 < cant[i - 1][j + p[1]] || c3 < cant[i - 1][j + p[2]]) && cant[i][j] < k){
                int id = -1, num = INT_MAX;
                if(c1 < cant[i - 1][j + p[0]] && num > kth[i - 1][j + p[0]][c1]){
                    id = 1;
                    num = kth[i - 1][j + p[0]][c1];
                }
                if(c2 < cant[i - 1][j + p[1]] && num > kth[i - 1][j + p[1]][c2]){
                    id = 2;
                    num = kth[i - 1][j + p[1]][c2];
                }
                if(c3 < cant[i - 1][j + p[2]] && num > kth[i - 1][j + p[2]][c3]){
                    id = 3;
                    num = kth[i - 1][j + p[2]][c3];
                }
                kth[i][j][cant[i][j]++] = num + mat[i][j];
                if(id == 1) c1++;
                else if(id == 2) c2++;
                else c3++;
            }
        }
    }
    for(int i = 1; i <= m; i++){
        int c = 0;
        while(c < cant[n][i]){
            if((int)cola.size() == k){
                if(cola.top() > kth[n][i][c]){
                    cola.pop();
                    cola.push(kth[n][i][c]);
                }
                c++;
                continue;
            }
            cola.push(kth[n][i][c]);
            c++;
        }
    }
    int con = k;
    while(!cola.empty()){
        arr[con--] = cola.top();
        cola.pop();
    }
    for(int i = 1; i <= k; i++) cout<<arr[i]<<" ";
    return 0;
}
