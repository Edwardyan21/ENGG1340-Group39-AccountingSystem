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
/*class record
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
*/

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
  int month, date, currency, cate, account, m, d, cur, cat, ac;
  double amount, am;
  string samount;
  cout << "Please enter the month(1-12): ";
  cin >> month;
  while (month > 12 || month < 1) {
	  cout << "Invalid! Try again: ";
	  cin >> month;
  }
  cout << "Please enter the date: ";
  cin >> date;
  cout << "Please enter the amount(0~9,+,-): ";
  cin >> samount;
  amount = Calculate_money(samount);
  if (amount < 0) amount = 0;
  cout << "Please choose the currency type: " << endl;
  cout << "1. HKD  2. CNY  3. USD  4. GBP  5. JPY" << endl;
  cin >> currency;
  while ( currency < 1 || currency > 5){
	  cout << "This type is invalid. Choose one from the provided currency: ";
	  cin >> currency;
  }
  cout << "Please choose the category: " << endl;
  cout << "1. Food \n2. Transportation \n3. Living expense \n4. Shopping \n5. Education \n6. Otherexpense \n7. Salary \n8. Prizes \n9. Presents \n10.Otherincomes " << endl;
  cin >> cate;
  while ( cate < 1 || cate > 10){
	  cout << "This category is invalid. Try again: ";
	  cin >> cate;
  }
  if (cate <= 6 && cate >= 1){
	  amount*= -1;
  }
  cout << "Please choose the account you want to use: " << endl;
  cout << "1. Bank Card  2. Credit Card  3. Cash" << endl;
  cin >> account;
  while ( account < 1 || account > 3){
	  cout << "This type is invalid. Choose one from the provided currency: ";
	  cin >> account;
  }
  int tot;
  ifstream fina;
  fina.open("detailstatus.txt");
  if(fina.fail()){
	  tot = 0;
  }
  else{
	  fina >> tot;
  }
  record *users = new record[tot];
  double tot_m = change(amount, currency);
  for (int i = 0; i < tot; i++){
	  fina >> m >> d >> am >> cur >> cat >> ac; 
	  users[i].set_month(m);
	  users[i].set_date(d);
	  users[i].set_amo(am);
	  users[i].set_cur(cur);
	  users[i].set_cat(cat);
	  users[i].set_acc(ac);
	  tot_m += change(am, cur);
  }
  fina.close();
  fina.clear();
  ifstream finb2;
  finb2.open("user_budgets.txt");
  if (!finb2.fail())
  {
	  double tot_bud;
      	  finb2 >> tot_bud;
      	  if ((0 - tot_m) > tot_bud){
      	  	  cout << "You have gone over the budget!" << endl;
          }
      	  else if ((0 - tot_m) == tot_bud){
      		  cout << "You have reached the budget!" << endl;
      	  }
  }
  finb2.close();
  finb2.clear();
  record *users_n = new record[tot + 1];
  int i = 0;
  for (i = 0; i < tot; i++){
	  if (users[i].get_month() <= month || (users[i].get_date() <= date && users[i].get_month() == month)){
			users_n[i] = users[i];
	  }
	  else break;
  }
	
  users_n[i].set_month(month);
  users_n[i].set_date(date);
  users_n[i].set_amo(amount);
  users_n[i].set_cur(currency);
  users_n[i].set_cat(cate);
  users_n[i].set_acc(account);
  for (int j = i + 1; j < tot + 1; j++){
	  users_n[j] = users[j - 1];
  }
  tot = tot + 1; 
  ofstream fouta;
  fouta.open("detailstatus.txt");
  fouta << tot << endl; 
  for (int p = 0; p < tot; p++){
	  fouta << users_n[p].get_month() << " " << users_n[p].get_date() << " " << users_n[p].get_amo() << " " << users_n[p].get_cur() << " " << users_n[p].get_cat() << " " << users_n[p].get_acc() << endl;
  }
  delete [] users;
  delete [] users_n;
  fouta.close();
  fouta.clear();
}

