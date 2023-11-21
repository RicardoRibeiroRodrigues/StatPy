#include <string>
#include <fstream>
#include <preprocess.h>
#include <vector>
// Preprocess -> input: filename: loop through the file, removes comments, and blank lines

bool isWhitespace(std::string line) 
{
    for (auto &c : line) {
        if (c != ' ' && c != '\n' && c != '\r') {
            return false;
        }
    }
    return true;
}

std::string preprocess_code(std::string filename)
{
    std::ifstream in(filename);
    if (!in.is_open()) {
        std::cout << "failed to open " << filename << '\n';
        // Raise exception
        throw std::runtime_error("failed to open " + filename);
    }
    std::vector<std::string> lines;

    std::string line;
    while (std::getline(in, line)) {
        // remove comments
        auto pos = line.find("#");
        if (pos != std::string::npos) {
            line.erase(pos);
        }

        // Remove line with only spaces or \n or \r
        if (isWhitespace(line)) {
            continue;
        }
        lines.push_back(line + '\n');
    }
    std::string result;
    for (auto &line : lines) {
        result += line;
    }
    return result;
}