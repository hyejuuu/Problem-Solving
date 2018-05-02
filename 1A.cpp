#include <iostream>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        int p,n,coin[14]={0},cnt=0;
        cin>>p>>n;
        p=10000-p;
        for(int i=0;i<n;i++)cin>>coin[i];
        for(int i=n-1;i>=0;i--){
            cnt+=p/coin[i];
            p=p%coin[i];
        }
        if(p!=0)printf("0\n");
        else printf("%d\n",cnt);
    }
    return 0;
}
