#ifndef KERNEL_OPERATINGSYSTEM_LIBARCHIVEUNZIPPER_H_
#define KERNEL_OPERATINGSYSTEM_LIBARCHIVEUNZIPPER_H_
#include "../../../include/libarchive/archive.h"
#include <string>
#include "unzipper.h"
#include <fstream>

using std::string;
using std::ofstream;

class LibArchiveUnzipper: public Unzipper {
public:
	LibArchiveUnzipper(string file_name);
	~LibArchiveUnzipper();
	void ExtractToOrDie(string output_path, string file_name);
	void ExtractFolderToOrDie(string output_path, string folder_name);
private:
    archive *zip_file_;
	archive_entry *current_zip_entry_;
	void ConfigureZipFile();
	void OpenZipArchiveOrDie();
	bool ReadNextHeader();
	void PrintCurrentEntry();
	bool EntryNameEquals(string file_name);
	void WriteEntryIntoFile(ofstream &output_file);
	int SizeAfterReading(char* buffer);
	void ExtractEntry(string destiny_path);
	bool ExtractEntryIfEqualsFileToExtract(string destiny_path, string file_name);
	string BuildDestinyFilePath(string destiny_path, string file_name);
	bool ExtractEntryIfItIsInsideFolder(string destiny_path, string folder_name);
	bool EntryNameContains(string folder_name);
	void ResetHeader();
	void CloseZipArchiveOrDie();
};
#endif
