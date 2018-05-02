#include <iostream>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    int T,K,C,A,B;
    cin>>T;
    while(T--){
        bool dp[501][501]={0};
        cin>>K>>C;
        for(int i=0;i<=K;i++){
            for(int j=0;j<=K;j++){
                if(i>j+(K-i+2))dp[i][j]=1;
                if(j>i+(K-j+1))dp[i][j]=1;
            }
        }
        for(int i=0;i<C;i++){
            cin>>A>>B;
            if(dp[A][B]==1)printf("0\n");
            else printf("1\n");
        }
    }
    return 0;
}
