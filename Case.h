#pragma once
#include"Hospital.h"
#include<ctime>

inline void change(int num, char* str)
{
    int p = 0;
    int tmp = num;
    while (tmp)
    {
        p++;
        tmp /= 10;
    }
    if (num > 0)p--;
    tmp = num;
    while (tmp)
    {
        str[p] = (tmp % 10) + '0';
        p--;
        tmp /= 10;
    }
}
inline char* Gettime(char t[22]) {
    time_t nowtime = time(NULL);
    tm* p = localtime(&nowtime);
    change(p->tm_year + 1900, t);
    t[4] = '-';
    if (p->tm_mon + 1 < 10) {
        t[5] = '0';
        change(p->tm_mon + 1, t + 6);
    }
    else change(p->tm_mon + 1, t + 5);
    t[7] = '-';
    if (p->tm_mday < 10) {
        t[8] = '0';
        change(p->tm_mday, t + 9);
    }
    else change(p->tm_mday, t + 8);
    t[10] = ' ';
    if (p->tm_hour < 10) {
        t[11] = '0';
        change(p->tm_hour, t + 12);
    }
    else change(p->tm_hour, t + 11);
    t[13] = ':';
    if (p->tm_min < 10) {
        t[14] = '0';
        change(p->tm_min, t + 15);
    }
    else change(p->tm_min, t + 14);
    t[16] = ':';
    if (p->tm_sec < 10) {
        t[17] = '0';
        change(p->tm_sec, t + 18);
    }
    else change(p->tm_sec, t + 17);
    t[19] = ':';t[20] = ' ';
    return t;

};

class Case {
public:
	void create(string h_name, string d_name, string p_name);
	void search();
	/*添加医嘱*/void modify();

};