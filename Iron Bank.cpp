// Iron Bank.cpp : Defines the entry point for the console application.
//_CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "accounts.h"
#include"customer.h"
#include "admin.h"
#include "id_genC.h"
#include "transaction.h"
#include "id_genE.h"
#include "id_genA.h"
#include <cstdlib>
#include<conio.h>
#include<Windows.h>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
id_genC idGenC;
id_genA idGenA;
id_genE idGenE;
void loading() {
	system("cls");
	cout << "\n\n...LOADING...\n________________\n\n\n\n";
	for (int i = 0; i<25; i++)
	{
		
		//cout << "\n" << "\n";
		
		cout << ">>";
		Sleep(50);
	}
	system ("cls");
}
void exiting() {
	system("cls");
	cout << "\n\n== developed by : \n";
	cout << "1. Md.Zahidul Islam, 160041010\n";
	cout << "2. Shafkat Rahman Farabi, 160041002\n";
	cout << "3. Ha - mim Hamid, 160041047\n";
	cout << "4. Faiyaz Mahmud Samin, 160041009\n";
	cout << "\n\n\n...QUITING...\n________________\n\n\n\n";
	for (int i = 0; i<25; i++)
	{

		//cout << "\n" << "\n";

		cout << ">>";
		Sleep(50);
	}
	system("cls");
}
void begin() {
	system("cls");
	cout << endl << endl ;
	cout << "Project: THE IRON BANK" << endl << endl;
	cout << "_________________________" << endl<<endl;

	cout << " A banking system which includes using the system as various\n kinds of users with various level privileges.\n";
	cout<<	" User can enter the program as Admin, Employee or Customer.\nThese 3 kinds of users will have different privileges.\n";
	cout << " An admin can add new admins, employees & customers or modify \ntheir information.\n";
	cout << " User can get a record of all the events like creation or \ndeletion of customers by him or other employees.\n";
	cout << " User can access all the accounts and see the information of \nthat account or other user’s profile.\n";
	cout << " Employees can add new customers or modify customer information.\nHe can see all the customer details except the private ones.\n";
	cout << " Customers can add or access accounts.Logging in an account,\n they can withdraw, deposit or transfer money.\n";
	cout << "\n\n\n";
	cout << "== developed by : \n";
	cout << "1. Md.Zahidul Islam, 160041010\n";
	cout << "2. Shafkat Rahman Farabi, 160041002\n";
	cout << "3. Ha - mim Hamid, 160041047\n";
	cout << "4. Faiyaz Mahmud Samin, 160041009\n";
	
	cout << "\n\n\n...INITIATING......\n_______________\n\n";
	for (int i = 0; i<25; i++)
	{

		//cout << "\n" << "\n";

		cout << ">>";
		Sleep(160);
	}
	
	system("cls");
}
bool checkNumber1(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] < 48 || s[i]>57) return false;
	}
	return true;
}
int stooi1(string s)
{
	int id = 0;
	int h = 1;
	for (int i = (int)(s.size() )-1; i >= 0; i--)
	{
		id += (s[i] * h);
		h *= 10;
	}
	return id;
}

