#include<cstdio>
using namespace std;
long long a,b,c,d,temp;
long long ans=0;
void solve(long long m,long long n){
    
}
int main(){
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;++i){
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        while(c>=a&&d>=b){
            if(c>d){
                temp=(c-a)/d;
                if(temp==0){
                    break;
                }
                c=c-temp*d;
                ans+=temp;
            }
            else{
                temp=(d-b)/c;
                if(temp==0){
                    break;
                }
                d=d-temp*c;
                ans+=temp;
            }
            if(c==a&&d==b){
                break;
            }
        }
        if(c==a&&d==b){
            printf("%lld\n",ans);
        }
        else{
            printf("-1\n");
        }
        ans=0;
    }
    return 0;
}