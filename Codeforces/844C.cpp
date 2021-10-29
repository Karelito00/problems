#include <bits/stdc++.h>

using namespace std;

int const MAXn = 1e5;

int n;
int arr[MAXn + 10];
int org[MAXn + 10];
bool marc[MAXn + 10];

vector < int > sub[MAXn];

int funt(int ult){
    for(;ult < n; ult++)
        if(!marc[ult])
            return ult;
    return n;
}

int main()
{
    //freopen(".in","r",stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++)
        cin>>arr[i], org[i] = arr[i];
    sort(arr, arr + n);
    int cant = 0;
    int pos = 0;
    int ult = 0;
    for(;ult < n; ult++){
        if(marc[ult])
            continue;
        while(1){
            marc[pos] = true;
            pos = lower_bound(arr, arr + n, org[pos]) - arr;
            sub[cant].push_back(pos);
            if(marc[pos]){
                cant++;
                pos = funt(ult + 1);
                ult = pos - 1;
                break;
            }
        }
    }
    cout<<cant<<"\n";
    for(int i = 0; i < cant; i++){
        cout<<sub[i].size()<<" ";
        for(auto x: sub[i])
            cout<<x + 1<<" ";
        cout<<"\n";
    }
    return 0;
}
