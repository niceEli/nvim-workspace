#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <fmt/format.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fmt::print("Usage: {} <file containing location>\n", argv[0]);
        return 1;
    }

    // Get the file path from command line argument
    std::string filePath = argv[1];

    // Read the content of the file
    std::ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        fmt::print("Error opening file: {}\n", filePath);
        return 1;
    }

    std::string location;
    getline(inputFile, location);

    // Build the command to open nvim with the specified location
    std::string command = "nvim " + location;

    // Use system() to execute the command
    int result = system(command.c_str());

    // Check if the command executed successfully
    if (result == 0) {
        fmt::print("Opened location from file: {} with nvim.\n", location);
        return 0;
    }
    else {
        fmt::print("Error opening location from file: {} with nvim.\n", location);
        return 1;
    }
}