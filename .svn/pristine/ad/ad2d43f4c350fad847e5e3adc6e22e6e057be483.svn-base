#ifndef CLI_H
#define CLI_H
#include <iostream>
#include <cstring>

class FileException : public std::runtime_error {
public:
    FileException(const std::string& msg);
    const char* what() const noexcept override;
};

class ArgumentException : public std::invalid_argument {
public:
    ArgumentException(const std::string& msg);
    const char* what() const noexcept override;
};

class CLI {
public:
    CLI(int argc, char **argv) : argc(argc), argv(argv) {}
    void parseFlags();
    std::string getInputFilename();
    std::string getOutputFilename();
    bool doCompress();
    bool doExtract();
private:
    int argc;
    char **argv;
    bool compFlag;
    bool extrFlag;
    bool inputFlag;
    bool outputFlag;
    std::string inputFile;
    std::string outputFile;
};

#endif // CLI_H
