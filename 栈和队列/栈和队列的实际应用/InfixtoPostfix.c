//这里用的是伪c代码

InitStack(&S); //初始化
PushStack(&S, ElemType e); //入栈
PopStack(&S, ElemType &e); //出栈
GetTop(&S, ElemType &x);   // 读取栈顶元素

void InfixtoPostfix(&S){
  InitStack(&S);
  char str[]= "((15/(7-(1+1)))*3)-2(2+(1+1))" //中缀表达式
  char value[]; // 用于接受的后缀表达式
  //c重复扫描
  for(int i=0;i<strlen(str);i++){
    //操作数
    if((int)str[i]>48 && (int)str[i]<58){
      strcat(value,str[i]);
    }
    //括号问题
    if(str[i]=='('){
      PushStack(&S,str[i]);
    }
    if(str[i]==')'){
        while (PopStack(&S,&e)) {
          if(e =='('){
            break;
          }else{
            strcat(value, e);  //若弹出的不是(就加入到新的表达式中
          }
        }
    }
    // 运算符
    if(str[i]=='+' || str[i]=='-'){
      while(1){
        GetTop(&S,&x);
        if(x=='+'||x=='-'||x=='*'||=='/'){ //若栈顶的运算级高于当前运算级
          PopStack(&S,&e);
          strcat(value, e);
        }
        else{  // 若没有当前优先级高就压栈
          PushStack(&S,str[i]);
          break;
        }
      }
    }
    if(str[i]=='*' || str[i]=='\'){
      while(1){
        GetTop(&S,&x);
        if(x=='*'||=='/'){ //若栈顶的运算级高于当前运算级
          PopStack(&S,&e);
          strcat(value, e);
        }
        else{  // 若没有当前优先级高就压栈
          PushStack(&S,str[i]);
          break;
        }
      }
    }
    while(PushStack(&S,&e)){  //剩余运算符一次弹出
      strcat(value,e)
    }
    printf("%s\n",value);
  }
}
