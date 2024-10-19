#define VER 1.3
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <sys/stat.h>
#include <unistd.h>
#include <filesystem>
#include <algorithm>
#include <format>
#include <ctime>
#include <sys/types.h>
#include <linux/stat.h>
#include <fcntl.h>
#include <time.h>

using namespace std;

typedef vector<string> CommandLineStringArgs;

inline bool check_file_exists(const string &name)
{
    ifstream f(name.c_str());
    return f.good();
}

ifstream::pos_type filesize(const string &name)
{
    ifstream in(name, ifstream::ate | ifstream::binary);
    return in.tellg();
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "You must enter at least one argument or file name" << endl;
        exit(0);
    }
    CommandLineStringArgs cmdlineStringArgs(&argv[0], &argv[0 + argc]);
    fstream file(cmdlineStringArgs[1], ifstream::binary);
    string args = cmdlineStringArgs[1];
    string file_ext = "";
    size_t dot_pos = cmdlineStringArgs[1].rfind('.');
    if (dot_pos != string::npos)
    {
        file_ext = cmdlineStringArgs[1].substr(dot_pos + 1);
    }
    else
    {
        file_ext = "";
    }

    if (file_ext == "7z")
        file_ext = "7zip archive";
    else if (file_ext == "ai")
        file_ext = "Adobe Illustrator file";
    else if (file_ext == "asm")
        file_ext = "Assembly source file";
    else if (file_ext == "avi")
        file_ext = "AVI video file";
    else if (file_ext == "bak")
        file_ext = "Backup file";
    else if (file_ext == "bat")
        file_ext = "Windows shell script";
    else if (file_ext == "bin")
        file_ext = "Binary file";
    else if (file_ext == "bmp")
        file_ext = "Bitmap image";
    else if (file_ext == "c")
        file_ext = "C source file";
    else if (file_ext == "cab")
        file_ext = "Cabinet file";
    else if (file_ext == "cpp")
        file_ext = "C++ source file";
    else if (file_ext == "cs")
        file_ext = "C# source file";
    else if (file_ext == "css")
        file_ext = "CSS stylesheet";
    else if (file_ext == "csv")
        file_ext = "CSV file";
    else if (file_ext == "dat")
        file_ext = "Binary data file";
    else if (file_ext == "db")
        file_ext = "Database file";
    else if (file_ext == "dll")
        file_ext = "Windows library file";
    else if (file_ext == "dmg")
        file_ext = "macOS disk file";
    else if (file_ext == "doc")
        file_ext = "Microsoft Word document";
    else if (file_ext == "docx")
        file_ext = "Microsoft Word 2007+ document";
    else if (file_ext == "exe")
        file_ext = "Windows executable file";
    else if (file_ext == "flv")
        file_ext = "Flash video file";
    else if (file_ext == "gif")
        file_ext = "GIF image";
    else if (file_ext == "gz")
        file_ext = "Unix GZ archive";
    else if (file_ext == "h")
        file_ext = "C/C++ header file";
    else if (file_ext == "htm" || file_ext == "html")
        file_ext = "Website source file";
    else if (file_ext == "ico")
        file_ext = "Icon file";
    else if (file_ext == "iso")
        file_ext = "Disk image file";
    else if (file_ext == "jar")
        file_ext = "Java executable file";
    else if (file_ext == "java")
        file_ext = "Java source file";
    else if (file_ext == "jpeg" || file_ext == "jpg")
        file_ext = "JPEG image";
    else if (file_ext == "js")
        file_ext == "JavaScript source file";
    else if (file_ext == "json")
        file_ext = "JSON file";
    else if (file_ext == "log")
        file_ext = "Logs file";
    else if (file_ext == "m4a")
        file_ext = "Audio file";
    else if (file_ext == "mkv")
        file_ext = "MKV video file";
    else if (file_ext == "mov")
        file_ext = "Apple video file";
    else if (file_ext == "mp3")
        file_ext = "MP3 audio file";
    else if (file_ext == "mp4")
        file_ext = "MP4 video file";
    else if (file_ext == "msi")
        file_ext = "Windows installer file";
    else if (file_ext == "ods")
        file_ext = "Open spreadsheet file";
    else if (file_ext == "odt")
        file_ext = "Open document file";
    else if (file_ext == "pdf")
        file_ext = "Portable document format file";
    else if (file_ext == "php")
        file_ext = "PHP source file";
    else if (file_ext == "png")
        file_ext = "PNG image";
    else if (file_ext == "ppt")
        file_ext = "Microsoft PowerPoint file";
    else if (file_ext == "pptx")
        file_ext = "Microsoft PowerPoint 2007+ file";
    else if (file_ext == "rar")
        file_ext = "RAR archive";
    else if (file_ext == "tar")
        file_ext = "Unix archive";
    else if (file_ext == "ts")
        file_ext = "TypeScript source file";
    else if (file_ext == "txt")
        file_ext = "Text file";
    else if (file_ext == "wav")
        file_ext = "WAV audio file";
    else if (file_ext == "xls")
        file_ext = "Microsoft Excel file";
    else if (file_ext == "xlsx")
        file_ext = "Microsoft Excel 2007+ file";
    else
        file_ext = file_ext + " file";

    if (check_file_exists(cmdlineStringArgs[1]) == 1 && cmdlineStringArgs[1] != "-v" && cmdlineStringArgs[1] != "-h")
    {
        cout << "File: " << cmdlineStringArgs[1] << endl;
        ifstream::pos_type size = filesize(cmdlineStringArgs[1]);
        cout << "Size: " << size << " B" << endl;
        string path = filesystem::current_path();
        cout << "Path: " << path << "/" << cmdlineStringArgs[1] << endl;
        if (file_ext == "")
        {
            cout << "Type: file" << endl;
        }
        else
        {
            cout << "Type: " << file_ext << endl;
        }

        struct stat file_stat;
        const char *filename = cmdlineStringArgs[1].c_str();
        time_t mod_time;
        char buffer[80];
        if (stat(filename, &file_stat) == 0)
        {
            mod_time = file_stat.st_mtime;
            struct tm *timeinfo = localtime(&mod_time);
            strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M", timeinfo);
        }
        else
        {
            mod_time = 'n/a';
        }
        cout << "File modified: " << buffer << endl;

        struct statx file_statx;
        time_t creation_time;
        int fd = open(filename, O_RDONLY | O_NONBLOCK);
        bool dateCreateeErr = false;
        if (fd == -1)
        {
            dateCreateeErr = true;
        }

        if (statx(fd, "", AT_EMPTY_PATH, STATX_BTIME, &file_statx) != 0)
        {
            close(fd);
        }
        char buffer_[80];
        if (file_statx.stx_mask & STATX_BTIME)
        {
            struct tm *timeinfo;
            creation_time = file_statx.stx_btime.tv_sec;
            timeinfo = localtime(&creation_time);
            strftime(buffer_, sizeof(buffer_), "%d/%m/%Y %H:%M", timeinfo);
        }
        else
        {
            dateCreateeErr = true;
        }

        if (dateCreateeErr == false)
        {
            cout << "File created: " << buffer_ << endl;
        }
        else
        {
            cout << "Your filesystem doesn't support file creation date" << endl;
        }
    }
    else if (cmdlineStringArgs[1] == "-v")
    {
        cout << "Fileinfo " << VER << endl;
    }
    else if (cmdlineStringArgs[1] == "-h")
    {
        cout << "Fileinfo help" << endl;
        cout << "Usage: fileinfo [file name: file info | -v: version | -h: help]" << endl;
    }
    else
    {
        cout << "Error: bad option or file doesn't exist." << endl;
    }
}
