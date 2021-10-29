#include <stdio.h>
#include <queue>

using namespace std;

priority_queue < int > cola;
int aux, n;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &aux);
        if((int)cola.size() == n / 2 + 1){
            if(cola.top() > aux){
                cola.pop();
                cola.push(aux);
            }
        }
        else cola.push(aux);
    }
    if(n&1){
        printf("%d.0", cola.top());
    }
    else{
        long long u = cola.top();
        cola.pop();
        u += cola.top();
        printf("%lld", u / 2);
        if(u&1) printf(".5");
        else printf(".0");
    }
    return 0;
}
