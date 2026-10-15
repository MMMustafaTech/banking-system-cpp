#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"

using namespace std;

class clsDeleteUserScreen : protected clsScreen
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


	static void ShowDeleteUserScreen() {

        string Username = "";
        _DrawScreenHeader("Delete User Screen");

        cout << "\nPlease Enter Username: ";
        Username = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(Username))
        {
            cout << "\nUsername is not found, choose another one: ";
            Username = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(Username);
        _PrintUser(User);

        cout << "\nAre you sure you want to delete this user? y/n: ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            if (User.Delete())
            {
                cout << "\nUser Deleted Successfully :-)\n";
                _PrintUser(User);

            }
            else
            {
                cout << "\nError User Was not Deleted\n";
            }
        }


	}

};

