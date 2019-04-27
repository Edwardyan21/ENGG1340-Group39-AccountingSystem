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


//detailstatus.txt: month date amount currency category account
//category: 1. Food 2. Transportation 3. Living expense 4. Shopping 5. Education 6. Others 7. Salary 8. Prizes 9. Presents 10. Otherrewards
//account: 1. Bank 2. Credit 3. Cash

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
    finv >> tmpi;
    users[i].set_cur(tmpi);
    finv >> tmpi;
    users[i].set_cat(tmpi);
    finv >> tmpi;
    users[i].set_acc(tmpi);
  }
  finv.close();
  finv.clear();
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
    cout << string(30, '*') << endl;
    for (int i = tot-1; i >= (tot-10>=0?tot-10:0); i--)
    {
      cout << left;
      cout << setw(3) << users[i].get_month() << setw(3) << users[i].get_date();
      cout << setw(15) << users[i].get_amo() << setw(4) << transfer_currency(users[i].get_cur());
      cout << setw(16) << transfer_category(users[i].get_cat()) << setw(7) << transfer_account(users[i].get_acc());
      cout << endl;
    }
  }
  else
  {
    cout << string(30, '*') << endl;
    cout << "Select a month: " << endl;
    int tmpi2;
    cin >> tmpi2;
    while (tmpi2 < 1 || tmpi2 > 12)
    {
      cout << "Opps, wrong choice, please try again: " << endl;
      cin >> tmpi2;
    }
    double *tot_cate = new double [11]{};
    double *tot_acc = new double [4]{};
    double max_in = max_out = 0;
    for (int i = 0; i < tot; i++)
    {
      if (users[i].get_month() == tmpi2)
      {
        tot_cate[users[i].get_cat()] += change(users[i].get_amo(), users[i].get_cur());
        tot_acc[users[i].get_acc()] += change(users[i].get_amo(), users[i].get_cur());
        if (users[i].get_cat() <= 6 && change(users[i].get_amo(), users[i].get_cur()) < max_out)
          max_out = change(users[i].get_amo(), users[i].get_cur());
        if (users[i].get_cat() > 6 && change(users[i].get_amo(), users[i].get_cur()) > max_in)
          max_in = change(users[i].get_amo(), users[i].get_cur());
      }
    }
    cout << "Your account details: " << endl;
    for (int i = 1; i <= 3; i++)
      cout << fill_s << transfer_account(i) << " " << fixed << setprecision(2) << tot_acc[i] << endl;
    cout << "For each category: " << endl;
    for (int i = 1; i <= 10; i++)
      cout << fill_s << transfer_category(i) << " " << fixed << setprecision(2) << tot_cate[i] << endl;
    cout << "The maximum expense of the month: " << endl;
      cout << fill_s << max_out*(-1) << endl;
    cout << "The maximun income of the month: " << endl;
      cout << fill_s << max_in << endl;
    delete [] tot_cate;
    delete [] tot_acc;
  }
  delete [] users;
}



void budgets()
{
  string fill_s = "      ";
  cout << string(30, '*') << endl;
  cout           << "What would you like to do?" << endl;
  cout << fill_s << "1. Set my monthly budgets" << endl;
  cout << fill_s << "2. How much could I spend..." << endl;
  cout           << "Your choice: ";
  int tmpi;
  cin >> tmpi;
  while (tmpi < 1 || tmpi > 2)
  {
    cout << "Opps, wrong choice, please try again: " << endl;
    cin >> tmpi;
  }
  if (tmpi == 1)
  {
    cout << string(30, '*') << endl;
    cout << "Enter your expected budgets, positive integer smaller than 10 million only: " << endl;
    int tmpi2;
    cin >> tmpi2;
    while (tmpi2 <= 0 || tmpi2 >= 100000000)
    {
      cout << "Opps, wrong choice, please try again: " << endl;
      cin >> tmpi2;
    }
    ofstream foutb;
    foutb.open("user_budgets.txt");
    fout << tmpi2 << endl;
    foutb.close();
    foutb.clear();
  }
  else
  {
    cout << string(30, '*') << endl;
    cout << "From which month till now?" ;
    int tmpi2;
    cin >> tmpi2;
    while (tmpi2 < 1 || tmpi2 > 12)
    {
      cout << "Opps, wrong choice, please try again: " << endl;
      cin >> tmpi2;
    }
    ifstream finb2;
    finb2.open("user_budgets.txt");
    if (finb2.fail())
    {
      cout << "Opps, it seems that you haven't set your budgets yet..." << endl;
      return;
    }
    double tot_bud;
    finb2 >> tot_bud;
    finb2.close();
    finb2.clear();

    ifstream finb;
    finb.open("detailstatus.txt");
    if (finb.fail())
    {
      cout << "You haven't spend any money! Relax!" << endl;
      return;
    }
    int tot;
    finb >> tot;
    int mon1, date1, cur1, cate1, acc1;
    double amo1, tot_amo = 0;
    int cur_mon = tmpi2;
    for (int i = 0; i < tot; i++)
    {
      finb >> mon1 >> date1 >> amo1 >> cur1 >> cate1 >> acc1;
      if (cur_mon < mon1)
        cur_mon = mon1;
      if (cur_mon >= tmpi2)
        tot_amo += change(amo1, cur1);
    }
    finb.close();
    finb.clear();
    tot_bud *= (cur_mon - tmpi2 + 1);
    tot_amo *= -1;
    if (tot_amo > tot_bud)
    {
      cout << "Oh no, you've spend too much! It is " << fixed << setprecision(2) << tot_amo-tot_bud;
      cout << " over the budget!" << endl;
    }
    else
    {
      cout << "From month " << tmpi2 << " to " << cur_mon << ", your budget is ";
      cout << fixed << setprecision(0) << tot_bud <<" HKD, you have ";
      cout << fixed << setprecision(2) << tot_bud-tot_amo << " left." <<endl;
    }
  }
}
