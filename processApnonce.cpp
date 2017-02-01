#include <iostream>
#include <stdlib.h>
#include <Windows.h>
using namespace std;

#define MAX_COLS 32768
#pragma warning(disable:4996)

int main() {

	/*
	in -> device apNonces
	ios -> ios version
	s -> saving chars from in
	ioss -> saving chars from ios
	cmd -> tsschecker command
	iosver -> ios version string
	ch -> to call system function, argvs must be const char type
	*/

	FILE *in, *ios;
	char s[MAX_COLS], ioss[MAX_COLS];
	string cmd, iosver;
	const char *ch;

	// Checking iOS version text file exists
	fputs("READING ios.txt\n", stderr);
	if ((ios = fopen("ios.txt", "rt")) == NULL) {
		fputs("Cannot open file ios.txt\n", stderr);
		system("pause");
	}

	// Put iOS version to char
	fgets(ioss, MAX_COLS, ios);
	fputs("READING ios.txt DONE\n", stderr);
	
	// Checking device text file exists
	fputs("READING 7.txt\n", stderr);
	if ((in = fopen("7.txt", "rt")) == NULL) {
		fputs("Cannot open file 7.txt\n", stderr);
		system("pause");
	}

	// 6s_64
	while (fgets(s, MAX_COLS, in) != NULL) {
		cmd = "";
		ch = NULL;

		cmd = "tsschecker_windows.exe -d iPhone9,2 -m manifest/iPhone9,2/";
		cmd.append(ioss);
		cmd.append(".plist");
		cmd.append(" -e *********** --boardconfig d11ap --apnonce ");
		cmd.append(s);
		cmd.erase(cmd.length() - 1);
		cmd.append(" -s");

		ch = cmd.c_str();
		cout << ch << endl;
		system(ch);

		cmd = "";
		ch = NULL;

		cmd = "copy *.shsh ..\\";
		cmd.append(s);
		cmd.erase(cmd.length() - 1);
		cmd.append(".shsh");
		ch = cmd.c_str();
		cout << ch << endl;
		system(ch);

		cmd = "";
		ch = NULL;
	}

	system("pause");
	return 0;
}