#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;

class clsUpdateClientScreen : clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient& Client) {
		cout << "\nEnter FirstName: ";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter LastName: ";
		Client.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Email: ";
		Client.Email = clsInputValidate::ReadString();
		cout << "\nEnter Phone: ";
		Client.Phone = clsInputValidate::ReadString();
		cout << "\nEnter PINCode: ";
		Client.PinCode = clsInputValidate::ReadString();
		cout << "\nEnter Account Balance: ";
		Client.AccountBalance = clsInputValidate::ReadDblNumber();
	}

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

public:

	static void ShowUpdateClientScreen() {

		if (!_CheckAccessRights(clsUser::enPermissions::ePerUpdateClient)) return;


		string AccountNumber = "";

		_DrawScreenHeader("Update Client Screen");

		cout << "\nPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		cout << "\nAre you sure you want to update this client y/n? ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			cout << "\n\nUpdate Client Info:";
			cout << "\n____________________\n";
			_ReadClientInfo(Client1);

			clsBankClient::enSaveStatus SaveResult = Client1.Save();


			switch (SaveResult) {

			case clsBankClient::enSaveStatus::SaveSuccessful:
				cout << "\nAccount Added Successfully :-)\n";
				_PrintClient(Client1);
				break;
			case clsBankClient::enSaveStatus::SaveFailedEmptyObject:
			{
				cout << "\nError account was not saved because it's Empty";
				break;

			}
			case clsBankClient::enSaveStatus::SaveFailedAccountNumberExists:
			{
				cout << "\nError account was not saved because account number is used!\n";
				break;
			}
			}

		}
	}



};

