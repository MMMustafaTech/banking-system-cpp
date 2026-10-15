#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"

using namespace std;


class clsTransferLogScreen : protected clsScreen
{


private:


	static void _PrintLogRecordLine(clsBankClient::strTransferLogInfo sTransferLogInfo) {

		cout << "\t\t| " << left << setw(22) << sTransferLogInfo.CurrentDateTime;
		cout << "| " << left << setw(7) << sTransferLogInfo.SourceAccount;
		cout << "| " << left << setw(7) << sTransferLogInfo.DestinationAccount;
		cout << "| " << left << setw(10) << sTransferLogInfo.Amount;
		cout << "| " << left << setw(12) << sTransferLogInfo.SourceBalance;
		cout << "| " << left << setw(12) << sTransferLogInfo.DestinationBalance;
		cout << "| " << left << setw(7) << sTransferLogInfo.Username << endl;
	}


public:

	static void ShowTransferLogList() {

		vector <clsBankClient::strTransferLogInfo> vTransferLogInfo = clsBankClient::GetTransferLogList();

		short SeparatorLength = 90;
		string Title = "Transfer Log List Screen";
		string SubTitle = " (" + to_string(vTransferLogInfo.size()) + ") Record(s)";

		_DrawScreenHeader(Title, SubTitle);


		cout << "\t\t" << string(SeparatorLength, '_') << endl;
		cout << "\n\t\t| " << left << setw(22) << "Date/Time";
		cout << "| " << left << setw(7) << "s.Acct";
		cout << "| " << left << setw(7) << "d.Acct";
		cout << "| " << left << setw(10) << "Amount";
		cout << "| " << left << setw(12) << "s.Balance";
		cout << "| " << left << setw(12) << "d.Balance";
		cout << "| " << left << setw(7) << "User" << endl;
		cout << "\t\t" << string(SeparatorLength, '_') << endl << endl;

		for (clsBankClient::strTransferLogInfo& TransferLogInfo : vTransferLogInfo) {
			_PrintLogRecordLine(TransferLogInfo);
		}
		cout << "\t\t" << string(SeparatorLength, '_') << endl;

	}





};

