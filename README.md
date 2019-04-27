# Accounting System Pro
## ENGG1340 Group39

### Problem Statement
Managing financial status easily on the user’s system is a trend nowadays. Hand-written accounting takes longer time and has lower security than online system. We aim to develop an accounting system with some powerful and easy-to-use functions to help users keep track of their financial status without spending much time and provide some financial advice such as setting daily budgets.

### Problem Setting
- Users record their expense and income frequently
- They would like to keep track of detailed and overall financial status and would like to set some budget plans to regulate their life
- They would also like to seek advice when special events happen and additional expenses are needed
- Since there’s no enough database for us, we assume that the currency rate will remain as a default value
- Since we don't have much storage to store, assume the database focus on one year
- We assume the customers are Hong Kong citizens, so the default unit is HKD, and we assume that the total amonut will not exceed 10 million

### Program Features
The designed program will contain the following features: 
1) **Add records of income and expenses:**
   - The record of different currency will be calculated into the major currency
   - Simple calculations(add, subtract) are allowed(we think that other operations are not needed in this system)
2) **The records can contain some basic information:**
   - Amount
   - Equivalent amount(for foreign currency, budgets and reports only)
   - Date
   - Types of income or expense(such as food, transportation, salary and so on)
   - Account (cash, bank card, and credit card)
3) **The records could be deleted and edited at any time:**
   - Records of a whole day could be deleted at once
   - By deletion and addition, the records can be edited
4) **Users could view their most recent records by date, type, and account** 
5) **The system will provide a statistical report of users’ financial status to help users measure their budget plans:**
   - Monthly income and expenses by categories
   - Top daily expense and income
6) **The system allows budget setting:**
   - Alerts when expenses reach the budget 
   - The budget can be modified at any time
7) **The system allows users to search the budget left for a special event in the month. Users enter starting month and the system will tell the user:**
   - The total amount the user has saved in this month（which is the total amount of the difference between daily budget and daily expense), or
   - The amount over the budget
8) **The system allows users to set a password to ensure security. The system will require the password to login once it is set**
   
### How to Use?
#### Environment
- The Program runs well in the Linux system, with c++11 standard
   
#### Compilation
- Download all the sources to the **SAME** directory
- Use **Terminal Emulator** to compile by using command: **_make accountingpro_**
- You can now run the executable file **accountingpro**

#### Users Guidance
1) For the first-time login, you are required to set your username and password. The password will be **encrypted** first and then will be stored in *KeySecured.txt*. You are asked to fill in your password everytime you log in and you can make changes to them. The maximun length of username and password are 20 characters.
2) After successful log-in, you can see five options, **enter one number** to access one of the following options:
##### Change a Financial Record
- In this options, you can **enter 1 or 2** for further options:
   1) you can **add a record** by entering **integers** for the months, dates, categories, currency and account, and **integers or simple polynomials such as 1+4-9** for the amount
   2) you can **delete a record** by entering **integers** for the months and dates and choose the particular one. **Enter Y or N** for confirmation
##### View My Record
- In this options, you can **enter 1 or 2** for further options:
   1) you can view the latest 10 details of your financial record
   2) you can **enter a number representing the month** and see the report of that month containing balance of each categories and accounts, and the top income and expense
##### Budget
- In this options, you can **enter 1 or 2** for further options:
   1) you can **set or change your budget** by **entering a positive integer**
   2) you can **estimate how much you can spend** by **entering the starting month**, and the system will calculate total budget and total balance **from the starting month to the latest month in your record, standing for the current month**
##### Personal Information
- You can reset your username and your password. Noticed that you are required to enter the original password before you change it
##### Quit
- You've successfully log out

### Reference List
The idea was from **Li Shumin, TA of ENGG1340, the University of Hong Kong**.

### About Contributors
**Chen Jieying, Jenny** Member of Group 39, BEng year 1 student, the University of Hong Kong.    
email: **_jennycjy@connect.hku.hk_**

**Yan Junchen, Edward** Member of Group 39, BEng year 1 student, the University of Hong Kong.   
email: **_yjc3328@connect.hku.hk_**
