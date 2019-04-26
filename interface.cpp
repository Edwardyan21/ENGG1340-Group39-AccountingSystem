#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<fstream>
#include<cctype>
#include<iomanip>
#include "interface.h"
#include 
using namespace std;
void interface()
{
  string user_name;
  string user_keys;
  while (true)
  {
    //welcome xxx!
    cout << string(30, '*') << endl;
    string fill_s = "      ";
    cout           << "What would you like to do?" << endl;
    cout << fill_s << "1. Change a financial status" << endl;
    cout << fill_s << "2. View my status" << endl;
    cout << fill_s << "3. Budgets" << endl;
    cout << fill_s << "4. Personal information" << endl;
    cout << fill_s << "5. Quit" << endl;
    cout           << "Your choice: ";
    int opt;
    cin >> opt;
    while (opt < 1 || opt > 5)
    {
      cout << "Opps, wrong choice...please try again: ";
      cin >> opt;
    }
    /*
    content: 1. Add a financial status --> income / expense
            2. View my status --> recent 10 details / get your report of the month-->top three, categories,
            3. Budgets --> Set my budgets / View my budgets / *Special events
            4. Personal information --> Change my name / Change my password
            5. Quit
    */
    switch (opt)
    {
      case 1:
      {
        cout << string(30, '*') << endl;             //Avoid using system("CLS");
        add_financial();
        break;
      }
      case 2:
      {
        cout << string(30, '*') << endl;
        view_status();
        break;
      }
      case 3:
      {
        cout << string(30, '*') << endl;
        budgets();
        break;
      }
      case 4:
      {
        cout << string(30, '*') << endl;
        cout           << "What would you like to do?" << endl;
        cout << fill_s << "1. Change my name" << endl;
        cout << fill_s << "2. Change my password" << endl;
        cout           << "Your choice: ";
        int opt_4;
        cin >> opt_4;
        while (opt_4 < 1 || opt_4 > 2)
        {
          cout << "Opps, wrong choice...please try again: ";
          cin >> opt_4;
        }
        if (opt_4 == 1)
        {
  
          cout << "Please set your name in no more than 20 characters: ";
          getline(cin, user_name);
          while (user_name.length() > 20)
          {
            cout << "Too long! Set another one: ";
            getline(cin, user_name);
          }
          store_username(user_name);
          cout << "Success!" << endl;
        }
        else
        {
          /*

                    verify the password

          */
          /*

                    set the new password

          */
        }
        break;
      }
      case 5:
      {
        cout << "See you!" << endl;
        exit(1);
        break;
      }
    }
  }
}
