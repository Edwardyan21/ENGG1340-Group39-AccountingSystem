#include<iostream>
#include<string>
#include<fstream>
using namespace std;


//change type!!!!!!!!!!!!!!
void change(double &cur, string &type, string def){
	if (type != "HKD"){
		if (type == "CNY"){
			cur = 1.17 * cur;
		}
		else if (type == "USD"){
			cur = 7.84 * cur;
		}
		else if (type == "GBP"){
			cur = 10.14 * cur;
		}
		else if (type == "JPY"){
			cur = 0.070 * cur;
		}
		type = "HKD";
	}
	if (def != "HKD"){
		if (def == "CNY"){
			cur = cur / 1.17;
			type = "CNY";
		}
		else if (def == "USD"){
			cur = cur / 7.84;
			type = "USD";
		}
		else if (def == "GBP"){
			cur = cur / 10.14;
			type = "GBP";
		}
		else if (def == "JPY"){
			cur = cur / 0.070;
			type = "JPY";
		}
	}
}

int ChooseType(){
	int n;
	cout << "Please choose the currency type:" << endl;
	cout << "1. HKD  2. CNY  3. USD  4. GBP  5. JPY" << endl;
	cin >> n;
	while ( n < 1 && n > 5){
		cout << "This type is invalid. Choose one from the provided currency: ";
		cin >> n;
	}
	return n - 1;
}

int ChooseAccount(){
	int n;
	cout << "Please choose the account you want to use: " << endl;
	cout << "1. cash  2. bank card  3. credit card" << endl;
	cin >> n;
	while ( n < 1 && n > 3){
		cout << "This type is invalid. Choose one from the provided currency: ";
		cin >> n;
	}
	return n - 1;
}

double GetNum(){
	int n;
	cout << "Please enter the number: ";
	cin >> n;
	return n;
}


//password
string enc(string a){
	for (int i = 0; i < a.length(); i++){
		if (a[i] >= 'a' && a[i] <= 'z'){
			a[i] = (a[i] - 'a' + 5) % 26 + 'A';
		}
		else if (a[i] >= 'A' && a[i] <= 'Z'){
			a[i] = (a[i] - 'A' + 5) % 26 + 'a';
		}
		else if (a[i] >= '0' && a[i] <= '9'){
			a[i] = (a[i] - '0' + 3) % 10 + '0';
		}
	}
	return a;
} 

void setpw(){
	string pw;
	cout << "Please set a password: ";
	cin >> pw;
	pw = enc(pw);
	cout << pw;
	ofstream pout;
	pout.open("KeySecured.txt");
	pout << pw;
	pout.close();
}

string getpw(){
	string cpw;
	cout << "Please enter the password: ";
	cin >> cpw;
	return cpw;
}

bool checkpw(string cpw){
	ifstream pin;
	pin.open("KeySecured.txt");
	string pw;
	pin >> pw;
	if (pw == enc(cpw)) return true;
	else return false;
}

void start(){
	setpw();
	int n = 0;
	string cpw = getpw();
	while (!checkpw(cpw)){
		n++;
		if (n == 1){
			cout << "Wrong! You have 2 trails left. Please try again: ";
			cin >> cpw;
		}
		if (n == 2){
			cout << "Wrong! You have 1 trails left. Please try again: ";
			cin >> cpw;
		}
		if (n == 3){
			cout << "You have entered the wrong password for three times. You are forced to exit." << endl;
			exit(1);
		}
	}
	cout << "Welcome!" << endl;
}

void InputRec(){
	double cur;
	int i;
	string type;
	string t[5] = {"HKD", "CNY", "USD", "GBP", "JPY"};
	i = ChooseType();
	cur = GetNum();
	type = t[i];
}

string SetDef(){
	int n;
	cout << "Choose your default currency: " << endl;
	cout << "1. HKD  2. CNY  3. USD  4. GBP  5. JPY" << endl;
	cin >> n;
	string t[5] = {"HKD", "CNY", "USD", "GBP", "JPY"};
	return t[n - 1];
}

int main(){
	start();
	return 0;
} 
