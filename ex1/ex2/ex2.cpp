#include <iostream>
#include <tchar.h>
#include <stdlib.h>
#include <Windows.h>

int main()
{
	// Open the file
	HANDLE hFile = CreateFile(L"test1.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ| FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hFile == INVALID_HANDLE_VALUE)
	{
		std::cout << "Error opening file: "<< GetLastError() << "\n";
		return 1;
	}
	
	// Lock the file
	OVERLAPPED overlapped = { 0 };
	if (!LockFileEx(hFile, LOCKFILE_EXCLUSIVE_LOCK, 0, MAXDWORD, MAXDWORD, &overlapped))
	{
		std::cout << "Error locking file: %d\n"<< GetLastError() << "\n";
		CloseHandle(hFile);
		return 1;
	}
	std::cout << "locking the file test1\n";

	// Sleep for 1 minute to hold the lock
	Sleep(20000);

	// Unlock the file and close the handle
	UnlockFileEx(hFile, LOCKFILE_EXCLUSIVE_LOCK, MAXDWORD, MAXDWORD, &overlapped);
	std::cout << "unlock the file test1\n";
	Sleep(30000);
	CloseHandle(hFile);
	return 0;
}

// 執行程式: Ctrl + F5 或 [偵錯] > [啟動但不偵錯] 功能表
// 偵錯程式: F5 或 [偵錯] > [啟動偵錯] 功能表

// 開始使用的秘訣: 
//   1. 使用 [方案總管] 視窗，新增/管理檔案
//   2. 使用 [Team Explorer] 視窗，連線到原始檔控制
//   3. 使用 [輸出] 視窗，參閱組建輸出與其他訊息
//   4. 使用 [錯誤清單] 視窗，檢視錯誤
//   5. 前往 [專案] > [新增項目]，建立新的程式碼檔案，或是前往 [專案] > [新增現有項目]，將現有程式碼檔案新增至專案
//   6. 之後要再次開啟此專案時，請前往 [檔案] > [開啟] > [專案]，然後選取 .sln 檔案
