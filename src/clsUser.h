#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include "clsUtil.h"


using namespace std;

class clsUser : public clsPerson
{

private:

    enum _enMode { EmptyMode = 0, UpdateMode, AddNewMode };

    

    _enMode _Mode;

    string _DateTime;
    string _UserName;
    string _Password;
    int _Permissions;

    bool _MarkedForDelete = false;

    static const int EncryptDecryptKey = 5;

    string _GetOneLineOfLogInfo(string Delim = "#//#") {
        return clsDate::GetCurrentTime() + Delim + UserName + Delim + clsUtil::EncryptText(Password, EncryptDecryptKey) + Delim + to_string(Permissions);
    }


    static clsUser _ConvertLineDataToLoginRegisterUserObject(string LineData, string Delim = "#//#") {
        vector<string> vUserLoginData = clsString::Split(LineData, Delim);
        return clsUser(_enMode::UpdateMode, "", "", "", "", vUserLoginData[0],
            vUserLoginData[1], clsUtil::DecryptText(vUserLoginData[2], EncryptDecryptKey), stoi(vUserLoginData[3]));
    }

    static clsUser _ConvertLineDataToUserObject(string LineData, string Delim = "#//#") {
        vector<string> vUserData = clsString::Split(LineData, Delim);
        return clsUser(_enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3],
            vUserData[4], clsUtil::DecryptText(vUserData[5], EncryptDecryptKey), stoi(vUserData[6]));
    }

    static clsUser _GetEmptyUserObject() {
        return clsUser(_enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    static string _ConvertUserObjectToLineData(clsUser User, string Delim = "#//#") {
        return User.FirstName + Delim + User.LastName + Delim + User.Email + Delim + User.Phone + Delim + User.UserName
            + Delim + clsUtil::EncryptText(User.Password, EncryptDecryptKey) + Delim + to_string(User.Permissions);
    }

    static vector <clsUser> _LoadUsersDataFromFile() {

        fstream MyFile;

        vector <clsUser> _vUsers;

        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open()) {
            string Line;

            while (getline(MyFile, Line)) {

                _vUsers.push_back(_ConvertLineDataToUserObject(Line));
            }

            MyFile.close();
        }
        return _vUsers;
    }

    static vector <clsUser> _LoadLoginRegisterDataFromFile() {

        fstream MyFile;

        vector <clsUser> vLoginRegisters;

        MyFile.open("LoginRegister.txt", ios::in);

        if (MyFile.is_open()) {
            string Line;

            while (getline(MyFile, Line)) {

                vLoginRegisters.push_back(_ConvertLineDataToLoginRegisterUserObject(Line));
            }

            MyFile.close();
        }
        return vLoginRegisters;
    }

    static void _SaveUsersDataToFile(vector <clsUser> vUsers) {

        fstream MyFile;

        MyFile.open("Users.txt", ios::out);

        if (MyFile.is_open()) {

            for (clsUser& User : vUsers) if (!User.MarkedForDeletion()) MyFile << _ConvertUserObjectToLineData(User) << endl;


            MyFile.close();
        }
    }

    void _Update() {
        vector <clsUser> _vUsers;

        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& User : _vUsers) {

            if (User.UserName == _UserName) {
                User = *this;
                break;
            }

        }
        _SaveUsersDataToFile(_vUsers);
    }

    void _AddDataLineToFile(string DataLine) {

        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << DataLine << endl;

            MyFile.close();
        }
    }

    void _AddNew() {
        _AddDataLineToFile(_ConvertUserObjectToLineData(*this));
    }


