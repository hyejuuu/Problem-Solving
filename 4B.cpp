#include <iostream>
#include <queue>
using namespace std;


int main(){
    std::ios::sync_with_stdio(false);
    int T;
    cin>>T;
    while(T--){
        int S,N,M;
        int cnt=0;
        queue <int> A,B,A1,B1;
        cin>>S>>N>>M;
        for(int i=0;i<N;i++){
            int in;
            cin>>in;
            A.push(in);
        }
        for(int i=0;i<N;i++){
            int sum=0;
            for(int j=0;j<N;j++){
                sum+=A.front();
                A.push(A.front());
                A.pop();
                if(sum==S){
                    cnt++;
                    continue;
                }else if(sum>S)continue;
                A1.push(sum);
            }
            A.push(A.front());
            A.pop();
        }
        for(int i=0;i<M;i++){
            int in;
            cin>>in;
            B.push(in);
        }
        for(int i=0;i<M;i++){
            int sum=0;
            for(int j=0;j<M;j++){
                sum+=B.front();
                B.push(B.front());
                B.pop();
                if(sum==S){
                    cnt++;
                    continue;
                }else if(sum>S)continue;
                B1.push(sum);
            }
            B.push(B.front());
            B.pop();
        }
        while(!A1.empty()){
            for(int i=0;i<B1.size();i++){
                if(A1.front()+B1.front()==S) cnt++;
                B1.push(B1.front());
                B1.pop();
            }
            A1.pop();
        }
        if(!cnt)printf("0\n");
        else printf("%d\n",cnt);
    }
    return 0;
}
