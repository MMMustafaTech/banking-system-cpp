#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"





class clsFindUserScreen : protected clsScreen
{

private:

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

public:


	static void ShowFindUserScreen() {
		string Username = "";

		_DrawScreenHeader("Find User Screen");

		cout << "\nPlease Enter Username: ";
		Username = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(Username))
		{
			cout << "\nUsername is not found, choose another one: ";
			Username = clsInputValidate::ReadString();
		}

		clsUser User = clsUser::Find(Username);

		if (!User.IsEmpty()) cout << "\nUser Found!\n";
		else cout << "\nUser was not Found.\n";


		_PrintUser(User);
	}
};

