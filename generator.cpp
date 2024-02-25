#include <iostream>
#include <string>
#include <sys/time.h>
#include <unistd.h>
#include <cstdlib>
#include <fstream>

#define path "path/to/your/passwords.extension"

using namespace std;

unsigned int hash3(unsigned int h1, unsigned int h2, unsigned int h3)
{
    return ((((h1 * 2654435789U) + h2) * 2654435789U) + h3);
}

int rando (int n)
{
	switch (n)
	{
		case 0:
			return char('A' + rand() % 26);
		case 1:
			return char('a' + rand() % 26);
		case 2:
			return char('!' + rand() % 10);
		case 3:
			return char('0' + rand() % 10);
	}
}

int main() {
	bool flag = false;
	int length = 15;
	while (!flag)
	{
		int choice;
		cout << "Enter choice: 1 - get, 2 - generate, 3 - change length, 4 - get list, 5 - clear screen, 0 - exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			{
				cout << "Enter account: ";
				string acc;
				cin >> acc;
				ifstream file(path);
				string s;
				while (getline(file, s)) {
					if (s == acc) {
						cout << "Password: ";
						getline(file, s);
						cout << s << endl;
						file.close();
						break;
					}
				}
				break;
			}
		case 2:
			{
				
				string password, acc;
				struct timeval time;
				gettimeofday(&time, NULL);
				srand(hash3(time.tv_sec, time.tv_usec, getpid()));
				for (int i = 0; i < length; i++)
				{
					password += rando(rand() % 4);
				}
				ofstream file(path, ios::app);
				cout << "Enter account: ";
				cin >> acc;
				file << acc << endl;
				file << password << endl;
				cout << password << endl;
				file.close();
				break;
			}
		case 3:
			{
				cout << "Enter new length: ";
				cin >> length;
				break;
			}
		case 4:
			{
				ifstream file(path);	
				string s;
				while (getline(file, s)) {
					cout << s << endl;
					getline(file, s);
				}
				file.close();
				break;
			}
		case 5:
			system("clear");
			break;
		case 0:
			flag = true;
			break;
		}
	}
	return 0;
}