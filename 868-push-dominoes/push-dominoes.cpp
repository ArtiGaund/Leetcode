class Solution {
public:
    string pushDominoes(string dominoes) {
        int q[100000],F[100000];
        int front=0,back=0;
        const int n=dominoes.size();
        for(int i=0;i<n;i++){
            if(dominoes[i]!='.'){
                q[back++]=i;
                F[i]=n;
            }
        }
        for(int f=n;front<back;f--){
            int qz=back-front;
            for(int j=0;j<qz;j++){
                int i=q[front++];
                const char c=dominoes[i];
                if(c=='L'){
                    int next=i-1;
                    if(next<0) continue;
                    if(dominoes[next]=='.'){
                        dominoes[next]='L';
                        q[back++]=next;
                        F[next]=f-1;
                    }
                    else if(dominoes[next]=='R' and F[next]==f-1)
                    dominoes[next]='.';
                }
                else{
                    int next=i+1;
                    if(next>=n) continue;
                    if(dominoes[next]=='.'){
                        dominoes[next]='R';
                        q[back++]=next;
                        F[next]=f-1;
                    }
                    else if(dominoes[next]=='L' and F[next]==f-1)
                    dominoes[next]='.';
                }
            }
        }
        return dominoes;
    }
};