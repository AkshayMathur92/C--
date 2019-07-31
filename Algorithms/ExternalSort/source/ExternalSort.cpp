#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <queue>
#include <vector>
#include <numeric>
#include <chrono>

using namespace std::literals::string_literals;
using fstream = std::fstream;
using ifstream = std::ifstream;
using ofstream = std::ofstream;
const static std::string InputFile = "input.txt"s;

int generate_input_file() {

	const static std::string InputFile = "input.txt"s;
	std::random_device rd;
	std::mt19937 generator(rd());
	std::vector<unsigned int> vec(UINT16_MAX);
	std::iota(begin(vec), end(vec), 0);
	ofstream fio;
	fio.open("expected.txt"s, std::ios::trunc | std::ios::out);
	if (!fio) {
		std::cout << "Failed to Open File" << std::endl;
		return -1;
	}
	else {
		for (auto& i : vec) {
			fio << i << std::endl;
		}
	}
	fio.close();
	std::shuffle(vec.begin(), vec.end(), generator);
	fio.open(InputFile, std::ios::trunc | std::ios::out);
	if (!fio) {
		std::cout << "Failed to Open File" << std::endl;
		return -1;
	}
	else {
		for(auto& i : vec){
			fio << i << std::endl;
		}
	}
	fio.close();
	std::cout << "File Created!\n";
	return 0;
}
void sort_external_file_with_temp() {
	
	fstream fio;
	fio.open(InputFile, std::ios::in);
	if (!fio) {
		std::cout << "Failed to Open File" << std::endl;
		return;
	}
	else {
		size_t num_of_files = 0;
		const size_t CHUNK_SIZE = 1000;
		while (!fio.eof()) {
			std::vector<unsigned int> temp_numbers;
			for (int i = 0; fio.is_open() && i < CHUNK_SIZE && !fio.eof(); i++) {
				int temp;
				fio >> temp;
				temp_numbers.push_back(temp);
			}
			std::sort(begin(temp_numbers), end(temp_numbers));
			ofstream temp_file_stream;
			temp_file_stream.open("temp_"s + std::to_string(num_of_files) + InputFile, std::ios::trunc | std::ios::out);
			for (unsigned int i = 0; temp_file_stream.is_open() && i < CHUNK_SIZE && i < temp_numbers.size() && !temp_file_stream.eof();i++) {
				temp_file_stream << temp_numbers[i] << std::endl;
			}
			temp_file_stream.close();
			num_of_files++;
		}
		fio.close();
		//batches created
		std::cout << num_of_files + 1 << " number of temp files created" << std::endl;
		std::vector<ifstream> temp_file_streams(num_of_files);
		for (unsigned int i = 0; i < num_of_files; i++) {
			std::cout << "temp_"s + std::to_string(i) + InputFile <<std::endl;
			temp_file_streams[i].open("temp_"s + std::to_string(i) + InputFile, std::ios::in);
			if (!temp_file_streams[i].is_open()) {
				std::cout << "Temp File "s + "temp_"s + std::to_string(i) + InputFile + " Cannot be opened"s << std::endl;
			}
		}
		ofstream master_file;
		master_file.open("master"s + InputFile , std::ios::trunc | std::ios::out);
		if (!master_file.is_open()) {
			std::cout << "Master File: "s + "master"s + InputFile + " Cannot be opened"s << std::endl;
		}
		std::priority_queue <unsigned int, std::vector<unsigned int>, std::greater<unsigned int>> pq;
		for(unsigned int i = 0; i <temp_file_streams.size(); i++){
			int temp = -1;
			temp_file_streams[i] >> temp;
			pq.emplace(temp);
		}
		while (true) {
			unsigned int min = INT_MAX;
			int index = -1;

			for (unsigned int j = 0; j < temp_file_streams.size() ; j++) {
				ifstream& temp_file = temp_file_streams[j];
				std::streampos pos = temp_file.tellg();
				unsigned int temp;
				auto& istream = temp_file_streams[j] >> temp;
				if (!static_cast<bool>(istream)) {
					continue;
				}
				else {
					temp_file.seekg(pos, std::ios_base::beg);
				}	
				if (temp < min) {
					index = j;
					min = temp;
				}
			}
			if (min == INT_MAX) {
				break;
			}
			else {
				temp_file_streams[index] >> min;
				pq.emplace(min);
				master_file << pq.top() << std::endl;
				pq.pop();
			}
		}
		while (!pq.empty()) {
			master_file << pq.top() << std::endl;
			pq.pop();
		}
		for (ifstream& closeable_stream : temp_file_streams) {
			closeable_stream.close();
		}
		master_file.close();
	}
	fio.close();
}

void sort_external_improved() {
	unsigned int range = UINT16_MAX;
	const unsigned int CHUNK_SIZE = 1000;
	std::vector<int> elements_in_range;
	uint16_t curr_begin = 0;
	uint16_t curr_end = curr_begin + CHUNK_SIZE;
	ofstream fo_output;
	fo_output.open("improvedoutput.txt"s, std::ios::out | std::ios::trunc);
	ifstream fio;
	fio.open(InputFile, std::ios::in);
	if (!fio) {
		std::cout << "Failed to Open File" << std::endl;
		return;
	}
	while (curr_end > curr_begin) {
		fio.clear();
		fio.seekg(std::ios::beg);
		int temp;
		while (fio >> temp) {
			if (temp >= curr_begin && temp < curr_end) {
				elements_in_range.push_back(temp);
			}
		}
		std::sort(elements_in_range.rbegin(), elements_in_range.rend());
		while (!elements_in_range.empty()) {
			fo_output << elements_in_range.back() << std::endl;
			elements_in_range.pop_back();
		}
		curr_begin = curr_end;
		curr_end = curr_begin + CHUNK_SIZE;
	}
	fo_output.close();
	fio.close();
}
int main()
{
	//generate_input_file();
	/*auto start = std::chrono::high_resolution_clock::now();
	sort_external_file_with_temp();
	auto stop = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::seconds>(stop - start).count() << std::endl;*/
	auto start = std::chrono::high_resolution_clock::now();
	sort_external_improved();
	auto stop = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::seconds>(stop - start).count() << std::endl;
}


