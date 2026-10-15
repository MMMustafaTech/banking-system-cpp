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

class clsLoginScreen : protected clsScreen
{

private:



	static bool _Login() {
		string Username = "";
		string Password = "";
		bool LoginFailed = false;
		short LoginTrials = 3;

		do {

			if (LoginFailed) { 
				LoginTrials--;
				cout << "\n\nInvalid Username/Password!";
				cout << "\nYou have " << LoginTrials << " Trials to login.";
				if (LoginTrials == 0) {
					cout << "\n\nYou are locked after 3 failed trials.\n\n";
					return false;
				}
			}


			cout << "\n\nEnter Username: ";
			Username = clsInputValidate::ReadString();

			cout << "\n\nEnter Password: ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(Username, Password);

			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		CurrentUser.LoginRegister();
		clsMainScreen::ShowMainScreen();
		return true;
	}

	


public:


	static bool ShowLoginScreen() {
		_DrawScreenHeader("\tLogin Screen");
		return _Login();
	}


	

};

