#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>

#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"


using namespace std;


class clsBankClient : public clsPerson
{
private:
	
	enum enMode { EmptyMode = 0, UpdateMode, AddNewMode};

	enMode _Mode;
    bool _MarkForDelete = false;

	string _AccountNumber;
	string _PINCode;
	float _AccountBalance;

    struct strTransferLogInfo;


	static clsBankClient _ConvertLineDataToClientObject(string LineData, string Delim = "#//#") {
		vector<string> vClientData = clsString::Split(LineData, Delim);
		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2], vClientData[3],
			vClientData[4], vClientData[5], stod(vClientData[6]));
	}

    static strTransferLogInfo _ConvertLineDataToTransferLogStruct(string LineData, string Delim = "#//#") {
        vector<string> vTransferLogData = clsString::Split(LineData, Delim);
        strTransferLogInfo sTransferLogStruct;

        sTransferLogStruct.CurrentDateTime = vTransferLogData[0];
        sTransferLogStruct.SourceAccount = vTransferLogData[1];
        sTransferLogStruct.DestinationAccount = vTransferLogData[2];
        sTransferLogStruct.Amount = stoi(vTransferLogData[3]);
        sTransferLogStruct.SourceBalance = stoi(vTransferLogData[4]);
        sTransferLogStruct.DestinationBalance = stoi(vTransferLogData[5]);
        sTransferLogStruct.Username = vTransferLogData[6];

        return sTransferLogStruct;
    }

	static clsBankClient _GetEmptyClientObject() {
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}


    string _GetOneLineOfTransferLogInfo(clsBankClient DestinationClient, double Amount, string Delim = "#//#") {
        return clsDate::GetCurrentTime() + Delim + AccountNumber() + Delim + DestinationClient.AccountNumber() + Delim + 
            to_string(Amount) + Delim + to_string(AccountBalance) + Delim + to_string(DestinationClient.AccountBalance)
            + Delim + CurrentUser.UserName;
    }

    void _TransferLog(clsBankClient& DestinationClient, double Amount) {
        fstream MyFile;

        MyFile.open("TransferLog.txt", ios::out | ios::app);

        if (MyFile.is_open()) {

            MyFile << _GetOneLineOfTransferLogInfo(DestinationClient, Amount) << endl;

            MyFile.close();
        }
    }

    static vector <strTransferLogInfo> _LoadTransferLogDataFromFile() {

        fstream MyFile;

        vector <strTransferLogInfo> _vTransferLog;

        MyFile.open("TransferLog.txt", ios::in);

        if (MyFile.is_open()) {
            string Line;

            while (getline(MyFile, Line)) {

                _vTransferLog.push_back(_ConvertLineDataToTransferLogStruct(Line));
            }


            MyFile.close();
        }
        return _vTransferLog;


    }

    static string _ConvertClientObjectToLineData(clsBankClient Client, string Delim = "#//#") {
        return Client.FirstName + Delim + Client.LastName + Delim + Client.Email + Delim + Client.Phone + Delim + Client.AccountNumber()
            + Delim + Client.PinCode + Delim + to_string(Client.AccountBalance);
    }

    static vector <clsBankClient> _LoadClientsDataFromFile(){
    
        fstream MyFile;

        vector <clsBankClient> _vClients;

        MyFile.open("Clients.txt", ios::in);

        if (MyFile.is_open()) {
            string Line;

            while (getline(MyFile, Line)) {

                _vClients.push_back(_ConvertLineDataToClientObject(Line));
            }



            MyFile.close();
        }
        return _vClients;
    }

    static void _SaveClientsDataToFile(vector <clsBankClient> vClients) {

        fstream MyFile;

        MyFile.open("Clients.txt", ios::out);

        if (MyFile.is_open()) {

            for (clsBankClient& Client : vClients) if (!Client.GetMarkForDelete()) MyFile << _ConvertClientObjectToLineData(Client) << endl;
            

            MyFile.close();
        }
    }

    void _Update() {
        vector <clsBankClient> _vClients;

        _vClients = _LoadClientsDataFromFile();

        for (clsBankClient& Client : _vClients) {

            if (Client.AccountNumber() == AccountNumber()) {
                Client = *this;
                break;
            }

        }
        _SaveClientsDataToFile(_vClients);
    }

    void _AddDataLineToFile(string DataLine) {

        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << DataLine << endl;

            MyFile.close();
        }
    }

    void _AddNew() {
        _AddDataLineToFile(_ConvertClientObjectToLineData(*this));
    }

