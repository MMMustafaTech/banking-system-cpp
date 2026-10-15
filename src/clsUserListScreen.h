#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUser.h"

using namespace std;


class clsUserListScreen : protected clsScreen
{


private:
	static void _PrintUserRecordLine(clsUser User) {
		cout << "\t\t| " << left << setw(10) << User.UserName;
		cout << "| " << left << setw(20) << User.FullName();
		cout << "| " << left << setw(10) << User.Phone;
		cout << "| " << left << setw(20) << User.Email;
		cout << "| " << left << setw(10) << User.Password;
		cout << "| " << left << setw(12) << User.Permissions << endl;
	}

public:
	static void ShowClientListScreen() {
		vector<clsUser> vUserInfo = clsUser::GetUserList();
		short SeparatorLength = 85;
		string Title = "User List Screen";
		string SubTitle = "  (" + to_string(vUserInfo.size()) + ") User(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << "\t\t" << string(SeparatorLength, '_') << endl;
		cout << "\n\t\t| " << left << setw(10) << "UserName";
		cout << "| " << left << setw(20) << "Full Name";
		cout << "| " << left << setw(10) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permissions" << endl;
		cout << "\t\t" << string(SeparatorLength, '_') << endl << endl;

		for (clsUser& sUserInfo : vUserInfo) {
			_PrintUserRecordLine(sUserInfo);
		}

		cout << "\t\t" << string(SeparatorLength, '_') << endl;


	}



};

