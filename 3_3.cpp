#include<iostream>
using namespace std;
#include<string>
int main()
{
	while (true)
	{
		cout << "UserName: ";
		string name;
		getline(cin, name);
		int length = 6;
		if (name.length() > 4)
		{
			if (length > name.length())
			{
				length = name.length();
			}
			unsigned long a = 574;
			for (int i = 0; i < length; i++)
			{
				a = a*(name[i] / 5) + name[i];
			}
			unsigned long b = a;
			unsigned long c = b >> 31;
			if (c == 0)
			{
				cout << "Serial: " << a << endl;
			}
			else
			{
				int d = (int)a;
				cout << "Serial: " << d << endl;
			}
		}
		else
		{
			cout << "Name too short" << endl;
		}
	}
	system("pause");
	return 0;
}