#pragma once

#include <windows.h>

#ifndef AIMP_FUNCTIONS_H
#define AIMP_FUNCTIONS_H

#define BUF_SIZE AIMPRemoteAccessMapFileSize

using namespace System;
using namespace System::Windows::Forms;


struct SongInfo //��������� ����������
{
    //wchar_t album[128] = L" ";
	wchar_t* album = new wchar_t[128]{'\0'};
    //wchar_t artist[128] = L" ";
	wchar_t* artist = new wchar_t[128]{'\0'};
    wchar_t date[64] = L" ";
    wchar_t fileName[512] = L" ";
    wchar_t genre[128] = L" ";
    wchar_t title[128] = L" ";
};

void TakeLineOfSongData(PBYTE buf, size_t len, wchar_t* data);//��������� ��������������� ���������� �� �����
void OpenFile();//�������� �����
void CloseFile();//�������� �����
SongInfo* TakeSongData();//��������� ���������� � �����
void TransferData(Label^ author_label, Label^ song_name_label, SongInfo* currentSong);
String^ ConvertFromWCharToString(wchar_t* str, String^ temportal, int i);//��������� �� wchar_t � String^
void ClearStruct(SongInfo* my_struct);//������� ���������

#endif