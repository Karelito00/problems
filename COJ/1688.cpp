#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c=0;
    while(1){
        int a;
        cin>>a;
        if(a==-1)
            break;
        if(a==1){
                if(c!=0)
                cout<<"\n";
            int b,tas=1;
            cin>>b;
            int space=b-1;
            for(int r=0;r<b;r++){
                for(int s=0;s<space;s++){
                    cout<<" ";
                }
                for(int asd=0;asd<tas;asd++){
                    cout<<"*";
                }
                tas+=2;
                space+=-1;
                cout<<"\n";

            }
        }
       else if(a==2){
                if(c!=0)
                cout<<"\n";
            int c,d;
            cin>>c>>d;
            int espa=d-1;
            for(int h=0;h<d;h++){
                for(int u=0;u<espa;u++){
                    cout<<" ";
                }
                for(int g=0;g<c;g++){
                    cout<<"*";
                }
                cout<<"\n";
                espa+=-1;
            }

        }
        else if(a==3){
                if(c!=0)
                cout<<"\n";
            int e,f;
            cin>>e>>f;
            for(int j=0;j<f;j++){
                for(int h=0;h<e;h++){
                    cout<<"*";
                }
                cout<<"\n";
            }

        }
        c=1;

    }
    return 0;
}
