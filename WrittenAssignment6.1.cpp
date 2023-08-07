#include <iostream>
#include <fstream>
#include <map>
#include <cctype>
#include <string>

int main() {
    std::string input_filename, output_filename;
    std::cout << "Enter input filename: ";
    std::getline(std::cin, input_filename);
    std::cout << "Enter output filename: ";
    std::getline(std::cin, output_filename);
    
    std::ifstream input_file(input_filename);
    std::ofstream output_file(output_filename);
    
    if (!input_file) {
        std::cerr << "Could not open input file\n";
        return 1;
    }
    if (!output_file) {
        std::cerr << "Could not open output file\n";
        return 1;
    }
    
    std::map<char, int> char_counts;
    std::string line;
    int line_count = 0;
    while (std::getline(input_file, line)) {
        output_file << line << '\n';
        line_count++;
        for (char c : line) {
            if (std::isalpha(c)) {
                char_counts[std::tolower(c)]++;
            }
        }
    }
    
    output_file << "\nThe number of lines in the input file is " << line_count << ".\n";
    for (auto pair : char_counts) {
        output_file << static_cast<char>(std::toupper(pair.first)) << " appears " << pair.second << " times.\n";
    }
    
    return 0;
}
