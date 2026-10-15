#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

using namespace std;


class clsCurrenciesListScreen : protected clsScreen
{



private:


	static void _PrintCurrencyRecordLine(clsCurrency Currency) {
		cout << "\t\t| " << left << setw(30) << Currency.Country();
		cout << "| " << left << setw(5) << Currency.CurrencyCode();
		cout << "| " << left << setw(30) << Currency.CurrencyName();
		cout << "| " << left << setw(12) << Currency.Rate() << endl;
	}


public:



	static void ShowCurrenciesListScreen() {


		vector<clsCurrency> vCurrenciesInfo = clsCurrency::GetCurrenciesList();
		short SeparatorLength = 85;
		string Title = "Currencies List Screen";
		string SubTitle = "  (" + to_string(vCurrenciesInfo.size()) + ") Currency.";

		_DrawScreenHeader(Title, SubTitle);

		cout << "\t\t" << string(SeparatorLength, '_') << endl;
		cout << "\n\t\t| " << left << setw(30) << "Country";
		cout << "| " << left << setw(5) << "Code";
		cout << "| " << left << setw(30) << "Name";
		cout << "| " << left << setw(12) << "Rate/(1$)" << endl;
		cout << "\t\t" << string(SeparatorLength, '_') << endl << endl;

		for (clsCurrency& sCurrency : vCurrenciesInfo) {
			_PrintCurrencyRecordLine(sCurrency);
		}

		cout << "\t\t" << string(SeparatorLength, '_') << endl;

	}

};

