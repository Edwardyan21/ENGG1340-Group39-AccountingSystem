#ifndef PASSWORD_H
#define PASSWORD_H
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

bool is_firsttime();

void store_username(string);

string enc(string);

void store_userkeys(string);

string get_username();

string get_userkeys();

#endif
