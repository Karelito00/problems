    #include <stdio.h>
    #define mx(a,b) (a > b ? a : b)
     
    int main()
    {
        int t;
        scanf("%d",&t);
        while(t--){
            int n;
            scanf("%d",&n);
            int best = n;
            for(int i=1;i<=n-1;i++){
                int l;
                scanf("%d",&l);
                best = mx(best,l + i);
            }
            for(int i=1;i<=n-1;i++){
                int l;
                scanf("%d",&l);
                best = mx(best,l + i);
            }
            printf("%d\n",best);
        }
        return 0;
    }
