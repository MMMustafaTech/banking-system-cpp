#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsUser.h"
#include "Global.h"


using namespace std;



class clsLoginRegisterScreen : clsScreen
{


private:

	static void _PrintUserLoginRecordLine(clsUser User) {
		cout << "\t\t| " << left << setw(25) << User.DateTime;
		cout << "| " << left << setw(20) << User.UserName;
		cout << "| " << left << setw(10) << User.Password;
		cout << "| " << left << setw(12) << User.Permissions << endl;
	}


public:

	static void ShowLoginRegisterScreen() {

		if (!_CheckAccessRights(clsUser::enPermissions::ePerLoginRegister)) return;

		vector<clsUser> vUserLoginInfo = clsUser::GetLoginRegisterList();
		short SeparatorLength = 85;
		string Title = "User List Screen";
		string SubTitle = "  (" + to_string(vUserLoginInfo.size()) + ") User(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << "\t\t" << string(SeparatorLength, '_') << endl;
		cout << "\n\t\t| " << left << setw(25) << "Date/Time";
		cout << "| " << left << setw(20) << "Username";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permissions" << endl;
		cout << "\t\t" << string(SeparatorLength, '_') << endl << endl;

		for (clsUser& UserLoginInfo : vUserLoginInfo) {
			_PrintUserLoginRecordLine(UserLoginInfo);
		}

		cout << "\t\t" << string(SeparatorLength, '_') << endl;
	}






};

