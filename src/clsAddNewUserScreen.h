#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

using namespace std;

class clsAddNewUserScreen : protected clsScreen
{

private:

	static void _ReadUserInfo(clsUser& User) {
		cout << "\nEnter FirstName: ";
		User.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter LastName: ";
		User.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadString();
		cout << "\nEnter Phone: ";
		User.Phone = clsInputValidate::ReadString();
		cout << "\nEnter Password: ";
		User.Password = clsInputValidate::ReadString();
		
		cout << "\nEnter Permission:\n";
		User.Permissions = _AssignPermissions();

	}

	static void _PrintUser(clsUser User) {
		cout << "\nUser Card:";
		cout << "\n___________________\n";
		cout << "\n\nFirstName   : " << User.FirstName;
		cout << "\n\nLastName    : " << User.LastName;
		cout << "\n\nFull Name   : " << User.FullName();
		cout << "\n\nEmail       : " << User.Email;
		cout << "\n\nPhone       : " << User.Phone;
		cout << "\n\nUsername    : " << User.UserName;
		cout << "\n\nPassword    : " << User.Password;
		cout << "\n\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";
	}


	static int _AssignPermissions() {
		short Permissions = 0;
		char Accept = 'n';

		cout << "\nDo you want to give full access? y/n: ";
		cin >> Accept;
		if (tolower(Accept) == 'y') return -1;


		cout << "\nDo you want to give access to: \n";
		cout << "\n\nShow Client List? y/n: ";
		cin >> Accept;
		if (tolower(Accept) == 'y') Permissions = Permissions | clsUser::enPermissions::ePerShowClientList;
		cout << "\n\nAdd New Client? y/n: ";					 
		cin >> Accept;											 
		if (tolower(Accept) == 'y') Permissions = Permissions | clsUser::enPermissions::ePerAddNewClient;
		cout << "\n\nDelete Client? y/n: ";						 
		cin >> Accept;											 
		if (tolower(Accept) == 'y') Permissions = Permissions | clsUser::enPermissions::ePerDeleteClient;
		cout << "\n\nUpdate Client? y/n: ";						 
		cin >> Accept;											 
		if (tolower(Accept) == 'y') Permissions = Permissions | clsUser::enPermissions::ePerUpdateClient;
		cout << "\n\nFind Client? y/n: ";
		cin >> Accept;
		if (tolower(Accept) == 'y') Permissions = Permissions | clsUser::enPermissions::ePerFindClient;
		cout << "\n\nTransactions Menu? y/n: ";
		cin >> Accept;
		if (tolower(Accept) == 'y') Permissions = Permissions | clsUser::enPermissions::ePerTransactions;
		cout << "\n\nManage Users? y/n: ";
		cin >> Accept;
		if (tolower(Accept) == 'y') Permissions = Permissions | clsUser::enPermissions::ePerManageUsers;
		cout << "\n\nLogin Register? y/n: ";
		cin >> Accept;
		if (tolower(Accept) == 'y') Permissions = Permissions | clsUser::enPermissions::ePerLoginRegister;

		return Permissions;
	}



public:

	static void ShowAddNewUserScreen() {

		string Username;

		_DrawScreenHeader("Add New User Screen");

		cout << "\n\nPlease enter Username: ";
		Username = clsInputValidate::ReadString();
		while (clsUser::IsUserExist(Username)) {
			cout << "\nUsername is Already used, Choose another one: ";
			Username = clsInputValidate::ReadString();
		}
		clsUser NewUser = clsUser::GetAddNewUserObject(Username);

		_ReadUserInfo(NewUser);

		clsUser::enSaveStatus SaveResult = NewUser.Save();

		switch (SaveResult) {

		case clsUser::enSaveStatus::SaveSuccessful:
			cout << "\nAccount Added Successfully :-)\n";
			_PrintUser(NewUser);
			break;
		case clsUser::enSaveStatus::SaveFailedEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;

		}
		case clsUser::enSaveStatus::SaveFailedUserExists:
		{
			cout << "\nError account was not saved because account number is used!\n";
			break;
		}
		}
	}

	

};

