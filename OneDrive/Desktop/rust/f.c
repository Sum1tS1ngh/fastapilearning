#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{
    char *name;
    char *act;
    int date;
}cal;

void create(cal a[] ,int i,char name[],char ac[]){
    a[i].name=(char *) malloc(strlen(name)+1);
    a[i].act=(char *) malloc(strlen(ac)+1);
    strcpy(a[i].name,name);
    strcpy(a[i].act,ac);

}

void read(cal a[]){
    int i;
    char name[30],ac[60];
    for(i=0;i<7;i++){
        printf("enter day name:");
        scanf("%s",name);
        printf("enter day activty:");
        scanf("%s",ac);
        printf("enter date of day:");
        scanf("%d",&a[i].date);
        create(a,i,name,ac);
    }
}
void display(cal a[]){
    int i;
    for(i=0;i<7;i++){
        printf("name of day : %s",a[i].name);
        printf("date of day : %s",a[i].date);
        printf("activity of day : %s",a[i].act);



    }
}
void main(){
    cal a[7];
    printf("enter detaits");
    read(a);
    printf("display details");
    display(a);
}
#include<stdio.h>
#include<stdlib.h>

void push(int item){
    if(top==9){
        printf("stack is overflod")
    }
    else{
        top++;
        stack[top]=item;
    }
}

int pop(){
    if(top==-1){
        printf("stack is overflod")
    }
    else{
        printf("from stack %d is removed",stack[top]);
        return stack[--top];
        
    }
}

void pld(char st){
    int i;
    for(i=0;st[i]!="\0"){
        top=-1;
        stack[top++]=st[i];
        
    }
    for(i=0;st[i]!="\0"){
        if(st[i]==pop())
            continue;
        printf("%s not palindrome ",st);
        return;
    }
    printf("%s is palindrome",st);

}
void dispaly(){
    if(top==-1)
        printf(stack is empty);
    for(top;top>=0:top--){
        printf(stack[top]);
    }
}

void main(){
    int top=-1;
    int stack[10];
    int choice;
    printf("choice 1: to pop 2: to push 3: to display 4: to check plindrome");
    scanf("%d",choice);

    switch(choice){
        case 1:
            pop();

        case 2:
            int item;
            printf("enter item to push")
            scanf("%d",&)
            push(item);

        case 3:
            dispaly();

        case 4:
            char str[10];
            printf("enter string to check palindrome")
            scanf("%s",str);
            pld(str);




    }
}