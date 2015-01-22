#ifndef KERNEL_OPERATINGSYSTEM_MINIZIPUNZIPPER_H_
#define KERNEL_OPERATINGSYSTEM_MINIZIPUNZIPPER_H_
#include <minizip/unzip.h>
#include <string>
#include "unzipper.h"

using std::string;
using std::ofstream;

class MinizipUnzipper: public Unzipper {
public:
	MinizipUnzipper(string file_name);
	~MinizipUnzipper();
	void ExtractTo(string output_path, string file_name);
private:
	unzFile zip_file_;
	void CopyFileToDestination(string file_name, string destination);
	void SelectFile(string file_name);
	void RemoveSelection();
	void WriteSelectionIntoFile(ofstream &output_file);
	string BuildOutputFileName(string output_path, string file_name);
	int SizeAfterReading(char* buffer);
	bool FileIsInsideZip(string file_to_locate);
	void OpenZipFileOrDie();
	void CloseZipFile();
};
#endif
