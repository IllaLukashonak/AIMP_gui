#pragma once
#include <string>
#include <windows.h>

#include "apiRemote.h"

#define BUF_SIZE AIMPRemoteAccessMapFileSize
#define AIMP_STRUCT_SIZE sizeof(TAIMPRemoteFileInfo)

namespace AIMPgui{
	
	class PlayerConnection {
	private:
		static TCHAR sz_name_[];
		static PBYTE my_buffer_;
		static HANDLE h_map_file_;
		static PAIMPRemoteFileInfo f_info_;
		
	public:static struct SongInfo { //Структура информации
		wchar_t* album = new wchar_t[128]{'\0'};
		wchar_t* artist = new wchar_t[128]{'\0'};
		wchar_t* date = new wchar_t[64]{'\0'};
		wchar_t* file_name = new wchar_t[1024]{'\0'};
		wchar_t* genre = new wchar_t[512]{'\0'};
		wchar_t* title = new wchar_t[128]{'\0'};
		} song;
	
	private:
		static void Open();//Открытие файла
		static void Close();//Закрытие файла
		static void TakeLine(PBYTE buf, size_t len, wchar_t* data);//Получение непосредственно информации из файла
		static void ClearSong();

	public:
		static void TakeSong();
		static System::String^ Wcstos(wchar_t* str, System::String^ temportal = L"", int i = 0);//Конверсия из wchar_t в String^
		static char* WcstoANCII(wchar_t* w_str, int codepage = 28595); //28595 - cyrilic, 1252; 28591 - latin
		static System::String^ ToString(char* str);
	};
}
