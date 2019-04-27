#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//This function is used to check whether it is the first-time user.
bool is_firsttime(){
	ifstream fin;
	fin.open("UserName.txt");
	if (fin.fail()) return true;
	else return false;
}

//This function is used to store the username in a file so that it can be usedthe next time that the user wants to log in.
void store_username(string un){
	ofstream uout;
	uout.open("UserName.txt");
	uout << un;
	uout.close();
}

//This function is used to encrypt a password when storing it.
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

//This function is used to store the password in a file so that it can be used the next time that the user wants to log in.
void store_userkeys(string uk){
	uk = enc(uk);//encrypt the password
	ofstream pout;
	pout.open("KeySecured.txt");
	pout << uk;
	pout.close();
}

//This function is used to get the stored username from the file.
string get_username(){
	ifstream fin;
	string un;
	fin.open("UserName.txt");
	getline(fin, un);
	fin.close();
	return un;
}

//This function is used to get the stored password from the file.
string get_userkeys(){
	ifstream pin;
	string pw;
	pin.open("KeySecured.txt");
	getline(pin, pw);
	pin.close();
	return pw;
}
