#include <bits/stdc++.h>

using namespace std;

int const MAXn = 1e5 + 10;

char a[MAXn];

int main()
{
    //freopen(".in","r",stdin);
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%s",&a[1]);
        int len = strlen(&a[1]);
        int suma = 0;
        for(int i = 1; i <= len; i++)
            suma += (a[i] - 48);
        if(a[len] % 2){
            if((suma - a[len] + 48) % 3 == 0 && a[len - 1] % 2 == 0){
                a[len] = 0;
                printf("%s", &a[1]);
            }
            else
                printf("-1");
        }
        else{
            bool found = false;
            for(int i = 1; i < len; i++){
                if(a[i] < a[i + 1] && (suma - a[i] + 48) % 3 == 0){
                    found = true;
                    a[i] = 0;
                    printf("%s%s",&a[1], &a[i + 1]);
                    break;
                }
            }
            if(!found){
                if((a[len - 1] % 2) + ((suma - a[len] + 48) % 3) == 0){
                    found = true;
                    a[len] = 0;
                    printf("%s", &a[1]);
                }
                else{
                    for(int i = len - 1; i >= 1; i--){
                        if((suma - a[i] + 48) % 3 == 0){
                            found = true;
                            a[i] = 0;
                            printf("%s%s", &a[1], &a[i + 1]);
                            break;
                        }
                    }
                }
                if(!found)
                    printf("-1");
            }
        }
        printf("\n");
    }
    return 0;
}

