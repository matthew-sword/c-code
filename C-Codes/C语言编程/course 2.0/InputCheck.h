#ifndef INPUTCHECK_H_INCLUDED
#define INPUTCHECK_H_INCLUDED
#include "file.h"


int checkMonth(void);
//检查月份输入的合法性
int checkDay(int month);
//检查日期输入的合法性
int checkSeq(void);
//检查课程节次输入的合法性

#endif // INPUTCHECK_H_INCLUDED
