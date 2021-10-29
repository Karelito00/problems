#include <bits/stdc++.h>

using namespace std;
int z[1001];
int b[10001];
int y[10001];
int main()
{
    int a;
    cin>>a;
    for(int o=0;o<a;o++){
        cin>>z[o];
    }
    sort(z,z+a);
    int q1 ,q2;
    cin>>q1>>q2;
    for(int i=0;i<q1;i++){
        cin>>b[i];
    }
    for(int i=0;i<q2;i++){
        cin>>y[i];
    }
    for(int l=0;l<q1;l++){
            int c=0;
        for(int t=0;t<a;t++){
            if(b[l]==z[t]){
                    c++;
            break;
            }
        }
    if(c>=1)
                cout<<":)\n";
            else
                cout<<":(\n";
    }
    for(int r=0;r<q2;r++){
        cout<<z[y[r]-1]<<"\n";
    }
    return 0;
}
