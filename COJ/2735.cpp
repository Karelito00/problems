#include <bits/stdc++.h>

using namespace std;

int z[7],x[7],w[7],p[7];

int main()
{
    for(int i=0;i<7;i++){
        cin>>z[i]>>x[i]>>w[i];
        p[i]=i+1;
    }
    for(int i=0;i<7;i++){
        for(int j=i+1;j<7;j++){
                int m;
            if(z[i]==z[j]){
                if(x[i]==x[j]){
                    if(w[i]==w[j]){
                        if(p[i]>p[j]){
                            m=p[i];
                            p[i]=p[j];
                            p[j]=m;
                            m=z[i];
                            z[i]=z[j];
                            z[j]=m;
                            m=x[i];
                            x[i]=x[j];
                            x[j]=m;
                            m=w[i];
                            w[i]=w[j];
                            w[j]=m;
                        }
                    }else if(w[i]<w[j]){
                            m=p[i];
                            p[i]=p[j];
                            p[j]=m;
                            m=z[i];
                            z[i]=z[j];
                            z[j]=m;
                            m=x[i];
                            x[i]=x[j];
                            x[j]=m;
                            m=w[i];
                            w[i]=w[j];
                            w[j]=m;
                    }
                }else if(x[i]<x[j]){
                            m=p[i];
                            p[i]=p[j];
                            p[j]=m;
                            m=z[i];
                            z[i]=z[j];
                            z[j]=m;
                            m=x[i];
                            x[i]=x[j];
                            x[j]=m;
                            m=w[i];
                            w[i]=w[j];
                            w[j]=m;
                }
            }else if(z[i]<z[j]){
                            m=p[i];
                            p[i]=p[j];
                            p[j]=m;
                            m=z[i];
                            z[i]=z[j];
                            z[j]=m;
                            m=x[i];
                            x[i]=x[j];
                            x[j]=m;
                            m=w[i];
                            w[i]=w[j];
                            w[j]=m;
            }
        }
    }
    for(int u=0;u<7;u++){
        cout<<"Facultad "<<p[u]<<" "<<z[u]<<" "<<x[u]<<" "<<w[u]<<"\n";
    }
    return 0;
}