public:


    clsUser(_enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName,
        string Password, int Permissions) : clsPerson(FirstName, LastName, Email, Phone) 
    {
        _Mode = Mode;
        _UserName = UserName;
        _Password = Password;
        _Permissions = Permissions;
    }

    clsUser(_enMode Mode, string FirstName, string LastName, string Email, string Phone, string DateTime, string UserName,
        string Password, int Permissions) : clsPerson(FirstName, LastName, Email, Phone) 
    {

        _Mode = Mode;
        _DateTime = DateTime;
        _UserName = UserName;
        _Password= Password;
        _Permissions = Permissions;
    }

    enum enPermissions {
        ePerAll = -1, ePerShowClientList = 1, ePerAddNewClient = 2, ePerDeleteClient = 4, ePerUpdateClient = 8, ePerFindClient = 16,
        ePerTransactions = 32, ePerManageUsers = 64, ePerLoginRegister = 128
    };


    bool IsEmpty()
    {
        return (_Mode == _enMode::EmptyMode);
    }

    bool MarkedForDeletion()
    {
        return _MarkedForDelete;
    }

    string GetUserName()
    {
        return _UserName;
    }

    void SetUserName(string UserName)
    {
        _UserName = UserName;
    }

    __declspec(property(get = GetUserName, put = SetUserName)) string UserName;

    void SetPassword(string Password)
    {
        _Password = Password;
    }

    string GetPassword()
    {
        return _Password;
    }
    __declspec(property(get = GetPassword, put = SetPassword)) string Password;

    void SetPermissions(int Permissions)
    {
        _Permissions = Permissions;
    }

    int GetPermissions()
    {
        return _Permissions;
    }
    __declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

    void SetDateTime(string DateTime)
    {
        _DateTime = DateTime;
    }

    string GetDateTime()
    {
        return _DateTime;
    }
    __declspec(property(get = GetDateTime, put = SetDateTime)) string DateTime;

    static clsUser Find(string UserName) {
        fstream MyFile;

        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open()) {
            string Line;

            while (getline(MyFile, Line)) {

                clsUser User = _ConvertLineDataToUserObject(Line);

                if (User.UserName == UserName) {
                    MyFile.close();
                    return User;
                }
            }



            MyFile.close();
        }
        return _GetEmptyUserObject();
    }


    static clsUser Find(string UserName, string Password) {
        fstream MyFile;

        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open()) {
            string Line;

            while (getline(MyFile, Line)) {

                clsUser User = _ConvertLineDataToUserObject(Line);

                if (User.UserName == UserName && User.Password == Password) {
                    MyFile.close();
                    return User;
                }
            }



            MyFile.close();
        }
        return _GetEmptyUserObject();
    }

    static bool IsUserExist(string UserName) {
        clsUser User = Find(UserName);
        return !User.IsEmpty();
    }


    enum enSaveStatus { SaveFailedEmptyObject = 0, SaveFailedUserExists, SaveSuccessful };

    enSaveStatus Save() {

        switch (_Mode) {

        case _enMode::EmptyMode:
            return enSaveStatus::SaveFailedEmptyObject;
            break;
        case _enMode::UpdateMode:
            _Update();
            return enSaveStatus::SaveSuccessful;
            break;

        case _enMode::AddNewMode:

            if (clsUser::IsUserExist(_UserName)) return enSaveStatus::SaveFailedUserExists;
            else {
                _AddNew();

                return enSaveStatus::SaveSuccessful;

            }
        }
    }

    static clsUser GetAddNewUserObject(string UserName) {
        return clsUser(_enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }


    bool Delete() {
        vector <clsUser> vUsers = _LoadUsersDataFromFile();

        for (clsUser& User : vUsers) {

            if (User.UserName == _UserName) {
                User._MarkedForDelete = true;
                break;
            }


        }


        _SaveUsersDataToFile(vUsers);

        *this = _GetEmptyUserObject();

        return true;
    }

    static vector <clsUser> GetUserList() {
        return _LoadUsersDataFromFile();
    }

    static vector <clsUser> GetLoginRegisterList() {
        return _LoadLoginRegisterDataFromFile();
    }



    void ClearObject() {
        *this = _GetEmptyUserObject();
    }


    bool CheckAccessPermission(enPermissions Permission) {

        if (this->_Permissions == enPermissions::ePerAll) return true;

        if ((Permission & this->_Permissions) == Permission) return true;
        return false;
    }

    

    void LoginRegister() {
        fstream MyFile;

        MyFile.open("LoginRegister.txt", ios::out | ios::app);

        if (MyFile.is_open()) {

            MyFile << _GetOneLineOfLogInfo() << endl;

            MyFile.close();
        }
    }

};

