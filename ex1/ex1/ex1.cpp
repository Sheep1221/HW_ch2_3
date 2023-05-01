//#define _UNICODE
#include <iostream>
#include <tchar.h>
#include <stdlib.h>
#include <Windows.h>
#include <string>


int _tmain()
{
	// for result 1
	
    int res_t = _tcscmp(_T("Hello world"), _T("Ｈｅｌｌｏ　ｗｏｒｌｄ"));
    int res_l = lstrcmp(_T("Hello world"), _T("Ｈｅｌｌｏ　ｗｏｒｌｄ"));
	int res_t2 = _tcscmp(L"Hello world", L"Ｈｅｌｌｏ　ｗｏｒｌｄ");
	int res_l2 = lstrcmp(L"Hello world", L"Ｈｅｌｌｏ　ｗｏｒｌｄ");
	
	//for result 2
	/*
	int res_t = _tcscmp(_T("Hfllo world"), _T("Ｈｅｌｌｏ　ｗｏｒｌｄ"));
	int res_l = lstrcmp(_T("Hfllo world"), _T("Ｈｅｌｌｏ　ｗｏｒｌｄ"));
	int res_t2 = _tcscmp(L"Hfllo world", L"Ｈｅｌｌｏ　ｗｏｒｌｄ");
	int res_l2 = lstrcmp(L"Hfllo world", L"Ｈｅｌｌｏ　ｗｏｒｌｄ");
	*/
    std::cout << "res_t: " << res_t << "\n";
    std::cout << "res_l: " << res_l << "\n";
	std::cout << "res_t2: " << res_t2 << "\n";
	std::cout << "res_l2: " << res_l2 << "\n";
}
