#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeScreen.h"
#include "Global.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
private:

	static short _ReadMainMenuOption() {
		cout << "\t\t\t\t";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 10);
		return Choice;
	}

	enum _enMenuOptions{eShowClientList = 1, eAddNewClient, eDeleteClient,eUpdateClientInfo, 
		eFindClient, eTransactions, eManageUsers, eLoginRegister, eCurrencyExchange, eLogout};

	static void _ReturnToMainMenu() {
		cout << "\n\n\tPress any key to back to Main Menu...";
		system("pause>0");
		ShowMainScreen();
	}

	static void _ShowClientListScreen() {
		clsClientListScreen::ShowClientListScreen();
		_ReturnToMainMenu();
	}

	static void _AddNewClientScreen() {
		clsAddNewClientScreen::ShowAddNewClientScreen();
		_ReturnToMainMenu();
	}

	static void _DeleteClientScreen() {
		clsDeleteClientScreen::ShowDeleteClientScreen();
		_ReturnToMainMenu();
	}

	static void _UpdateClientInfoScreen() {
		clsUpdateClientScreen::ShowUpdateClientScreen();
		_ReturnToMainMenu();
	}

	static void _FindClientScreen() {
		clsFindClientScreen::ShowFindClientScreen();
		_ReturnToMainMenu();
	}

	static void _TransactionsScreen() {
		clsTransactionsScreen::ShowTransactionsScreen();
		_ReturnToMainMenu();
	}

	static void _ManageUsersScreen() {
		clsManageUsersScreen::ShowManageUsersScreen();
		_ReturnToMainMenu();
	}

	static void _LoginRegisterScreen() {
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
		_ReturnToMainMenu();
	}

	static void _CurrencyExchangeScreen() {
		clsCurrencyExchangeScreen::ShowCurrencyExchangeScreen();
		_ReturnToMainMenu();
	}

	static void _Logout() {
		system("cls");
		CurrentUser.ClearObject();
	}


	static void _PerformMenuAction(_enMenuOptions Option) {
		system("cls");
		switch (Option) {
		case _enMenuOptions::eShowClientList:
			_ShowClientListScreen();
			break;
		case _enMenuOptions::eAddNewClient:
			_AddNewClientScreen();
			break;
		case _enMenuOptions::eDeleteClient:
			_DeleteClientScreen();
			break;
		case _enMenuOptions::eUpdateClientInfo:
			_UpdateClientInfoScreen();
			break;
		case _enMenuOptions::eFindClient:
			_FindClientScreen();
			break;
		case _enMenuOptions::eTransactions:
			_TransactionsScreen();
			break;
		case _enMenuOptions::eManageUsers:
			_ManageUsersScreen();
			break;
		case _enMenuOptions::eLoginRegister:
			_LoginRegisterScreen();
			break;
		case _enMenuOptions::eCurrencyExchange:
			_CurrencyExchangeScreen();
			break;
		case _enMenuOptions::eLogout:
			_Logout();
			break;
		}
	}

public:

	static void ShowMainScreen() {
		short DelimLength = 40;
		_DrawScreenHeader("\tMain Screen");

		cout << "\t\t\t\t" << string(DelimLength, '=') << endl;
		cout << "\t\t\t\t\t\t" << "Main Menu" << endl;
		cout << "\t\t\t\t" << string(DelimLength, '=') << endl;

		cout << "\t\t\t\t   [1] Show Client List.\n";
		cout << "\t\t\t\t   [2] Add New Client.\n";
		cout << "\t\t\t\t   [3] Delete Client.\n";
		cout << "\t\t\t\t   [4] Update Client Info.\n";
		cout << "\t\t\t\t   [5] Find Client.\n";
		cout << "\t\t\t\t   [6] Transactions.\n";
		cout << "\t\t\t\t   [7] Manage Users.\n";
		cout << "\t\t\t\t   [8] Login Register.\n";
		cout << "\t\t\t\t   [9] Currency Exchange.\n";
		cout << "\t\t\t\t   [10] Logout.\n";
		cout << "\t\t\t\t" << string(DelimLength, '=') << endl;
		
		_PerformMenuAction((_enMenuOptions)_ReadMainMenuOption());
	}




};

