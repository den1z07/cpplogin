#include "stdafx.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <sys/stat.h>


using namespace std;

void Login();
void Register();
int main();
int main()
{
	bool again;
	int selection;

	cout << "Welcome to login system made with c++, There can be bugs so sorry :D" << endl;
	cout << "Options are:\n1.Login\n2.Register\n3.Exit" << endl;
	cout << ">> ";
	cin >> selection;
	if (selection == 1)
	{
		Login();
	}
	if (selection == 2)
	{
		Register();
	}
	if (selection == 3)
	{
		cout << "Goodbye!" << endl;
		again = false;
	}
}


void Register()
{
	// fixed file problems.
	fstream reg; // load file to register user
	string usrname; //
	string usrpass; //
	cout << "Enter your username: ";
	cin.get(); // skip some lines for getline, otherwise it won't work.
	getline(cin, usrname);
	if (usrname.empty()) // if user leaves username section is empty >>
	{
		cout << "You can't leave username empty." << endl;
		Register(); // return back to registration.
	}
	else if (usrname.length() < 3) // check if length is smaller than 3 
	{
		cout << "Minimum username length should be 4 characters long." << endl;
		Register(); // return ro registration.
	}
	else // if everything is fine get password.
	{
		cout << "Enter password: ";
		getline(cin, usrpass); // get password and start initilization
		if (usrpass.empty()) // if password is empty cancel registration.
		{
			cout << "Your password can't be left empty." << endl;
			Register(); // return back to first registration line
		}
		else if (usrpass.length() < 5) // for security (wow very secure! :D), check if password is smaller than 5 characters.
		{
			cout << "Your password can't be less than 5 characters." << endl;
			Register(); // return back 
		}
		else // if everything is fine do this >>
		{
			reg.open(usrname.c_str(), fstream::out); // create and open user file.
			reg << usrpass; // write to file.
			reg.close(); // close file.
			cout << "Registration complete. Returning you to main menu." << endl << endl;
			main(); // return back to  main menu.

		}
	}
}




void Login()
{
	// start login (will add explanation of what i did here soon)
	ifstream checklog;
	string username;
	string password;
	string output;
	cout << "Welcome Guest. Please enter your username." << endl;
	cout << ">> ";
	cin.get();
	getline(cin, username);
	if (username.empty())
	{
		cout << "You didn't entered anything. Returning you back to main menu." << endl;
		main();
	}
	else
	{
		checklog.open(username);
		if (checklog)
		{
			checklog >> output;
			cout << "Enter your password" << endl;
			cout << ">> ";
			cin >> password;
				if (password == output)
					{
					cout << "Login succesful." << endl;
					main();
					}
				else
					{
					cout << "Password is wrong." << endl;
					main();
					}
		}
		else
		{
			cout << "Username does not exist." << endl;
			main();
		}
	}
}


