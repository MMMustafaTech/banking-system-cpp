#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUserListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

using namespace std;

class clsManageUsersScreen : protected clsScreen
{

private:
	static short _ReadManageUsersMenuOption() {
		cout << "\t\t\t\t";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 6);
		return Choice;
	}

	enum _enManageUsersMenuOptions { ListUsers = 1, AddNewUser, DeleteUser, UpdateUser, FindUser, MainMenu};

	static void _ReturnToManageUsersMenu() {
		cout << "\n\n\tPress any key to go back to Manage Users Menu...";
		system("pause>0");
		ShowManageUsersScreen();
	}

	static void _ShowListUsersScreen() {
		clsUserListScreen::ShowClientListScreen();
		_ReturnToManageUsersMenu();
	}

	static void _ShowAddNewUserScreen() {
		clsAddNewUserScreen::ShowAddNewUserScreen();
		_ReturnToManageUsersMenu();
	}

	static void _ShowDeleteUserScreen() {
		clsDeleteUserScreen::ShowDeleteUserScreen();
		_ReturnToManageUsersMenu();
	}

	static void _ShowUpdateUserScreen() {
		clsUpdateUserScreen::ShowUpdateUserScreen();
		_ReturnToManageUsersMenu();
	}

	static void _ShowFindUserScreen() {
		clsFindUserScreen::ShowFindUserScreen();
		_ReturnToManageUsersMenu();
	}


	static void PerformTransactionsMenuActions(_enManageUsersMenuOptions ManageUsersMenuOptions) {
		system("cls");

		switch (ManageUsersMenuOptions) {
			case _enManageUsersMenuOptions::ListUsers:
			_ShowListUsersScreen();
			break;
		case _enManageUsersMenuOptions::AddNewUser:
			_ShowAddNewUserScreen();
			break;
		case _enManageUsersMenuOptions::DeleteUser:
			_ShowDeleteUserScreen();
			break;
		case _enManageUsersMenuOptions::UpdateUser:
			_ShowUpdateUserScreen();
			break;
		case _enManageUsersMenuOptions::FindUser:
			_ShowFindUserScreen();
			break;
		case _enManageUsersMenuOptions::MainMenu:
			break;
		}
	}




public:

	static void ShowManageUsersScreen() {
		if (!_CheckAccessRights(clsUser::enPermissions::ePerTransactions)) return;
		system("cls");
		short DelimLength = 40;

		_DrawScreenHeader("  Manage Users Screen");


		cout << "\t\t\t\t" << string(DelimLength, '=') << endl;
		cout << "\t\t\t\t\t" << "Manage Users Menu" << endl;
		cout << "\t\t\t\t" << string(DelimLength, '=') << endl;



		cout << "\t\t\t\t   [1] List Users.\n";
		cout << "\t\t\t\t   [2] Add New User.\n";
		cout << "\t\t\t\t   [3] Delete User.\n";
		cout << "\t\t\t\t   [4] Update User.\n";
		cout << "\t\t\t\t   [5] Find User.\n";
		cout << "\t\t\t\t   [6] Main Menu.\n";
		cout << "\t\t\t\t" << string(DelimLength, '=') << endl;


		PerformTransactionsMenuActions((_enManageUsersMenuOptions)_ReadManageUsersMenuOption());
	}




};

