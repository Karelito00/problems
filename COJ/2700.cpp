#include <iostream>

using namespace std;

int main()
{
    string a,b;
    cin>>a>>b;
    string a1,b1,n;
    int m=0,l=0;
    for(int c=0;c<a.size();c++){
            int i=0;
       for(int d=0;d<b.size();d++){
        if(a[c]==b[d])
        i++;
    }
    if(i==0){
        a1[m]=a[c];
        m++;
    }
      i=0;
    }
    cout<<"First:";
for(int h=0;h<m;h++){
    cout<<a1[h];
}
for(int c=0;c<b.size();c++){
            int i=0;
       for(int d=0;d<a.size();d++){
        if(b[c]==a[d])
        i++;
    }
    if(i==0){
        b1[l]=b[c];
        l++;
    }
      i=0;
    }
    cout<<endl;
    cout<<"Second:";
for(int h=0;h<l;h++)
    cout<<b1[h];
    int r=0;
    for(int j=0;j<a.size();j++){
            int k=0;
        for(int u=0;u<b.size();u++){
            if(a[j]==b[u]){
                k++;
                break;
            }
        }
        if(k!=0){
            n[r]=a[j];
            r++;
        }
        k=0;
    }
    cout<<endl;
    cout<<"First&Second:";
    for(int j=0;j<r;j++)
        cout<<n[j];

    return 0;
}