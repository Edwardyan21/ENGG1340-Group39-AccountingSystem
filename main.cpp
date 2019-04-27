//ENGG1340 Group 39 Accounting System Pro_Main
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include "interface.h"
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
    while (user_name.length() > 20 || user_name == "")
    {
      if(user_name == ""){
        cout << "Empty user name! Try another one: ";
        getline(cin, user_name);
      }
      else{
        cout << "Too long! Try another one: ";
        getline(cin, user_name);
      }
    }
    cout << "Hello " << user_name << "! Please set your password in no more than 20 characters: ";
    getline(cin, user_keys);
    while (user_keys.length() > 20 || user_keys == "")
    {
      if(user_keys == ""){
        cout << "Empty key! Try another one: ";
        getline(cin, user_keys);
      }
      else{
        cout << "Too long! Try another one: ";
        getline(cin, user_keys);
      }
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
  getline(cin, user_keys);
  int n = 0;
  while (enc(user_keys) != keys){
		n++;
		if (n == 1){
			cout << "Wrong! You have 2 trails left. Please try again: ";
      getline(cin, user_keys);
		}
		if (n == 2){
			cout << "Wrong! You have 1 trails left. Please try again: ";
      getline(cin, user_keys);
		}
		if (n == 3){
			cout << "You have entered the wrong password for three times. You are forced to exit." << endl;
			exit(1);
		}
	}
  //correct keys and log in
  cout << "Correct! Logging you in..." << endl;
  interface();
  return 0;
}
