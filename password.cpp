#include<iostream>
#include<string>
#include<fstream>
using namespace std;

bool is_firsttime(){
	ifstream fin;
	fin.open("UserName.txt");
	if (fin.fail()) return true;
	else return false;
}

void store_username(string un){
	ofstream uout;
	uout.open("UserName.txt");
	uout << un;
	uout.close();
}

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

void store_userkeys(string uk){
	uk = enc(uk);
	ofstream pout;
	string pw;
	pout.open("KeySecured.txt");
	pout << pw;
	pout.close();
}

string get_username(){
	ifstream fin;
	string un;
	fin.open("UserName.txt");
	getline(fin, un);
	fin.close();
	return un;
}

string get_userkeys(){
	ifstream pin;
	string pw;
	pin.open("KeySecured.txt");
	getline(pin, pw);
	pin.close();
	return pw;
}
