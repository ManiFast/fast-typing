#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ofstream fout;	// Write+crate
	string path = "config.ahk";
	fout.open(path);

	string text;
	cin >> text;

	fout << "Sleep, 2000\n\n";

	vector<string> textInVec(100);
	for (int i = 0; i < text.size(); i++)
	{
		if (text[i] == '_')
			textInVec[i] = ' ';
		else
			textInVec[i] = text[i];
	}

	for (int i = 0; i < text.size(); i++)
	{
		cout << textInVec[i] << " ";

		if (text[i] == '_')
			fout << "send {Space}\n";
		else
			fout << "send {" << textInVec[i] << "}\n";

		fout << "Sleep, 1\n";
	}




	system("timeout 1");system("exit");fout.close();
	return 0;
}