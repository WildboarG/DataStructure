
// 后缀表达式的计算
// 15 7 1 1 + - / 3 * 2 1 1 + + -
// 用链式栈 带头节点实现

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
typedef struct node{
    int data;
    struct node *next; 
}LinkedStrack;  // 节点

//初始化
void InitStack(LinkedStrack *S){
    S = (LinkedStrack*)malloc(sizeof(LinkedStrack));
    S->next = NULL;        //链头指向第一个节点
}
// 入栈
// 将数据带入新节点内
bool PushStack(LinkedStrack *S,int num){
    LinkedStrack* nnode = (LinkedStrack*)malloc(sizeof(LinkedStrack));
    if(nnode==NULL)
        return false;//申请内存失败
    nnode->data = num; 
    nnode->next =S->next; 
    S->next = nnode;
    return true;
}

//出栈
bool PopStack(LinkedStrack *S,int *value){
    LinkedStrack *temp = S->next;  //用一个临时指针来接管第一个节点，便于销毁
    if(temp==NULL){
        return false; //栈空
    }
    *value = temp->data;   // 弹出数据
    //printf("要出的数：%d\n",temp->data;
    S->next = temp->next;  // 头节点指向下一个节点
    free(temp);            //free掉弹出的节点
    return true;
}

int main(){
    LinkedStrack S;  // 生命一个结构体类型
    InitStack(&S);   // 初始化链栈的头节点
    char str[] = "15 7 1 1 + - / 3 * 2 1 1 + + -";  // 后缀表达式
    int temp=0;
    int x,y,z;
    for (int i=0;i<strlen(str);i++){
        if ((int)str[i]>48 && (int)str[i]< 58){ // 如果是数字
            if (temp==0){
            temp += (int)str[i]-48;              
            }else{
                temp=temp*10;
                temp+=(int)str[i]-48;            
            }
            //printf("temp=%d\n",(int)temp);
        }
        if(str[i]==32){                     // 如果是空格分割符
            if((int)str[i-1]>48 && (int)str[i-1]< 58){ // 遇到分割符号，判断前一个字符是否为数字，若为数字，将数字压栈，如不是就跳过
                PushStack(&S,temp);
                printf("压入：%d\n",temp);
                temp=0;
            }
            //continue;
        }
        
        if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'){
            //若为运算符，弹出两个数据进行运算           
            PopStack(&S,&y);
            PopStack(&S,&x);
            printf("弹出y=%d\t",y);
            printf("弹出x=%d\n",x);

            if(str[i]=='+'){
                printf("[%c]",str[i]);
                z = x + y;
            }
            if(str[i]=='-'){
                printf("[%c]",str[i]);
                z = x - y;
            }
            if(str[i]=='*'){
                printf("[%c]",str[i]);
                z = x * y;
            }if(str[i]=='/'){
                printf("[%c]",str[i]);
                z = x / y;
            }
            printf("计算后重新压入：%d\n",z);
            PushStack(&S,z);
            
            
        }
    
    }
    int result;
    PopStack(&S,&result);  //弹出最终的结果
    printf("result=%d\n",result);


    return 0;
}