public:

	clsBankClient(enMode Mode, string FirstName, string LastName,string Email, string Phone, string AccountNumber, 
		string PINCode,float AccountBalance) : clsPerson (FirstName, LastName, Email, Phone) {

		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PINCode = PINCode;
		_AccountBalance = AccountBalance;
	}

    struct strTransferLogInfo {
        string CurrentDateTime = clsDate::GetCurrentTime();
        string SourceAccount;
        string DestinationAccount;
        double Amount = 0;
        double SourceBalance = 0;
        double DestinationBalance = 0;
        string Username;
    };


	
	bool IsEmpty() {
		return _Mode == enMode::EmptyMode;
	}

    string AccountNumber()
    {
        return _AccountNumber;
    }

    void SetPinCode(string PinCode)
    {
        _PINCode = PinCode;
    }

    string GetPinCode()
    {
        return _PINCode;
    }
    __declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

    void SetAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float GetAccountBalance()
    {
        return _AccountBalance;
    }
    __declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

    bool GetMarkForDelete() {
        return _MarkForDelete;
    }

    void SetMarkForDelete(bool MarkForDelete) {
        _MarkForDelete = MarkForDelete;
    }
    

    static clsBankClient Find(string AccountNumber) {
        fstream MyFile;

        MyFile.open("Clients.txt", ios::in);

        if (MyFile.is_open()) {
            string Line;

            while (getline(MyFile, Line)) {

                clsBankClient Client = _ConvertLineDataToClientObject(Line);

                if (Client.AccountNumber() == AccountNumber) {
                    MyFile.close();
                    return Client;
                }
            }



            MyFile.close();
        }
        return _GetEmptyClientObject();
    }


    static clsBankClient Find(string AccountNumber, string PINCode) {
        fstream MyFile;

        MyFile.open("Clients.txt", ios::in);

        if (MyFile.is_open()) {
            string Line;

            while (getline(MyFile, Line)) {

                clsBankClient Client = _ConvertLineDataToClientObject(Line);

                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PINCode) {
                    MyFile.close();
                    return Client;
                }
            }



            MyFile.close();
        }
        return _GetEmptyClientObject();
    }

    static bool IsClientExist(string AccountNumber) {
        clsBankClient Client = Find(AccountNumber);
        return !Client.IsEmpty();
    }


    enum enSaveStatus{ SaveFailedEmptyObject = 0, SaveFailedAccountNumberExists, SaveSuccessful};

    enSaveStatus Save() {

        switch (_Mode) {

            case enMode::EmptyMode:
                return enSaveStatus::SaveFailedEmptyObject;
                break;
            case enMode::UpdateMode:
                _Update();
                return enSaveStatus::SaveSuccessful;
                break;

            case enMode::AddNewMode:

                if (clsBankClient::IsClientExist(_AccountNumber)) return enSaveStatus::SaveFailedAccountNumberExists;
                else { 
                    _AddNew();
                        
                    return enSaveStatus::SaveSuccessful; 
                
                }
        }
    }


    static clsBankClient GetAddNewClientObject(string AccountNumber) {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }


    bool Delete() {
        vector <clsBankClient> vClients = _LoadClientsDataFromFile();

        for (clsBankClient& Client : vClients) {

            if (Client.AccountNumber() == _AccountNumber) {
                Client._MarkForDelete = true;
                break;
            }


        }


        _SaveClientsDataToFile(vClients);

        *this = _GetEmptyClientObject();
        
        return true;
    }

    static vector <clsBankClient> GetUserList() {
        return _LoadClientsDataFromFile();
    }

    static vector <strTransferLogInfo> GetTransferLogList() {
        return _LoadTransferLogDataFromFile();
    }

    static double GetTotalBalances() {
        double Sum = 0;
        vector <clsBankClient> vClientList = clsBankClient::GetUserList();

        for (clsBankClient& Client : vClientList) Sum += Client.AccountBalance;
        
        return Sum;
    }

    void Deposit(double Amount) {
        _AccountBalance += Amount;
        Save();
    }

    bool Withdraw(double Amount) {

        if (Amount > _AccountBalance) return false;
        else { 
            _AccountBalance -= Amount;
            Save();
        }
        return true;
    }

    bool Transfer(double Amount, clsBankClient& DestinationClient) {

        if (Amount > _AccountBalance) return false;

        Withdraw(Amount);
        DestinationClient.Deposit(Amount);
        _TransferLog(DestinationClient, Amount);

        return true;
    }


    static double CalculateTotalBalances() {
        double TotalBalances = 0;

        vector <clsBankClient> vClients = clsBankClient::GetUserList();

        for (clsBankClient& Client : vClients) {
            TotalBalances += Client.AccountBalance;
        }

        return TotalBalances;
    }


    


};

