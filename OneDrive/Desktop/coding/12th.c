#include<stdio.h>
#include<stdlib.h>
int q[50],rear=-1,font=-1,bvisted[50];
int s[50],top=-1,dvisted[50];
int mat[50][50],n;
void bfs(int start){
    int cur,i;
    bvisted[start]=1;
    q[++rear]=start;
    while(font!=rear){
        cur=q[++font];
        for(i=1;i<=n;i++){
            if(mat[cur][i]==1 &&  bvisted[i]==0){
               
                q[++rear]=i;
                bvisted[i]=1;
                printf("%d\t",i);
            }
        }
    }

}
void dfs(int start){
    int i;
    dvisted[start]=1;
    s[++top]=start;
    for(i=1;i<=n;i++){
        if(mat[start][i]==1 & dvisted[i]==0){
            printf("%d\n",i);
            dfs(i);
        }
    }
}
int main(){
    int i,j,ch,k;
    printf("enter the number of vertex \n");
    scanf("%d",&n);
    printf("enter the adjected matrix\n");
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)
                    scanf("%d",&mat[i][j]);
        }
    
    for(k=1;k<=n;k++){
        dvisted[k]=0;
        bvisted[k]=0;
    }
    int st;
    printf("enter star vertex");
    scanf("%d",&st);
    for(;;){
            printf("1: BFS all node rechable from starting node\n ");
            printf("2: BFS all node rechable from starting node \n");
            printf("3:exit\n");
            printf("enter your choice--->");
            scanf("%d",&ch);

            switch (ch)
            {
            case 1:
                printf(" nodes reachable from starting vertex  %d  are :",st);
                bfs(st);
                for(i=1;i<=n;i++)
                    if(bvisted[i]==0)
                        printf("node is not reachable from starting node is %d  ",i);
                break;
            case 2:
                printf(" nodes reachable from starting vertex are %d:",st);
                dfs(st);
                break;

            default:
                exit(0);
            }

    }
}      
    