void del_status()
{
  int month, date, m, d, cur, cat, ac;
	double am;
	cout << "Please enter the month of the record you want to delete: ";
	cin >> month;
	cout << "Please enter the date: ";
	cin >> date;
	int tot;
	ifstream find;
	find.open("detailstatus.txt");
	if(find.fail()){
		cout << "There's no status available now, try to add some first!" << endl;
		return;
	}
	find >> tot;
	record *users = new record[tot];
	record *del = new record[tot];
	for (int i = 0; i < tot; i++){
		find >> m >> d >> am >> cur >> cat >> ac; 
		users[i].set_month(m);
		users[i].set_date(d);
		users[i].set_amo(am);
		users[i].set_cur(cur);
		users[i].set_cat(cat);
		users[i].set_acc(ac);
	}
	find.close();
	find.clear();
	int a = 0;
	for (int i = 0; i < tot; i++){
		if (users[i].get_month() == month && users[i].get_date() == date){
		  cout << right;
      		  cout << setw(2) << users[i].get_month() << "." << left << setw(2) << users[i].get_date();
      		  cout << right << setw(15) << fixed << setprecision(2) << users[i].get_amo() << left << setw(4) << transfer_currency(users[i].get_cur());
      		  cout << setw(16) << transfer_category(users[i].get_cat()) << setw(7) << transfer_account(users[i].get_acc());
      		  cout << endl;
      		  a += 1;
		}
	}
	int n;
	cout << "Choose the record that you want to delete(please indicate its order): ";
	cin >> n;
	while(n > a || n <= 0){
		cout << "Out of range! Try again: ";
		cin >> n;
	}
	int b = 0;
	char c;
	bool check = true;
	for (int i = 0; i < tot; i++){
		if (users[i].get_month() == month && users[i].get_date() == date){
			b+=1;
			if (b == n) {
			cout << right;
      			cout << setw(2) << users[i].get_month() << "." << left << setw(2) << users[i].get_date();
      			cout << right << setw(15) << fixed << setprecision(2) << users[i].get_amo() << left << setw(4) << transfer_currency(users[i].get_cur());
      			cout << setw(16) << transfer_category(users[i].get_cat()) << setw(7) << transfer_account(users[i].get_acc());
      			cout << "\nAre you sure you want to delete this record?(Y/N)";
      			cin >> c;
      			if (c == 'Y'){
      				check = false;
					continue;
      			}
			}
		}
		if(check){
			del[i] = users[i];
		}
		else{
			del[i - 1] = users[i];
		}
	}
	ofstream foutd;
	foutd.open("detailstatus.txt");
	if(check){
		foutd << tot << endl; 
		for (int p = 0; p < tot ; p++){
			foutd << del[p].get_month() << " " << del[p].get_date() << " " << del[p].get_amo() << " " << del[p].get_cur() << " " << del[p].get_cat() << " " << del[p].get_acc() << endl;
		}
	}
	else{
		foutd << tot - 1 << endl; 
		for (int p = 0; p < tot - 1; p++){
			foutd << del[p].get_month() << " " << del[p].get_date() << " " << del[p].get_amo() << " " << del[p].get_cur() << " " << del[p].get_cat() << " " << del[p].get_acc() << endl;
		}
	}
	delete [] users;
	delete [] del;
	foutd.close();
	foutd.clear();
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
      cout << right;
      cout << setw(2) << users[i].get_month() << "." << left << setw(2) << users[i].get_date();
      cout << right << setw(15) << fixed << setprecision(2) << users[i].get_amo() << left << setw(4) << transfer_currency(users[i].get_cur());
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
    double max_in =0, max_out = 0;
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
    cout << "Your account details in HKD: " << endl;
    for (int i = 1; i <= 3; i++)
      cout << fill_s << transfer_account(i) << " " << fixed << setprecision(2) << tot_acc[i] << endl;
    cout << "For each category in HKD: " << endl;
    for (int i = 1; i <= 10; i++)
      cout << fill_s << transfer_category(i) << " " << fixed << setprecision(2) << tot_cate[i] << endl;
    cout << "The maximum expense of the month in HKD: " << endl;
      cout << fill_s << max_out*(-1) << endl;
    cout << "The maximun income of the month in HKD: " << endl;
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
      cout << "Opps, out of range, please try again: " << endl;
      cin >> tmpi2;
    }
    ofstream foutb;
    foutb.open("user_budgets.txt");
    foutb << tmpi2 << endl;
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
      cout << "Opps, invalid, please try again: " << endl;
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
