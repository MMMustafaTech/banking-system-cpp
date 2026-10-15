#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include "clsString.h"

using namespace std;

class clsFindCurrencyScreen : protected clsScreen
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

	static void _ShowResults(clsCurrency Currency) {
		if (!Currency.IsEmpty()) {
			cout << "\nCurrency Found :-)\n";
			_PrintCurrencyCard(Currency);
		}
		else cout << "\nCurrency was not Found :-(\n";

	}


public:


	static void ShowFindCurrencyScreen() {
		_DrawScreenHeader("Find Currency Screen");

		string CurrencyCode = "";
		string Country = "";
		short Choice;

		cout << "\nFind By: [1] Code or [2] Country?\n";
		Choice = clsInputValidate::ReadIntNumberBetween(1, 2);

		if (Choice == 1) {

			cout << "\nPlease Enter Currency Code: ";
			CurrencyCode = clsString::UpperAllString(clsInputValidate::ReadString());

			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

			_ShowResults(Currency);
		}

		else {
			cout << "\nPlease Enter Country Name: ";
			Country = clsInputValidate::ReadString();

			clsCurrency Currency = clsCurrency::FindByCountry(Country);

			_ShowResults(Currency);

		}
		

	}



};

