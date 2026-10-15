#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

using namespace std;

class clsTransactionsScreen : protected clsScreen
{

private:
	static short _ReadTransactionsMenuOption() {
		cout << "\t\t\t\t";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 6);
		return Choice;
	}

	enum _enTransactionsMenuOptions{Deposit = 1, Withdraw, TotalBalances, Transfer, TransferLog, MainMenu};

	static void _ReturnToTransactionsMenu() {
		cout << "\n\n\tPress any key to go back to Transactions Menu...";
		system("pause>0");
		ShowTransactionsScreen();
	}

	static void _ShowDepositScreen() {
		clsDepositScreen::ShowDepositScreen();
		_ReturnToTransactionsMenu();
	}

	static void _ShowWithdrawScreen() {
		clsWithdrawScreen::ShowWithdrawScreen();
		_ReturnToTransactionsMenu();
	}

	static void _ShowTotalBalancesScreen() {
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
		_ReturnToTransactionsMenu();
	}

	static void _ShowTransferScreen() {
		clsTransferScreen::ShowTransferScreen();
		_ReturnToTransactionsMenu();
	}

	static void _ShowTransferLogScreen() {
		clsTransferLogScreen::ShowTransferLogList();
		_ReturnToTransactionsMenu();
	}


	static void _PerformTransactionsMenuActions(_enTransactionsMenuOptions TransactionsMenuOptions) {
		system("cls");

		switch (TransactionsMenuOptions) {

		case _enTransactionsMenuOptions::Deposit:
			_ShowDepositScreen();
			break;
		case _enTransactionsMenuOptions::Withdraw:
			_ShowWithdrawScreen();
			break;
		case _enTransactionsMenuOptions::TotalBalances:
			_ShowTotalBalancesScreen();
			break;
		case _enTransactionsMenuOptions::Transfer:
			_ShowTransferScreen();
			break;
		case _enTransactionsMenuOptions::TransferLog:
			_ShowTransferLogScreen();
			break;
		case _enTransactionsMenuOptions::MainMenu:
			break;
		}
	}




public:

	static void ShowTransactionsScreen() {
		if (!_CheckAccessRights(clsUser::enPermissions::ePerTransactions)) return;

		system("cls");

		short DelimLength = 40;

		_DrawScreenHeader("  Transactions Screen");


		cout << "\t\t\t\t" << string(DelimLength, '=') << endl;
		cout << "\t\t\t\t\t" << "Transactions Menu" << endl;
		cout << "\t\t\t\t" << string(DelimLength, '=') << endl;
		


		cout << "\t\t\t\t   [1] Deposit.\n";
		cout << "\t\t\t\t   [2] Withdraw.\n";
		cout << "\t\t\t\t   [3] Total Balances.\n";
		cout << "\t\t\t\t   [4] Transfer.\n";
		cout << "\t\t\t\t   [5] Transfer Log.\n";
		cout << "\t\t\t\t   [6] Main Menu.\n";
		cout << "\t\t\t\t" << string(DelimLength, '=') << endl;


		_PerformTransactionsMenuActions((_enTransactionsMenuOptions)_ReadTransactionsMenuOption());
	}




};

