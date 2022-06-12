/*
 * 用顺序站的方式现实括号匹配
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 7


//创建站的基本数据结构
typedef struct {
    char arr[MAXSIZE]; //最大容量
    int printer;  //栈指针
    int top;
}sqStack;


//初始化一个顺序栈
void Initstruck(sqStack *S){
    S->printer = -1;     //栈底指针指向-1
}
// 入栈
bool push(sqStack *S,char i){
    if (S->printer+1==MAXSIZE){
        return false;  // 栈满
    }
    S->printer = S->printer+1;
    S->arr[S->printer]=i;
    printf("栈顶:%d->%c\n",S->printer,S->arr[S->printer]);
    return true;
}
// 出战
bool pop(sqStack *S,char *x){
    if(S->printer == -1){
        return false;  //空栈
    }
    
    *x = S->arr[S->printer];
    S->printer =S->printer-1;
    printf("此时栈顶下移动1个单位=%d",S->printer);
    return true;
}
// 判空
bool IsEmpty(sqStack *S){
     if(S->printer == -1){
        return true;  //空栈
    }
    return false;
}
//判满
bool IsFull(sqStack *S){
    if(S->printer==MAXSIZE-1){
        return true;
    }
    return false;
}

//用站的方式现实括号匹配
bool bracketcheck(char str[],int length){
    sqStack S; //声明栈的数据类型
    Initstruck(&S); //初始化栈
    for(int j=0;j<length;j++){
        if(str[j] == '(' || str[j]=='{' || str[j]=='['){
            if(!IsFull(&S)){
                push(&S,str[j]);
            }
            else{
                printf("%s\n","栈溢出");
                return false;
            }
        }
        else{
            if(IsEmpty(&S)){// 如果是右括号 看站是否为空
                printf("%s\n","栈空了,没法匹配括号");
                return false;}
            char emly;      
            pop(&S,&emly);  // 不为空 弹栈用变量elmy 接收做括号;
            printf("当前值：%c\n",str[j]);
            printf("POP:%c\n",emly);
            
            if (str[j] ==')' && emly!='('){
                printf("%s \n","匹配类型错误");
                return false;
            }
            if (str[j]==']' && emly!='['){
                printf("%s \n","匹配类型错误");
                return false;
            }
            if (emly!='{' && str[j]=='}'){
                printf("%s\n","匹配类型错误");
                return false;
            }
        }
    }
    printf("%s\n","成功匹配");

}

int main(){
    char stra[]="{{[({(())})]}}";
    int a=14;
    bracketcheck(stra,a);
}