#include "AIMP_Functions.h"
#include "apiRemote.h"
#include <string>
#include <codecvt>

TCHAR szName[] = TEXT("AIMP2_RemoteInfo");

TCHAR szName[];
PBYTE My_Buffer;

HANDLE hMapFile;
PAIMPRemoteFileInfo FInfo;

void OpenFile() {
   // AIMPRemoteHandle = (HANDLE)FindWindow((LPCWSTR)"AIMP2_RemoteInfo", (LPCWSTR)"AIMP2_RemoteInfo");
    
    hMapFile = OpenFileMapping(
        FILE_MAP_READ,   // доступ к чтению/записи
        TRUE,            // имя не наследуется
        szName);         // имя "проецируемого " объекта 

    if (hMapFile == NULL)
    {
        MessageBox::Show(
            L"Невозможно открыть объект проекция файла",
            "Error",
            MessageBoxButtons::YesNo);
        return;
    }

    FInfo = (PAIMPRemoteFileInfo)MapViewOfFile(hMapFile,    // дескриптор "проецируемого" объекта
        FILE_MAP_READ,  // разрешение чтения/записи
        0,
        0,
        BUF_SIZE);

    if (FInfo == NULL)
    {
        MessageBox::Show(
            "Невозможно открыть объект проекция файла",
            "Error",
            MessageBoxButtons::YesNo);
        return;
    }
}

void CloseFile() {
    CloseHandle(hMapFile);
}

SongInfo* TakeSongData() {
    My_Buffer = PBYTE(UINT(FInfo) + sizeof(TAIMPRemoteFileInfo));
    SongInfo* currentSong = new SongInfo;
	//wcscpy(currentSong->artist, L"");
    TakeLineOfSongData(My_Buffer, FInfo->AlbumLength, currentSong->album);
    TakeLineOfSongData(My_Buffer, FInfo->ArtistLength, currentSong->artist);
    TakeLineOfSongData(My_Buffer, FInfo->DateLength, currentSong->date);
    TakeLineOfSongData(My_Buffer, FInfo->FileNameLength, currentSong->fileName);
    TakeLineOfSongData(My_Buffer, FInfo->GenreLength, currentSong->genre);
    TakeLineOfSongData(My_Buffer, FInfo->TitleLength, currentSong->title);

    UnmapViewOfFile(FInfo);
    return currentSong;
}

void TakeLineOfSongData(PBYTE buf, size_t len, wchar_t* data) {
    memcpy(data, (wchar_t*)buf, len * 2);
    My_Buffer += len * 2;
}

void TransferData(Label^ author_label, Label^ song_name_label, SongInfo* currentSong) {
    String^ temortal = "";
    author_label->Text = ConvertFromWCharToString(currentSong->artist, temortal, 0);
    song_name_label->Text = ConvertFromWCharToString(currentSong->title, temortal, 0);
    delete currentSong;
}
String^ ConvertFromWCharToString(wchar_t* str, String^ temportal, int i) {   
    if (str[i] != '\0') {
        temportal += Convert::ToString(str[i]);
        temportal = ConvertFromWCharToString(str, temportal, ++i);
    }
    return temportal;
}

void ClearStruct(SongInfo* my_struct) {
    delete my_struct;
}
