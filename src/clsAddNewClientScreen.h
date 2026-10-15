#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;

class clsAddNewClientScreen : protected clsScreen
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
	
	static void ShowAddNewClientScreen() {
		if (!_CheckAccessRights(clsUser::enPermissions::ePerAddNewClient)) return;


		string AccountNumber;

		_DrawScreenHeader("Add New Client Screen");

		cout << "\n\nPlease enter account number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber)) {
			cout << "\nAccount Number is Already used, Choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

		_ReadClientInfo(NewClient);

		clsBankClient::enSaveStatus SaveResult = NewClient.Save();

		switch (SaveResult) {

		case clsBankClient::enSaveStatus::SaveSuccessful:
			cout << "\nAccount Added Successfully :-)\n";
			_PrintClient(NewClient);
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

};

