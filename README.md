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
- We assume the customers are Hong Kong citizens, so the default unit is HKD

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
   
### Reference List
The idea was from **Li Shumin, TA of ENGG1340, the University of Hong Kong**.

### About Contributors
**Chen Jieying, Jenny** Member of Group 39, BEng year 1 student, the University of Hong Kong.    
email: **_jennycjy@connect.hku.hk_**

**Yan Junchen, Edward** Member of Group 39, BEng year 1 student, the University of Hong Kong.   
email: **_yjc3328@connect.hku.hk_**