void employee_access()
{

	int id_;
	string sid_;
	char password[30], c = ' ';
	cout << " _____________________________\n";
	while (1)
	{
		cout << " Enter ID : ";
		cin >> sid_;
		if (checkNumber1(sid_))break;
		else { cout << "\ninvalid input... Enter again... "; }
	}
	id_ = stoi(sid_);
	cout << " Enter Pin(4-digit) : ";
	int i = 0;
	while (c != 13)
	{
		c = _getch();
		cout << "*";
		//c = getchar();
		password[i] = c;
		i++;
		if (i > 3)break;
		//fflush(stdin);
	}
	password[i] = '\0';
	int pin = atoi(password);

	fflush(stdin);
	cin.clear();
	employee Employee;
	bool flag = false;
	fstream infile;
	infile.open("employee.dat", ios::binary | ios::app | ios::in);
	if (!infile)
	{
		cout << "employee file could not be opened !!" << endl;
		return;
	}

	while (infile.read(reinterpret_cast<char*>(&Employee), sizeof employee))
	{
		int id = Employee.get_id();
		int pin_ = Employee.get_pin();
		//cout << id << " " << id_ << " " << pin << " " << pin_ << endl;
		if (id == id_ && pin == pin_)
		{
			//cout << "found" << endl;
			flag = true;
			break;
		}


	}
	//system("pause");
	//cout << "finished Searching\n";
	infile << flush;
	infile.close();
	if (!flag)    //return;
	{
		cout << "\n\nUsername or password is Wrong ! -_-\n\n";
		system("pause");
		return;
	}
	int c_idd;

	loading();
	bool q = false;
	while (1) {
		system("cls");
		cout << "\n\t== Welcome " << Employee.get_name() << " .....\n";
		cout << " _______________________________\n\n";
		cout << " What do you want to do? == >\n";
		cout << " 1. Add Customer\n";
		cout << " 2. Delete Customer\n";
		cout << " 3. Show Transaction\n";
		cout << " 4. Log Out\n";
		cout << "\n == enter a choice: \t";
		//cin>>flush;

		cin.clear();
		fflush(stdin);

		int cc;
		cin >> cc;
		
		switch (cc) {
	
		case 1:
			c_idd = idGenC.get_id();
			Employee.create_customer(c_idd);
			break;
		case 2:
			cout << " Enter the ID of the Customer to be Deleted : ";
			cin >> c_idd;
			Employee.delete_customer(c_idd);
			break;
		case 3:
			//show all transactions
		{cout << "\nTransactions.......\n";
		cout << "=====================";
		fstream infile0;
		infile0.open("transactions.dat", ios::binary | ios::in | ios::app);
		transaction Trans;
		while (infile0.read(reinterpret_cast<char *>(&Trans), sizeof Trans))
		{

			Trans.show();

		}
		infile0.close();
		cout << endl << endl;
		system("pause");
		}
			break;
		case 4:
			q = true;
			break;

		}

		if (q) {
			//cin.clear();
			break;
		}

	}



}
void customer_access()
{
	//clear screen 
	//enter using customer id and pass
	//options create account, enter into account,transactions
	int id_;
	string sid_;
	char password[30], c = ' ';
	cout << " _____________________________\n";
	while (1)
	{
		cout << " Enter ID : ";
		cin >> sid_;
		if (checkNumber1(sid_))break;
		else { cout << "\ninvalid input... Enter again... "; }
	}
	id_ = stoi(sid_);
	
	cout << " Enter Pin(4-digit) : ";
	int i = 0;
	while (c != 13)
	{
		c = _getch();
		cout << "*";
		password[i] = c;
		i++;
		if (i > 3)break;
	}
	password[i] = '\0';
	int pin = atoi(password);
	fflush(stdin);
	cin.clear();
	customer Customer;
	bool flag = false;
	fstream infile;
	infile.open("customer.dat", ios::binary | ios::app | ios::in);
	if (!infile)
	{
		cout << "customer file could not be opened !!" << endl;
		return;
	}

	while (infile.read(reinterpret_cast<char*>(&Customer), sizeof Customer))
	{
		int id = Customer.get_id();
		int pin_ = Customer.get_pin();
		//cout << id << " " << id_ << " " << pin << " " << pin_ << endl;
		if (id == id_ && pin == pin_)
		{
			flag = true;
			break;
		}
		

	}
	infile << flush;
	infile.close();
	if (!flag)  
	{
		cout << "\n\nUsername or password is Wrong ! -_-\n\n";
		system("pause");
		return;
	}
	loading();
	bool q = false;
	while (1) {
		system("cls");
		cout << "\n\t== Welcome  " << Customer.get_name() << " .....\n";
		cout << " _______________________________\n\n";
		cout << " What do you want to do? == >\n";
		cout << " 1. Add Account\n";
		cout << " 2. Delete Account\n";
		cout << " 3. Perform / Show Transactions\n";
		cout << " 4. Log Out\n";
		cout << "\n == enter a choice: \t";
		//cin>>flush;

		cin.clear();
		fflush(stdin);

		int cc;
		cin >> cc;
		int a_id,c_id;
		switch (cc) {
		case 1:
			c_id = Customer.get_id();
		    a_id = idGenA.get_id();
			//cout << "c_id " << c_id << " a_id " << a_id << endl;
			Customer.create_account( c_id, a_id);
			break;
		case 2:
	
			cout << " Enter the ID of the account to be Deleted : ";
			cin >> a_id;
			Customer.delete_account( a_id);
			break;
		case 3:
			Customer.access_account();
			break;
		case 4:
			q = true;
			break;

		}

		if (q) {
			break;
		}

	}
}
void admin_access()
{
	int id_;
	string sid_;
	char password[30],c=' ';
	cout << " _____________________________\n";
	while(1)
	{
		cout << " Enter ID : ";
		cin >> sid_;
		if (checkNumber1(sid_))break;
		else { cout << "\ninvalid input... Enter again... "; }
	}
	id_ = stoi(sid_);
	
	cout << " Enter Pin(4-digit) : ";
	int i = 0;
	while (c != 13)
	{
		c = _getch();
		cout << "*";
		//c = getchar();
		password[i] = c;
		i++;
		if (i > 3)break;
		//fflush(stdin);
	}
	password[i] = '\0';
	int pin = atoi(password);

	fflush(stdin);
	cin.clear();
	admin Admin;
	bool flag = false;
	fstream infile;
	infile.open("admin.dat", ios::binary | ios::app | ios::in);
	if (!infile)
	{
		cout << "Admin file could not be opened !!" << endl;
		return;
	}

	while (infile.read(reinterpret_cast<char*>(&Admin), sizeof admin))
	{
		int id = Admin.get_id(); 
		int pin_ = Admin.get_pin();
		//cout << id << " " << id_ << " " << pin << " " << pin_ << endl;
		if (id == id_ && pin == pin_)
		{
			//cout << "found" << endl;
			flag = true;
			break;
		}
		
	}
	//system("pause");
	//cout << "finished Searching\n";
	infile << flush;
	infile.close();
	if (!flag)    //return;
	{
		cout << "\n\nUsername or password is Wrong ! -_-\n";
		system("pause");
		return;
	}
	
	loading();
	bool q = false;
	while (1) {
		system("cls");
		cout << "\n\t== Welcome " << Admin.get_name() << " .....\n";
		cout << " _______________________________\n\n";
		cout << " What do you want to do? == >\n";
		cout << " 1. Add Admin\n";
		cout << " 2. Add Employee\n";
		cout << " 3. Add Customer\n";
		cout << " 4. Delete Employee\n";
		cout << " 5. Delete Customer\n";
		cout << " 6. Show Transactions\n";
		cout << " 7. Log Out\n";
		cout << "\n == enter a choice: \t";
		//cin>>flush;
		
		cin.clear();
		fflush(stdin);

		int cc;
		cin >> cc;
		int c_id,e_id,a_id;
		switch (cc) {
		case 1:
			a_id = idGenE.get_id();
			Admin.create_admin(a_id);
			break;
		case 2:
			e_id = idGenE.get_id();
			Admin.create_employee(e_id);
			break;
		case 3:
			c_id = idGenC.get_id();
			Admin.create_customer( c_id);
			break;
		case 4:
			cout << " Enter the ID of the Employee to be Deleted : ";
			cin >> e_id;
			Admin.delete_employee(e_id);
			break;
		case 5:
			cout << " Enter the ID of the Customer to be Deleted : ";
			cin >> c_id;
			Admin.delete_customer(c_id);
			break;
		case 6: 
			//show all transactions
		{   cout << "Transactions.......\n";
			cout << "=====================";
			fstream infile0;
			infile0.open("transactions.dat", ios::binary | ios::in | ios::app);
			transaction Trans;
			while (infile0.read(reinterpret_cast<char *>(&Trans), sizeof Trans))
			{

				Trans.show();

			}
			infile0.close();
			cout << endl << endl;
			system("pause"); 
		}
		case 7:
			q = true;
			break;
		
		}

		if (q) {
			//cin.clear();
			break;
		}

	}
	

}
void welcome()
{
	//cin.clear();
	//fflush(stdin);
	cout << "\n\n\t\t===        THE IRON BANK      ===\n";
	cout << "\t\t=================================\n\n";
	cout << " Press any key to continue...\n";
	//fflush(stdin);
	getchar();
	
}
int  menu()
{
	cout << "Login as == >\n";
	cout << " 1. Admin\n";
	cout << " 2. Employee\n";
	cout << " 3. Customer\n";
	cout << " 4. Info\n";
	cout << " 5. Quit\n";
	cout<< "\n == enter a choice: \t";
	int c;
	while (1) {
		cin >> c;
		cout << "\n";
		//if (c > 4 || c < 1) { cout << "\n\ninvalid input...\n"; system("pause"); cin.clear();  system("cls"); cin.clear(); fflush(stdin); welcome(); menu(); }
		if (c <= 5 && c >= 1)break;
		else cout << "..invalid input..enter again.. ";
	}
	return c;
}
void create_account()
{
	cout << "\n account is creating...\n";

}
void show_accounts()
{
	cout << "\n accounts are shown...\n";
}
void systemAdminGen()
{
	
	admin temp;
	bool flag = false;
	fstream infile;
	infile.open("admin.dat", ios::binary|ios::app|ios::in);
	if (!infile)
	{
		cout << "Admin file could not be opened !!" << endl;
		return;
	}
	while (infile.read(reinterpret_cast<char*>(&temp), sizeof admin))
	{
		if (temp.get_id() == 1234)
		{
			//cout << "admin nai \n";
			flag = true;
		}
	}
	infile<<flush;
	infile.close();
	if (flag)   
	{
		
		return; 
	}
	//cout << "admin nai \n";
	int id = 1234;
	char name[] = "system";
	int pin = 1234;
	char phone[] = "";
	admin system(1234, pin ,name ,phone);
	fstream outfile;
	outfile.open("admin.dat", ios::binary|ios::out);
	outfile.write(reinterpret_cast<char *>(&system), sizeof(admin) );
	outfile.flush();
	outfile.close();
	

}
void id_GenC()
{
	fstream infile;
	infile.open("idgenC.dat", ios::binary | ios::in|ios::app);
	if (!infile)
	{
		cout << "idgenC File could not be open !!"<<endl;
		return;
	}
	bool flag = true;
	while (!infile.eof())
	{
		infile.read(reinterpret_cast<char *>(&idGenC), sizeof idGenC);
	}
	infile.close();
}
void id_GenA()
{
	fstream infile;
	infile.open("idgenA.dat", ios::binary | ios::in|ios::app);
	if (!infile)
	{
		cout << "idgenA File could not be open !!" << endl;
		return;
	}
	bool flag = true;
	while (!infile.eof())
	{
		infile.read(reinterpret_cast<char *>(&idGenA), sizeof idGenA);
	}
	infile.close();
}
void id_GenE()
{
	fstream infile;
	infile.open("idgenE.dat", ios::binary | ios::in |ios::app);
	if (!infile)
	{
		cout << "idgenE File could not be open !!" << endl;
		return;
	}
	bool flag = true;
	while (!infile.eof())
	{
		infile.read(reinterpret_cast<char *>(&idGenE), sizeof idGenE);
	}
	infile.close();
}
void see_everything()
{
	cout << "Transactions.......\n";
	cout << "=====================";
	fstream infile0;
	infile0.open("transactions.dat", ios::binary | ios::in | ios::app);
	transaction Trans;
	while (infile0.read(reinterpret_cast<char *>(&Trans), sizeof Trans))
	{
		
		Trans.show();
		
	}
	infile0.close();
	cout << endl << endl;
	cout << "accounts...........\n";
	fstream infile1;
	infile1.open("accounts.dat", ios::binary | ios::in|ios::app);
	accounts Account;
	while (infile1.read(reinterpret_cast<char *>(&Account), sizeof Account))
	{
		cout << "=======\n";
		cout << Account.get_id() << " " << Account.get_c_id() << " " << Account.get_amount() << endl;
		cout << "========\n";
	}
	infile1.close();
	cout << endl << endl;
	cout << "Customers....\n";
	fstream infile2;
	infile2.open("customer.dat", ios::binary | ios::in |ios::app);
	customer Customer;
	while (infile2.read(reinterpret_cast<char *>(&Customer), sizeof Customer))
	{
		cout << "=======\n";
		cout << Customer.get_id() << " " << Customer.get_pin() << " " << Customer.get_name() << endl;
		cout << "========\n";
	}
	infile2.close();

	cout << endl << endl;
	cout << "Admins....\n";
	fstream infile3;
	infile3.open("admin.dat", ios::binary | ios::in | ios::app);
	admin Admin;
	while (infile3.read(reinterpret_cast<char *>(&Admin), sizeof Admin))
	{
		cout << "=======\n";
		cout << Admin.get_id() << " " << Admin.get_pin() << " " << Admin.get_name() << endl;
		cout << "========\n";
	}
	infile3.close();

	cout << endl << endl;
	cout << "Employees....\n";
	fstream infile4;
	infile4.open("employee.dat", ios::binary | ios::in | ios::app);
	employee Employee;
	while (infile4.read(reinterpret_cast<char *>(&Employee), sizeof Employee))
	{
		cout << "=======\n";
		cout << Employee.get_id() << " " << Employee.get_pin() << " " << Employee.get_name() << endl;
		cout << "========\n";
	}
	infile4.close();
	cout << "_________________________________________\n";
	cout << "___________________________________________\n";
}

