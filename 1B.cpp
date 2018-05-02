#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        int p,n,coin[501],dp[10001];
        cin>>p>>n;
        p=10000-p;
        for(int i=1;i<=n;i++)cin>>coin[i];
        dp[0]=0;
        for(int i=1;i<=p;i++)dp[i]=10001;
        for(int i=1;i<=n;i++){
            for(int j=coin[i];j<=p;j++){
                dp[j]=min(dp[j],dp[j-coin[i]]+1);
            }
        }
        if(dp[p]==10001)printf("0\n");
        else printf("%d\n",dp[p]);
    }
    return 0;
}
