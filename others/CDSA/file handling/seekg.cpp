#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream file("data.txt");

    if (!file.is_open())
    {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }

    // Get the initial position of the get pointer
    std::ifstream::pos_type initialPos = file.tellg();
    std::cout << "Initial position: " << initialPos << std::endl;

    // Read the first line from the file
    std::string line;
    std::getline(file, line);
    std::cout << "First line: " << line << std::endl;

    // Get the current position after reading the first line
    std::ifstream::pos_type currentPos = file.tellg();
    std::cout << "Current position: " << currentPos << std::endl;

    // Set the get pointer back to the initial position
    file.seekg(initialPos);

    // Read the second line from the file
    std::getline(file, line);
    std::cout << "again read after setting back to first line: " << line << std::endl;

    // Get the current position again
    currentPos = file.tellg();
    std::cout << "Current position: " << currentPos << std::endl;

    file.close();

    return 0;
}
