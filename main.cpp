//ENGG1340 Group 39 Accounting System Pro_Main
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include "interface.h"
#include "customer.h"
#include "password.h"
using namespace std;


int main()
{
  string user_name;
  string user_keys;
  
  //determine if it is the first-time user
  if (is_firsttime())
  {
    cout << "Welcome! Please set your name and password!" << endl;
    cout << "Please set your name in no more than 20 characters: ";
    getline(cin, user_name);
    while (user_name.length() > 20)
    {
      cout << "Too long! Set another one: ";
      getline(cin, user_name);
    }
    while (user_name == "")
    {
      cout << "Empty user name! Set another one: ";
      getline(cin, user_name);
    }
    cout << "Hello " << user_name << "! Please set your password in no more than 20 characters: ";
    getline(cin, user_keys);
    while (user_keys.length() > 20)
    {
      cout << "Too long! Try another one: ";
      getline(cin, user_keys);
    }
    while (user_keys == "")
    {
      cout << "Empty key! Set another one: ";
      getline(cin, user_keys);
    }
    cout << "Okay! Setting..." <<endl;
    store_username(user_name);
    store_userkeys(user_keys); // will be encrypted
    cout << "Success! Now you can use your key: \"" << user_keys << "\" to log in!" << endl;
    cout << endl;
  }
  
  //enter password to get into the interface
  user_name = get_username();
  string keys = get_userkeys();
  cout << "Welcome " << user_name << "!\nPlease enter your password:";
  cin >> user_keys;
  while (enc(user_keys) != keys)
  {
    cout << "Opps, wrong keys, Please try again: ";
  }

  //correct keys and log in
  cout << "Correct! Logging you in..." << endl;
  interface();
  return 0;
}
