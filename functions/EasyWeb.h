// WebReq Function - Call using WebRequest(url here);

#pragma once
#pragma comment(lib, "wininet.lib")
#define _WIN32_WINNT _WIN32_WINNT_WINXP
#define NOMINMAX
#include <Windows.h>
#include <WinInet.h>
#include <string>
using namespace std;
string WebRequest(string url) {
	string result;
	HINTERNET connect = InternetOpen("MyBrowser", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);

	if (!connect) {
		cout << "Connection Failed or Syntax error";
		return 0;
	}

	HINTERNET OpenAddress = InternetOpenUrl(connect, url.c_str(), NULL, 0, INTERNET_FLAG_PRAGMA_NOCACHE | INTERNET_FLAG_KEEP_CONNECTION, 0);

	if (!OpenAddress)
	{
		DWORD ErrorNum = GetLastError();
		cout << "Failed to open URL \nError No: " << ErrorNum;
		InternetCloseHandle(connect);
		return 0;
	}

	char DataReceived[4096] = { 0 };
	DWORD NumberOfBytesRead = 0;
	while (InternetReadFile(OpenAddress, DataReceived, 4096, &NumberOfBytesRead) && NumberOfBytesRead)
	{
		result += DataReceived;
	}

	InternetCloseHandle(OpenAddress);
	InternetCloseHandle(connect);

	return result;
}
