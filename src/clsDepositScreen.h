#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;


class clsDepositScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client) {
		cout << "\nClient Card:";
		cout << "\n___________________\n";
		cout << "\nFirstName   : " << Client.FirstName;
		cout << "\nLastName    : " << Client.LastName;
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nEmail       : " << Client.Email;
		cout << "\nPhone       : " << Client.Phone;
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nPassword    : " << Client.PinCode;
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

	static string _ReadAccountNumber() {
		string AccountNumber = "";


		cout << "\nPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}


public:

	static void ShowDepositScreen() {
		double Amount = 0;
		char Answer = 'n';

		_DrawScreenHeader(" Deposit Screen");

		clsBankClient Client1 = clsBankClient::Find(_ReadAccountNumber());
		_PrintClient(Client1);

		cout << "\nPlease enter the deposit amount: ";
		Amount = clsInputValidate::ReadDblNumber();

		cout << "\n\nAre you sure you want to perform this operations? (y/n): ";
		cin >> Answer;

		if (tolower(Answer) == 'y') {
			Client1.Deposit(Amount);
			cout << "\nAmount Deposited Successfully.\n";
			cout << "\nNew Balance is: " << Client1.AccountBalance;

		}
		else cout << "\nOperation Cancelled.\n";



	}




};

