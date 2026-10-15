#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsUser.h"

using namespace std;

class clsClientListScreen : protected clsScreen
{
private:
	static void _PrintClientRecordLine(clsBankClient Client) {
		cout << "\t\t| " << left << setw(14) << Client.AccountNumber();
		cout << "| " << left << setw(10) << Client.PinCode;
		cout << "| " << left << setw(20) << Client.FullName();
		cout << "| " << left << setw(13) << Client.Phone;
		cout << "| " << left << setw(15) << Client.AccountBalance << endl;
	}

public:
	static void ShowClientListScreen() {

		if (!_CheckAccessRights(clsUser::enPermissions::ePerShowClientList)) return;


		vector<clsBankClient> vClientInfo = clsBankClient::GetUserList();
		short SeparatorLength = 85;
		string Title = "Client List Screen";
		string SubTitle = "  (" + to_string(vClientInfo.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << "\t\t" << string(SeparatorLength, '_') << endl;
		cout << "\n\t\t| " << left << setw(14) << "Account Number";
		cout << "| " << left << setw(10) << "PIN Code";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(13) << "Phone Number";
		cout << "| " << left << setw(15) << "Account Balance" << endl;
		cout << "\t\t" << string(SeparatorLength, '_') << endl << endl;

		for (clsBankClient& sClientInfo : vClientInfo) {
			_PrintClientRecordLine(sClientInfo);
		}

		cout << "\t\t" << string(SeparatorLength, '_') << endl;


	}
};

