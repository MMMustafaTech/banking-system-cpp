#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

using namespace std;


class clsCurrencyCalculatorScreen : protected clsScreen
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


	static clsCurrency _GetCurrency(string Message) {
		string CurrencyCode = "";

		cout << Message << endl;
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode)) {
			cout << "\nCurrency was not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return Currency;
	}

	static void _PrintCalculationResults(double Amount, clsCurrency Currency1, clsCurrency Currency2) {

		cout << "\nConverting from " << Currency1.CurrencyCode() << " to USD:\n";

		_PrintCurrencyCard(Currency1);

		double AmountInUSD = Currency1.ConvertToUSD(Amount);

		cout << endl << Amount << " " << Currency1.CurrencyCode() << ": " << AmountInUSD << " USD\n";

		if (Currency2.CurrencyCode() == "USD") return;

		cout << "\nConverting from USD to " << Currency2.CurrencyCode() << ":\n";
		_PrintCurrencyCard(Currency2);

		double AmountInCurrency2 = Currency1.CurrencyCalculator(Amount, Currency2);

		cout << endl << Amount << " " << Currency1.CurrencyCode() << ": " << AmountInCurrency2 << " " << Currency2.CurrencyCode() << endl;
	}



public:

	static void ShowCurrencyCalculatorScreen() {

		double Amount;
		double Result;

		char Continue = 'y';

		while (tolower(Continue) == 'y') {
			_DrawScreenHeader("Currency Calculator");

			clsCurrency Currency1 = _GetCurrency("\nPlease enter Currency1 Code: ");
			clsCurrency Currency2 = _GetCurrency("\nPlease enter Currency2 Code: ");


			cout << "\nEnter amount to exchange: ";
			Amount = clsInputValidate::ReadDblNumber();

			_PrintCalculationResults(Amount, Currency1, Currency2);

			cout << "\n\nDo you want to make another transactions? y/n: ";
			cin >> Continue;
		}
	}

		
















};

