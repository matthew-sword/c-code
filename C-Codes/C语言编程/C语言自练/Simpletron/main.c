#include <stdio.h>
#include <stdlib.h>
#include"funs.h"

int memory[100];//Simpletron的内存
int accumulator;//Simpletron的累加器
int instructionCounter;//当前被执行指令的存储地址
int operationCode;//当前操作类型的代号
int operand;//当前指令所处理对象的存储地址
int instructionRegister;//即将执行的指令

int main()
{
    welcome();

    program(memory);
    int i,j;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
           instructionCounter=10*i+j;
           instructionRegister=memory[instructionCounter];
           operationCode=(instructionRegister-instructionRegister%100)/100;
           operand=instructionRegister%100;
           operation(operationCode,operand,memory);
           if(operationCode==43){
              break;
           }
        }
        if(operationCode==43){
              break;
           }
    }
    return 0;
}
