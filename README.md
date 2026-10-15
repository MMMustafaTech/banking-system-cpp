# C++ Banking System

A console banking application developed while studying **OOP Applications** in the Programming Advices learning path.

## Features in the source

- Create, find, update, delete, and list client accounts.
- Deposit, withdraw, transfer funds, and show total balances.
- User login, user management, and permission checks.
- Login register and transfer history screens.
- Currency listing, lookup, rate updates, and a conversion calculator.
- Text-file persistence and reusable string, date, input, and utility classes.

## Technology

C++20 · Windows console · Microsoft Visual C++ · File I/O · Object-oriented programming

## Run locally

1. Install Visual Studio with **Desktop development with C++**, the Windows SDK, and a compatible MSVC toolset.
2. Open `src/MyFirstCPPApp.vcxproj`. The saved project targets toolset `v145`; retarget it to the installed toolset if necessary.
3. Set the debugger working directory to the `src` folder, which contains the demo data files.
4. Build and run the console application.
5. Sign in with the **public demo account**: username `admin`, password `Demo123`.

All included account names, email addresses, phone numbers, balances, and currency rates are fictional demonstration values. The original saved records and activity logs are excluded.

Alternatively, compile from a Visual Studio Developer Command Prompt:

```bat
cd src
cl /std:c++20 /EHsc MyFirstCPPApp.cpp /Fe:bank-demo.exe
bank-demo.exe
```

## Verification

The application compiled with MSVC 14.51 and C++20. A smoke run verified the demo login, display of the main menu, logout, and the three-failed-attempt exit. Compiler warnings remain in the saved coursework; other workflows have not been exhaustively tested.

## Project structure

- `src/MyFirstCPPApp.cpp`: application entry point.
- `src/clsBankClient.h`, `src/clsUser.h`, `src/clsCurrency.h`: core data and file operations.
- `src/cls*Screen.h`: menu and screen classes.
- `src/clsDate.h`, `src/clsString.h`, `src/clsInputValidate.h`, `src/clsUtil.h`: helpers.

## Learning context

This is an educational application. Its reversible password transformation, text-file storage, and floating-point balances are learning implementations; use only the provided fictional demo data.

The source follows Programming Advices by Mohammed Abu-Hadhoud. Portfolio preparation adds documentation and fictional seed data. See [ATTRIBUTION.md](ATTRIBUTION.md).
