#include <iostream>
#include <string>

inline bool file_exists(const std::string& name) {
    struct stat buffer;
    return (stat(name.c_str(), &buffer) == 0);
}

int main(int argc, char* argv[])
{
    std::string path;

    while (true) {
        std::cout << "Input absolute path to a file (with file extension and using letters only from latin alphabet, please): ";
        if (argc > 1)
            path = argv[1];
        else
            getline(std::cin, path);

        if (file_exists(path)) {
            std::string command = "curl --upload-file \"" + path + "\" https://paste.c-net.org";
            std::cout << "\n";
            system(command.c_str());
            system("pause");
            break;
        }
        else {
            system("cls");
            std::cout << "File doesn't exist. Try again\n";
        }
    }
}