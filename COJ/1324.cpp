#include <bits/stdc++.h>

using namespace std;
int z[12];
int o[12];
int main()
{

    for(int y=0;y<9;y++){
        int h;
        cin>>h;
        z[y]=h;
    }

      for(int q=0;q<9;q++){
     for(int w=q+1;w<9;w++){
     for(int e=w+1;e<9;e++){
     for(int r=e+1;r<9;r++){
     for(int t=r+1;t<9;t++){
     for(int y=t+1;y<9;y++){
     for(int i=y+1;i<9;i++){
        if(z[q]+z[w]+z[e]+z[r]+z[t]+z[y]+z[i]==100){
            o[0]=z[q];
            o[1]=z[w];
            o[2]=z[e];
            o[3]=z[r];
            o[4]=z[t];
            o[5]=z[y];
            o[6]=z[i];
        }

    }
    }
    }
    }
    }
    }
    }

    sort(o,o+7);
    for(int v=0;v<7;v++)
        cout<<o[v]<<endl;

    return 0;
}
