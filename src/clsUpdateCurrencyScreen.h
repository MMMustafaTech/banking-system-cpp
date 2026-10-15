#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

using namespace std;


class clsUpdateCurrencyScreen : protected clsScreen
{

private:
	static void _PrintCurrencyCard(clsCurrency Currency) {
		cout << "\nCurrency Card:";
		cout << "\n___________________\n";
		cout << "\nCountry  : " << Currency.Country();
		cout << "\nCode     : " << Currency.CurrencyCode();
		cout << "\nName     : " << Currency.CurrencyName();
		cout << "\nRate(1$) : " << Currency.Rate();
		cout << "\n___________________\n";
	}

public:

	static void ShowUpdateCurrencyScreen() {
		_DrawScreenHeader("Update Currency Screen");

		string CurrencyCode = "";
		char Choice = 'n';
		double NewRate;

		cout << "\nPlease enter Currency Code: ";
		CurrencyCode = clsInputValidate::ReadString();


		while (!clsCurrency::IsCurrencyExist(CurrencyCode)) {
			cout << "\nCurrency was not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		_PrintCurrencyCard(Currency);

		cout << "\nAre you sure you want to update the rate of this Currency? y/n: ";
		cin >> Choice;

		if (tolower(Choice) == 'y') {

			cout << "\nUpdate Currency Rate:\n";
			cout << "_________________________";
			cout << "\n\nEnter New Rate: ";
			NewRate = clsInputValidate::ReadDblNumber();

			Currency.UpdateRate(NewRate);

			cout << "\nCurrency Rate Updates Successfully :-)\n";

			_PrintCurrencyCard(Currency);
		}
		else cout << "\nOperation Cancelled\n";
	}


};