int main()
{
	systemAdminGen();
	id_GenC();
	id_GenE();
	id_GenA();
	//see_everything();
	//system("pause");
	begin();
	//return 0;
	bool q = false;
	while (1) {
		system("cls");
		welcome();
		int choice = menu();
		
		switch (choice) {
		case 3:
			customer_access();
			break;
		case 1:
			admin_access();
			break;
		case 2:
			employee_access();
			break;
		case 4:
			system("cls");
			cout << endl << endl;
			cout << "Project: THE IRON BANK" << endl << endl;
			cout << "_________________________" << endl << endl;

			cout << " A banking system which includes using the system as various\n kinds of users with various level privileges.\n";
			cout << " User can enter the program as Admin, Employee or Customer.\nThese 3 kinds of users will have different privileges.\n";
			cout << " An admin can add new admins, employees & customers or modify \ntheir information.\n";
			cout << " User can get a record of all the events like creation or \ndeletion of customers by him or other employees.\n";
			cout << " User can access all the accounts and see the information of \nthat account or other user’s profile.\n";
			cout << " Employees can add new customers or modify customer information.\nHe can see all the customer details except the private ones.\n";
			cout << " Customers can add or access accounts.Logging in an account,\n they can withdraw, deposit or transfer money.\n";
			cout << "\n\n\n";
			cout << "== made by : \n";
			cout << "1. Md.Zahidul Islam, 160041010\n";
			cout << "2. Shafkat Rahman Farabi, 160041002\n";
			cout << "3. Ha - mim Hamid, 160041047\n";
			cout << "4. Faiyaz Mahmud Samin, 160041009\n\n\n";
			system("pause");
			break;
		case 5:
			q = true;
			break;
		}
		
		if (q) {
			break;
		}

	}
    exiting();
	cout << "\n\n";
	//system("pause");
	return 0;
}