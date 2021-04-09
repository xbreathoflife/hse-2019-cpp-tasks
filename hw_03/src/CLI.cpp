#include "CLI.h"

FileException::FileException(const std::string& msg) : std::runtime_error(msg) {}

const char* FileException::what() const noexcept {
    return runtime_error::what();
}

ArgumentException::ArgumentException(const std::string& msg) : std::invalid_argument(msg) {}

const char *ArgumentException::what() const noexcept {
    return invalid_argument::what();
}

void CLI::parseFlags() {
    if (argc != 6)
        throw ArgumentException("Wrong number of arguments");
    compFlag = false;
    extrFlag = false;
    inputFlag = false;
    outputFlag = false;
    for (int i = 1; i < argc;) {
        if ( !strcmp(argv[i], "-c")) {
            if (compFlag)
                throw ArgumentException("Argument repeating: -c");
            compFlag = true;
            i++;
        } else if (!strcmp(argv[i], "-u")) {
            if (extrFlag)
                throw ArgumentException("Argument repeating: -u");
            extrFlag = true;
            i++;
        } else if (!strcmp(argv[i], "-f") || !strcmp(argv[i], "--file")) {
            if (inputFlag)
                throw ArgumentException("Argument repeating: -f");
            if (i == argc - 1 || !strcmp(argv[i + 1], "-c") || !strcmp(argv[i + 1], "-u") ||
                !strcmp(argv[i + 1], "-f") || !strcmp(argv[i + 1], "--flag") || !strcmp(argv[i + 1], "-o") ||
                !strcmp(argv[i + 1], "--output")) {
                    throw ArgumentException("Input filename argument is missing");
            }
            inputFile = argv[i + 1];
            i += 2;
            inputFlag = true;
        } else if (!strcmp(argv[i], "-o") || !strcmp(argv[i], "--output")) {
            if (outputFlag)
                throw ArgumentException("Argument repeating: -o");
            if (i == argc - 1 || !strcmp(argv[i + 1], "-c") || !strcmp(argv[i + 1], "-u") ||
                !strcmp(argv[i + 1], "-f") || !strcmp(argv[i + 1], "--flag") || !strcmp(argv[i + 1], "-o") ||
                !strcmp(argv[i + 1], "--output")) {
                    throw ArgumentException("Output filename argument is missing");
            }
            outputFile = argv[i + 1];
            i += 2;
            outputFlag = true;
        } else {
            throw ArgumentException("No such flag");
        }
    }

    if (!inputFlag)
        throw ArgumentException("Not enough info for input");

    if (!outputFlag)
        throw ArgumentException("Not enough info for output");

    if (compFlag && extrFlag)
        throw ArgumentException("Unable to do both");

    if (!compFlag && !extrFlag)
        throw ArgumentException("No command");
}

std::string CLI::getInputFilename() {
    return inputFile;
}

std::string CLI::getOutputFilename() {
    return outputFile;
}

bool CLI::doCompress() {
    return compFlag;
}

bool CLI::doExtract() {
    return extrFlag;
}
