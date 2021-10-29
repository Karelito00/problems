#include <bits/stdc++.h>

using namespace std;

int x[1001];
int y[1001];
int arr[1001];
bool x1[1001];
bool yy1[1001];
bool ar[1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i];
        x1[x[i]] = true;
    }
    for(int i=0;i<n;i++){
        cin>>y[i];
        if(y[i]==x[i])
            arr[i] = y[i], ar[arr[i]] = true;
        yy1[y[i]] = true;
    }
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            if(ar[x[i]] == 0 && ar[y[i]] == 1)
                arr[i] = x[i], ar[x[i]] = true;
            else if(ar[y[i]] == 0 && ar[x[i]] == 1)
                arr[i] = y[i], ar[y[i]] = true;
            else if(ar[y[i]] == 0 && ar[x[i]] == 0){
                int num1 = 0, num2 = 0;
                for(int z=i+1;z<n;z++){
                    if(x[z] == x[i])
                        num1++;
                    if(y[z] == y[i])
                        num2++;
                }
                if(num1 < num2){
                    arr[i] = x[i], ar[x[i]] = true;
                }
                else
                    arr[i] = y[i], ar[y[i]] = true;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i] == false){
            for(int j=0;j<n;j++){
                if(ar[j+1] == false){
                    ar[j+1] = true;
                    arr[i] = j + 1;
                    break;
                }
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
