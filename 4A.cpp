#include <iostream>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        int N,A,B,cur[1000001]={0},cnt=0;
        cin>>N;
        for(int i=0;i<N;i++){
            cin>>A;
            cur[A/30] |= (1<<(A%30));
        }
        for(int i=0;i<N;i++){
            cin>>B;
            if(!(cur[B/30]&(1<<(B%30)))){
                printf("%d ",B);
                cnt++;
            }
        }
        if(!cnt)printf("0");
        printf("\n");
    }
    return 0;
}
