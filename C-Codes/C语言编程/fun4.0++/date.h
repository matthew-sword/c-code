#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

int getDaySeqofYear(int month,int day);/*���㼸�¼�����ȫ��ڼ���*/
int getDaySeqofWeek(int daySeqofYear);/*����ȫ���ĳ�������ڼ�*/
int getMonth(int daySeqofYear);/*����ȫ���ĳ���Ǽ���*/
int getDay(int daySeqofYear);/*����ȫ���ĳ���Ǽ���*/
int getWeekSeqOfYear(int daySeqOfYear);/*����ȫ���ĳ���ǵڼ���*/
int isMonth(int month);/*�����û�������·��Ƿ����Ҫ��*/
int isDay(int month,int day);/*�����û��������Ӧ�·ݵ������Ƿ����Ҫ��*/

#endif // DATE_H_INCLUDED
