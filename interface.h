#ifndef INTERFACE_H
#define INTERFACE_H

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<fstream>
#include<cctype>
#include<iomanip>
#include "customer.h"
#include "transfer.h"
#include "password.h"
using namespace std;
/*
To do: Welcome page+content
content: 1. Add a financial status --> income / expense
         2. View my status --> recent 10 details / get your report of the month-->top three, categories,
         3. Budgets --> Set my budgets / View my budgets / *Special events
         4. Personal information --> Change my name / Change my password
         5. Quit
*/
void interface();

#endif
