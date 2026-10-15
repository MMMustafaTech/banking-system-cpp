#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"

class clsInputValidate
{



public:

	static int ReadIntNumber(string ErrorMessage = "\nInvalid Number, Please enter again: \n") {
		int Number;

		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << ErrorMessage;
		}
		return Number;
	}

	static double ReadDblNumber(string ErrorMessage = "\nInvalid Number, Please enter again: \n") {
		double Number;

		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << ErrorMessage;
		}
		return Number;
	}


	static bool IsNumberBetween(int NumberToCheck, int From, int To) {
		return (NumberToCheck >= From && NumberToCheck <= To);
	}

	static bool IsNumberBetween(double NumberToCheck, double From, double To) {
		return (NumberToCheck >= From && NumberToCheck <= To);
	}


	static bool isDateBetween(clsDate DateToCheck, clsDate Date1, clsDate Date2) {
		return clsDate::isDateBetween(DateToCheck, Date1, Date2);
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "\nNumber is not within range, enter again: ") {
		cout << "Please enter a number between " << From << " and " << To << ": ";
		int NumberToCheck = ReadIntNumber();

		while (!IsNumberBetween(NumberToCheck, From, To)) { 
			cout << ErrorMessage;
			NumberToCheck = ReadIntNumber();
		}

		return NumberToCheck;
	}


	static double ReadIntNumberBetween(double From, double To, string ErrorMessage = "\nNumber is not within range, enter again: ") {
		cout << "Please enter a number between " << From << " and " << To << ": ";
		double NumberToCheck = ReadDblNumber();

		while (!IsNumberBetween(NumberToCheck, From, To)) {
			cout << ErrorMessage;
			NumberToCheck = ReadDblNumber();
		}

		return NumberToCheck;
	}

	static bool IsValidDate(clsDate Date) {
		return clsDate::IsValidDate(Date);
	}

	static string ReadString() {
		string MyString;

		getline(cin >> ws, MyString);

		return MyString;
	}



};

