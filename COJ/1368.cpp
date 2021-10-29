#include <bits/stdc++.h>

using namespace std;

int p[11];
vector < pair <int,int> > coord;
float mat[11][11];
int main()
{
        int a;
        scanf("%d",&a);
        for(int i=0;i<a;i++){
            int y,x;
            scanf("%d %d",&y,&x);
            coord.push_back(make_pair(y,x));
        }
        for(int i=0;i<a-1;i++){
            double y1=(double)coord[i].first,x1=(double)coord[i].second;
            for(int j=i+1;j<a;j++){
            double y2=(double)coord[j].first,x2=(double)coord[j].second;
            double dist=sqrt(((y2-y1)*(y2-y1))+((x2-x1)*(x2-x1)));
            mat[i+1][j+1]=dist;
            mat[j+1][i+1]=dist;
        }
        }
        float suma=99999;
        int o=a/2;
        p[0]=o;
        int con=1;
        for(int i=0;i<a;i++){
            if(p[0]!=i+1){
                p[con]=i+1;
                con++;
            }
        }
        do{
            float best=0;
            for(int y=1;y<a;y++){
                best+=mat[p[y-1]][p[y]];
            }
            suma=min(suma,best);
        }while(next_permutation(p,p+a));

    printf("%.2f\n",suma);
    return 0;
}
