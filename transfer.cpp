#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<iomanip>
#include<fstream>
#include<cctype>
#include "transfer.h"
//category: 1. Food 2. Transportation 3. Living expense 4. Shopping 5. Education 6. Others 7. Salary 8. Prizes 9. Presents 10. Otherrewards
//account: 1. Bank 2. Credit 3. Cash
string transfer_category(int u_in)
{
  string res;
  switch (u_in)
  {
    case 1:
      res = "Food";
      break;
    case 2:
      res = "Transportation";
      break;
    case 3:
      res = "Living Expense";
      break;
    case 4:
      res = "Shopping";
      break;
    case 5:
      res = "Education";
      break;
    case 6:
      res = "Other Expense";
      break;
    case 7:
      res = "Salary";
      break;
    case 8:
      res = "Prizes";
      break;
    case 9:
      res = "Presents";
      break;
    case 10:
      res = "Other Income";
      break;
  }
  return res;
}

string transfer_account(int u_in)
{
  string res;
  switch (u_in)
  {
    case 1:
      res = "Bank";
      break;
    case 2:
      res = "Credit";
      break;
    case 3:
      res = "Cash";
      break;
  }
  return res;
}

double Calculate_money(string user_input)
{
  if (user_input[0] == '-' || user_input[0] == '+')
    user_input.insert(0, "0");
  string num_s = "";
  int flag = 1;
  double result = 0, tmp=0;
  for (int i = 0; i < user_input.length(); i++)
  {
    if （user_input[i] >= '0' && user_input[i] <= '9')
    {
      num_s.insert(num_s.length(), user_input.substr(i, 1));
      if (num_s.length() > 8)
      {
        cout << "Error: Input is too large!" << endl;
        return 0;
      }
    }
    else if (user_input[i] == '+' || user_input[i] == '-')
    {
      tmp = atof(num_s.c_str());
      result += (double)flag * tmp;
      tmp = 0;
      num_s = "";
      flag = (user_input[i] == '+' ? 1 : -1);
    }
    else 
    {
      cout << "Opps, wrong expression!" << endl;
      return 0;
    }
  }
  tmp = atof(num_s.c_str());
  result += (double)flag * tmp;
  if (result >= 100000000)
  {
    cout << "Error: Input is too large!" << endl;
    return 0;
  }
  return result;
}
