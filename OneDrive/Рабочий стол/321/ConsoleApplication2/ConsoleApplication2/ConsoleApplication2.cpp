#include <iostream>
#include <fstream>
#include <regex>
#include <string>

enum FileType { JSON, XML, TXT, UNKNOWN };

FileType determineFileType(const std::string& content) {
    std::regex json_regex(R"(\s*\{[^{}]*\})");
    std::regex xml_header_regex(R"(\s*<\?xml[^>]*\?>)");
    std::regex xml_tag_regex(R"(<[^>]+>)");
    std::regex txt_regex(R"(\s*[\w\s,.\-;:!?"]+\s*)");

    if (std::regex_search(content, json_regex)) {
        return JSON;
    }
    else if (std::regex_search(content, xml_header_regex) && std::regex_search(content, xml_tag_regex)) {
        return XML;
    }
    else {
        return TXT;
    }
}

std::string readFileContent(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file");
    }

    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return content;
}

int main() {
    std::string filePath;
    std::cout << "Enter file path: ";
    std::cin >> filePath;

    try {
        std::string content = readFileContent(filePath);
        FileType fileType = determineFileType(content);
        switch (fileType) {
        case JSON:
            std::cout << "File type: JSON" << std::endl;
            break;
        case XML:
            std::cout << "File type: XML" << std::endl;
            break;
        case TXT:
            std::cout << "File type: TXT" << std::endl;
            break;
        default:
            std::cout << "File type: UNKNOWN" << std::endl;
            break;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
