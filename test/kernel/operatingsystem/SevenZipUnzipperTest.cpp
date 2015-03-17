#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE SezzetTests
#include <boost/test/unit_test.hpp>
#include <boost/crc.hpp>
#include <string>
#include "../../../src/kernel/operatingsystem/SevenZipUnzipper.h"
#include <fstream>
#include <ios>
#include <exception>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem.hpp>

void RemoveTemporalDirectories();

using std::string;
using std::ifstream;


string zip_file_path = "C:\\Users\\Nikita\\Desarrollo\\SIANI\\sezzet\\resources\\win_32_bouncingBall.fmu";
string output_folder_path = "C:\\Users\\Nikita\\Desarrollo\\SIANI\\sezzet\\resources\\win_32_bouncingBall_out\\";
const int kBufferSize = 1024;

void RemoveTemporalDirectories() {
	boost::filesystem::path ofp_path(output_folder_path);
	boost::filesystem::remove_all(ofp_path);
}

void ProcessBytes(ifstream &input_file_stream, boost::crc_32_type &result) {
	char buffer[kBufferSize];
	input_file_stream.read(buffer, kBufferSize);
	result.process_bytes(buffer, input_file_stream.gcount());
}

string ChecksumAsHexadecimalString(boost::crc_32_type &result) {
	std::stringstream stream;
	stream << std::hex << result.checksum();
	return string(stream.str());
}

int GetCrc32FromFileOrDie(string file_path) {
	ifstream input_file_stream(file_path, std::ios_base::binary);
	boost::crc_32_type result;
	if (!input_file_stream) throw std::exception("Could not open file");
	do { ProcessBytes(input_file_stream, result); } while (input_file_stream);
	return result.checksum();
}

BOOST_AUTO_TEST_CASE(checksum_after_extraction_is_correct){
	SevenZipUnzipper unzipper(zip_file_path);
	unzipper.ExtractTo(output_folder_path);
	
	int expected_crc = 4035518048;
	int actual_crc = GetCrc32FromFileOrDie(output_folder_path + "\\modelDescription.xml");

	BOOST_CHECK_EQUAL(expected_crc, actual_crc);
	RemoveTemporalDirectories();
}