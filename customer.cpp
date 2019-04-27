#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<iomanip>
#include<fstream>
#include<cctype>
#include "customer.h"
#include "transfer.h"
/*
class record
{
  public:
    string get_cur() { return currency; }
    int get_month() { return month; }
    int get_date() { return date; }
    int get_cat() { return category; }
    double get_amo() { return amount; }
    void set_cur(string s) { currency = s;}
    void set_month(int num) { month = num; }
    void set_date(int num) { date = num; }
    void set_cat(int num) { category = num; }
    void set_amo(double num) { amount = num; }
  private:
    string currency;
    int month, date, category, account;
    double amount;
};
*/

//detailstatus.txt: month date amount currency category account
//category: 1. Food 2. Transportation 3. Living expense 4. Shopping 5. Education 6. Others 7. Salary 8. Prizes 9. Presents 10. Otherrewards
//account: 1. Bank 2. Credit 3. Cash
using namespace std;
/*
    content: 1. Add a financial status --> income / expense
            2. View my status --> recent 10 details / get your report of the month-->top three, categories,
            3. Budgets --> Set my budgets / View my budgets / *Special events

    */

/*
string fill_s = "      ";

    cout << string(30, '*') << endl;
    cout           << "What would you like to do?" << endl;
    cout << fill_s << "1. Change a financial status" << endl;
    cout << fill_s << "2. View my status" << endl;
    cout << fill_s << "3. Budgets" << endl;
    cout << fill_s << "4. Personal information" << endl;
    cout << fill_s << "5. Quit" << endl;
    cout           << "Your choice: ";
*/
void add_status()
{
  
}
void del_status()
{
  
}
void view_status()
{
  ifstream finv;
  finv.open("detailstatus.txt");
  if (finv.fail())
  {
    cout << "There's no status available now, start your accounting now~" << endl;
    return;
  }
  int tot;
  finv >> tot;
  record *users = new record[tot];
  int tmpi;
  double tmpd;
  string tmps;
  for (int i = 0; i < tot; i++)
  {
    finv >> tmpi;
    users[i].set_month(tmpi);
    finv >> tmpi;
    users[i].set_date(tmpi);
    finv >> tmpd;
    users[i].set_amo(tmpd);
    finv >> tmps;
    users[i].set_cur(tmps);
    finv >> tmpi;
    users[i].set_cat(tmpi);
    finv >> tmpi;
    users[i].set_acc(tmpi);
  }
  string fill_s = "      ";
  cout << string(30, '*') << endl;
  cout           << "What would you like to do?" << endl;
  cout << fill_s << "1. View my recent 10 details" << endl;
  cout << fill_s << "2. View my monthly report" << endl;
  cout           << "Your choice: ";  
  cin >> tmpi;
  while (tmpi < 1 || tmpi > 2)
  {
    cout << "Opps, wrong choice, please try again: " << endl;
    cin >> tmpi;
  }
  if (tmpi == 1)
  {
    for (int i = tot-1; i >= (tot-10>=0?tot-10:0); i--)
    {
      
    }
  }
}
void budgets()
{
  
}
