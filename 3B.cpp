#include <iostream>
#include <set>
using namespace std;

int emp[100001],doc[100001];

int parent(int n,int m){
    set <int> S;
    while(n!=1){
        S.insert(n);
        n=emp[n];
    }
    while(m!=1){
        if(S.count(m))break;
        m=emp[m];
    }
    return m;
}

int main(){
    std::ios::sync_with_stdio(false);
    int N,K;
    cin>>N>>K;
    for(int i=1;i<=N;i++) emp[i]=doc[i]=1;
    for(int i=0;i<K;i++){
        int r,a,b,c;
        cin>>r>>a>>b;
        if(r==1){       //documnet
            int c,p;
            cin>>c;
            p=parent(a,b);
            while(a!=p){
                doc[a]=c;
                a=emp[a];
            }
            while(b!=p){
                doc[b]=c;
                b=emp[b];
            }
        }else if(r==2){     //under
            emp[a]=b;
        }else{      //kinds
            int p = parent(a,b);
            set <int> S;
            while(a!=p){
                S.insert(doc[a]);
                a=emp[a];
            }
            while(b!=p){
                S.insert(doc[b]);
                b=emp[b];
            }
            printf("%d\n",(int)S.size());
        }
    }
    return 0;
}
