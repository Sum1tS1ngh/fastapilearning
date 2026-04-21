#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct node{
    int c;
    int px;
    int py;
    int pz;
    struct node *link;

};
typedef struct node *NODE;
NODE get(){
    NODE x=(NODE) malloc(sizeof(struct node));
    if(x==NULL)
       return 0;
    return x;
}
NODE insert(NODE head,int c,int x,int y,int z){
    NODE t,cur;
    t=get();
    t->c=c;
    t->px=x;
    t->py=y;
    t->pz=z;
    t->link=NULL;
    cur=head;
    while(cur->link!=head)
        cur=cur->link;
    cur->link=t;
    t->link=head;
    return head;
}
NODE read(){
    NODE head;
    head=get();
    head->link=head;
    int c,x,y,z;
    for(;;){
        scanf("%d",&c);
        if(c==0)
            break;
        else{
            scanf("%d",&x); scanf("%d",&y); scanf("%d",&z);
            head=insert(head,c,x,y,z);
        }
         

    }
    return head;
}

NODE add(NODE h1,NODE h2){
    NODE s,p,q;
    s=get();
    s->link=s;
    int sum;
    for(q=h1->link;q!=h1;q=q->link){
        for(p=h2->link;p!=h2;p=p->link){
            if(q->px==p->px && q->py==p->py && q->pz==p->pz){
                sum=p->c + q->c;
                p->c=0;
                if(sum!=0) insert(s,sum,q->px,q->py,q->pz);
                break;
            }
        }
        if(p==h2) insert(s,q->c,q->px,q->py,q->pz);
    }
    for(p=h2->link;p!=h2;p=p->link){
        if(p->c==0)
            continue;
        insert(s,p->c,p->px,p->py,p->pz);
    }
    return s;

}
void print(NODE h){
    NODE c;
    for(c=h->link;c!=h;c=c->link){
        if(c->c>=0)
            printf("+%dx^%dy^%dz^%d ",c->c,c->px,c->py,c->pz);
        else
            printf("%dx^%dy^%dz^%d ",c->c,c->px,c->py,c->pz);
    }
    printf("\n");
}
void evaluate(int x,int y,int z,NODE h){
    NODE cur;
    cur=h->link;
    int sum=0;
    while(cur!=h){
        sum +=cur->c*pow(x,cur->px)*pow(y,cur->py)*pow(z,cur->pz);
        cur=cur->link;
    }
    printf("result %d-->",sum);

}
int main(){
    NODE h1,h2,h3;
    int choice,x,y,z;
    for(;;){
        printf("1: add  2: evaluate  3:exit --->");
        scanf("%d",&choice);
        
        switch(choice){
            case 1:
                printf("enter first polnomial");
                h1=read();
                printf("enter second polnomail");
                h2=read();
                print(h1);
                print(h2);
                h3=add(h1,h2);
                
                printf("addition of two polynomial is-->\n");
                print(h3);
                break;
            case 2:
                printf("enter polynomail :");
                h1=read();
                printf("enter x , y and z value-->");
                scanf("%d %d %d",&x,&y,&z);

                print(h1);
                printf("after evaluate polynomial\n");
                evaluate(x,y,z,h1);
                break;
            case 3:
               printf("exiting througth programm");
               exit(0);
                

        }
    }
}