#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;


class clsCurrencyExchangeScreen : protected clsScreen
{

private:

	static short _ReadCurrencyExchangeMenuOption() {
		cout << "\t\t\t\t";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 5);
		return Choice;
	}


	enum _enCurrencyExchangeMenuOptions {eListCurrencies = 1, eFindCurrency, eUpdateRate, eCurrencyCalculator, eMainMenu};



	static void _ShowListCurrenciesScreen() {
		//cout << "\n\tListCurrencies Screen will be here.";
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrenciesScreen() {
		//cout << "\n\tFind Screen will be here.";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen() {
		//cout << "\n\tUpdateRate Screen will be here.";
		clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();
	}

	static void _ShowCurrencyCalculatorScreen() {
		//cout << "\n\tCurrencyCalculator Screen will be here.";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}



	static void _PerformMenuAction(_enCurrencyExchangeMenuOptions Option) {
		system("cls");
		switch (Option) {
		case _enCurrencyExchangeMenuOptions::eListCurrencies:
			_ShowListCurrenciesScreen();
			_ReturnToCurrencyExchangeMainMenu();
			break;

		case _enCurrencyExchangeMenuOptions::eFindCurrency:
			_ShowFindCurrenciesScreen();
			_ReturnToCurrencyExchangeMainMenu();
			break;

		case _enCurrencyExchangeMenuOptions::eUpdateRate:
			_ShowUpdateRateScreen();
			_ReturnToCurrencyExchangeMainMenu();
			break;

		case _enCurrencyExchangeMenuOptions::eCurrencyCalculator:
			_ShowCurrencyCalculatorScreen();
			_ReturnToCurrencyExchangeMainMenu();
			break;

		case _enCurrencyExchangeMenuOptions::eMainMenu:
			break;
		}
	}

	static void _ReturnToCurrencyExchangeMainMenu() {
		cout << "\n\n\tPress any key to back to Currency Exchange Main Menu...";
		system("pause>0");
		ShowCurrencyExchangeScreen();
	}

public:

	static void ShowCurrencyExchangeScreen() {
		short DelimLength = 40;
		_DrawScreenHeader("Currency Exchange Main Screen");

		cout << "\t\t\t\t" << string(DelimLength, '=') << endl;
		cout << "\t\t\t\t\t" << "  Currency Exchange Menu" << endl;
		cout << "\t\t\t\t" << string(DelimLength, '=') << endl;

		cout << "\t\t\t\t   [1] List Currencies.\n";
		cout << "\t\t\t\t   [2] Find Currencies.\n";
		cout << "\t\t\t\t   [3] Update Rate.\n";
		cout << "\t\t\t\t   [4] Currency Calculator.\n";
		cout << "\t\t\t\t   [5] Main Menu.\n";

		cout << "\t\t\t\t" << string(DelimLength, '=') << endl;

		_PerformMenuAction((_enCurrencyExchangeMenuOptions)_ReadCurrencyExchangeMenuOption());
	}










};

