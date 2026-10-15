#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;


class clsTransferScreen : clsScreen
{


private:
	static void _PrintClient(clsBankClient Client) {
		cout << "\nClient Card:";
		cout << "\n___________________\n";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";
	}

	static clsBankClient _FindClientFromAccountNumber() {
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return Client;
	}



	static double _ReadAmount(clsBankClient SourceClient) {

		cout << "\nEnter Transfer Amount: ";
		double TransferAmount = clsInputValidate::ReadDblNumber();

		while (TransferAmount > SourceClient.AccountBalance) {
			cout << "\nAmount Exceeds the available Balance, Enter another Amount: ";
			TransferAmount = clsInputValidate::ReadDblNumber();
		}
		return TransferAmount;
	}

	static void _TransferOperation(clsBankClient& Client1, clsBankClient& Client2) {
		char Answer = 'n';

		double TransferAmount = _ReadAmount(Client1);


		cout << "\n\nAre you sure you want to perform this operations? (y/n): ";
		cin >> Answer;

		if (tolower(Answer) == 'y') {

			Client1.Transfer(TransferAmount, Client2);


			cout << "\nTransfer done successfully!\n";
		}
		else cout << "\nOperation Cancelled.\n";

	}


public:

	static void ShowTransferScreen() {


		_DrawScreenHeader("Transfer Screen");

		cout << "\nPlease Enter Account Number to Transfer From: ";

		clsBankClient Client1 = _FindClientFromAccountNumber();

		_PrintClient(Client1);

		cout << "\nPlease Enter Account Number to Transfer To: ";

		clsBankClient Client2 = _FindClientFromAccountNumber();

		_PrintClient(Client2);



		_TransferOperation(Client1, Client2);

		_PrintClient(Client1);

		_PrintClient(Client2);

	}

};

