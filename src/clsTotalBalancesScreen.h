#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsUtil.h"

using namespace std;


class clsTotalBalancesScreen : protected clsScreen
{


private:
	static void _PrintClientRecordLine(clsBankClient Client) {
		cout << "\t\t| " << left << setw(14) << Client.AccountNumber();
		cout << "| " << left << setw(20) << Client.FullName();
		cout << "| " << left << setw(15) << Client.AccountBalance << endl;
	}

public:

	static void ShowTotalBalancesScreen() {
		vector<clsBankClient> vClientInfo = clsBankClient::GetUserList();
		short SeparatorLength = 85;
		string Title = "Balances List Screen";
		string SubTitle = "  (" + to_string(vClientInfo.size()) + ") Client(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << "\t\t" << string(SeparatorLength, '_') << endl;
		cout << "\n\t\t| " << left << setw(14) << "Account Number";
		cout << "| " << left << setw(20) << "Client Name";
		cout << "| " << left << setw(15) << "Account Balance" << endl;
		cout << "\t\t" << string(SeparatorLength, '_') << endl << endl;

		for (clsBankClient& sClientInfo : vClientInfo) {
			_PrintClientRecordLine(sClientInfo);
		}

		cout << "\t\t" << string(SeparatorLength, '_') << endl;

		double TotalBalances = clsBankClient::CalculateTotalBalances();

		cout << endl << setw(60) << left <<  "" << "Total Balances = " << TotalBalances << endl;

		cout << setw(50) << left << "" << "( " << clsUtil::NumberToText(TotalBalances) << ')';
	}




};

