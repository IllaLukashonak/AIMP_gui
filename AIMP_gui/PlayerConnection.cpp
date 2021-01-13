#include <stringapiset.h>

#include "PlayerConnection.h"

TCHAR AIMPgui::PlayerConnection::sz_name_[] = TEXT("AIMP2_RemoteInfo");
PBYTE AIMPgui::PlayerConnection::my_buffer_;
HANDLE AIMPgui::PlayerConnection::h_map_file_;
PAIMPRemoteFileInfo AIMPgui::PlayerConnection::f_info_;

AIMPgui::PlayerConnection::SongInfo AIMPgui::PlayerConnection::song;

void AIMPgui::PlayerConnection::Open() {
	 h_map_file_ = OpenFileMapping(
        FILE_MAP_READ,   // доступ к чтению/записи
        TRUE,            // имя не наследуется
        sz_name_);         // имя "проецируемого " объекта 

    if (h_map_file_ == NULL)
    {
	    System::Windows::Forms::MessageBox::Show(
            L"Невозможно открыть объект проекция файла",
            "Error",
            System::Windows::Forms::MessageBoxButtons::YesNo);
        return;
    }

    f_info_ = (PAIMPRemoteFileInfo)MapViewOfFile(
        h_map_file_,    // дескриптор "проецируемого" объекта
        FILE_MAP_READ,  // разрешение чтения/записи
        0,
        0,
        BUF_SIZE);

    if (f_info_ == NULL)
    {
	    System::Windows::Forms::MessageBox::Show(
            "Невозможно открыть объект проекция файла",
            "Error",
            System::Windows::Forms::MessageBoxButtons::YesNo);
        return;
    }
}

void AIMPgui::PlayerConnection::Close() {
	UnmapViewOfFile(f_info_);
	CloseHandle(h_map_file_);
}

void AIMPgui::PlayerConnection::TakeLine(PBYTE buf, size_t len, wchar_t* data) {
	memcpy(data, (wchar_t*)buf, len * 2);
    my_buffer_ += len * 2;
}

void AIMPgui::PlayerConnection::ClearSong() {
	delete[] song.album;
	delete[] song.artist;
	delete[] song.date;
	delete[] song.file_name;
	delete[] song.genre;
	delete[] song.title;
	
	song.album = new wchar_t[128]{'\0'};
	song.artist = new wchar_t[128]{'\0'};
	song.date = new wchar_t[64]{'\0'};
	song.file_name = new wchar_t[1024]{'\0'};
	song.genre = new wchar_t[512]{'\0'};
	song.title = new wchar_t[128]{'\0'};
}

System::String^ AIMPgui::PlayerConnection::Wcstos(wchar_t* str, System::String^ temportal, int i) {
	 if (str[i] != '\0') {
        temportal += System::Convert::ToString(str[i]);
        temportal = Wcstos(str, temportal, ++i);
    }
    return temportal;
}

char* AIMPgui::PlayerConnection::WcstoANCII(wchar_t* w_str) {
	int ISO_8859_5 = 28595;
    char* m_char;
    int strsize = WideCharToMultiByte(ISO_8859_5, 0, w_str, wcslen(w_str) + 1, NULL, 0, NULL, NULL);
    m_char = new char[strsize];
    WideCharToMultiByte(ISO_8859_5, 0, w_str, wcslen(w_str) + 1, m_char, strsize, NULL, NULL);
    return m_char;
}

void AIMPgui::PlayerConnection::TakeSong() {
    ClearSong();
	
	Open();
	
	my_buffer_ = (PBYTE)((UINT)f_info_ + AIMP_STRUCT_SIZE);

	TakeLine(my_buffer_, f_info_->AlbumLength, song.album);
	TakeLine(my_buffer_, f_info_->ArtistLength, song.artist);
	TakeLine(my_buffer_, f_info_->DateLength, song.date);
	TakeLine(my_buffer_, f_info_->FileNameLength, song.file_name);
	TakeLine(my_buffer_, f_info_->GenreLength, song.genre);
	TakeLine(my_buffer_, f_info_->TitleLength, song.title);

	Close();
}
