#pragma once
#include <iostream>
#include "clsUser.h"
#include "clsDate.h"
#include "Global.h"

using namespace std;

class clsScreen
{

protected:
	static void _DrawScreenHeader(string Title, string SubTitle = "", short DelimLength = 40) {
		system("cls");
		cout << "\t\t\t\t" << string(DelimLength, '-') << endl;
		cout << "\t\t\t\t\t" << Title << endl;
		if (SubTitle != "")cout << "\t\t\t\t\t\t" << SubTitle << endl;
		cout << "\t\t\t\t" << string(DelimLength, '-') << endl;

		cout << "\n\t\t\t\tUser:" << CurrentUser.UserName << endl;
		clsDate::GetSystemDate();
		cout << "\t\t\t\tDate:";
		_PrintSystemDate();
		cout << "\n";
	}

	static bool _CheckAccessRights(clsUser::enPermissions Permission) {
		system("cls");
		if (!CurrentUser.CheckAccessPermission(Permission)) {
			cout << "\t\t\t\t\t" << string(45, '_');
			cout << "\n\n\t\t\t\t\t  Access Denied! Please Contact your Admin.";
			cout << "\n\t\t\t\t\t" << string(45, '_');
			return false;
		}

		return true;
	}

	static void _PrintSystemDate() {

		clsDate Date = clsDate::GetSystemDate();
		Date.Print();
	}

};

