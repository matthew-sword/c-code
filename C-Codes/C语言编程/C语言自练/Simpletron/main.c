#include <stdio.h>
#include <stdlib.h>
#include"funs.h"

int memory[100];//Simpletron���ڴ�
int accumulator;//Simpletron���ۼ���
int instructionCounter;//��ǰ��ִ��ָ��Ĵ洢��ַ
int operationCode;//��ǰ�������͵Ĵ���
int operand;//��ǰָ�����������Ĵ洢��ַ
int instructionRegister;//����ִ�е�ָ��

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
