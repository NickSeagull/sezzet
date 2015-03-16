#include "SevenZipUnzipper.h"
#include <string>
#include <windows.h>
#include <exception>

using std::string;

SevenZipUnzipper::SevenZipUnzipper(string file_path){
	file_path_ = file_path;
}

SevenZipUnzipper::~SevenZipUnzipper() {}

bool CreateNewProcess(string command, STARTUPINFO &si, PROCESS_INFORMATION &pi) {
	LPSTR converted_command = &command[0];
	return CreateProcess(NULL,
						 converted_command,
						 NULL,
						 NULL,
						 FALSE,
						 0,
						 NULL,
						 NULL,
						 &si,
						 &pi);
}

void InitalizeProcessStructs(STARTUPINFO &startup_info, PROCESS_INFORMATION &process_info) {
	ZeroMemory(&startup_info, sizeof(startup_info));
	startup_info.cb = sizeof(startup_info);
	ZeroMemory(&process_info, sizeof(process_info));
}

void SevenZipUnzipper::ExtractTo(string output_path) {
	STARTUPINFO startup_info;
	PROCESS_INFORMATION process_info;
	string command = "7z x " + file_path_ + " -o\"" + output_path + "\" -y";
	InitalizeProcessStructs(startup_info, process_info);
	if (!CreateNewProcess(command, startup_info, process_info)) throw std::exception("Could not execute 7zip");
	WaitForSingleObject(process_info.hProcess, INFINITE);
	CloseHandle(process_info.hProcess);
	CloseHandle(process_info.hThread);
}
