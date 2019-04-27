#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<iomanip>
#include<fstream>
#include<cctype>
#include "transfer.h"
using namespace std;

class record
{
  public:
    int get_cur() { return currency; }
    int get_month() { return month; }
    int get_date() { return date; }
    int get_cat() { return category; }
    double get_amo() { return amount; }
    int get_acc() { return account; }
    
    void set_cur(int s) { currency = s;}
    void set_month(int num) { month = num; }
    void set_date(int num) { date = num; }
    void set_cat(int num) { category = num; }
    void set_amo(double num) { amount = num; }
    void set_acc(int num) { account = num; }


  private:
    int currency;
    int month, date, category, account;
    double amount;
};

void add_status();
void del_status();
void view_status();
void budgets();

#endif
