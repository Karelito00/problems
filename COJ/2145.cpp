#include <cstdio>
#include <algorithm>

using namespace std;
int z[10];
int main()
{
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        for(int y=0;y<10;y++){
            scanf("%d",&z[y]);
        }
        sort(z,z+10);
        int suma=0;
        for(int y=1;y<9;y++){
            suma+=z[y];
        }
        printf("%d %d\n",i+1,suma);
    }
    return 0;
}
