#include <iostream>
#include <fstream>
#include "CLI.h"
#include "HuffmanArchiver.h"

int main(int argc, char **argv) {
    CLI cli(argc, argv);

    try {
        cli.parseFlags();
    } catch (const ArgumentException& e) {
        std::cout << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    std::ifstream inputStream(cli.getInputFilename());
    try {
        if (!inputStream)
            throw FileException("Unable to open input file");
    } catch (const FileException &e) {
        std::cout << e.what() << std::endl;
    }
    std::ofstream outputStream(cli.getOutputFilename());
    try {
        if (!outputStream)
            throw FileException("Unable to open output file");
    } catch (const FileException &e) {
        std::cout << e.what() << std::endl;
    }
    std::istream& inStream = inputStream;
    std::ostream& outStream = outputStream;

    HuffmanArchiver h;
    long infoSize;
    if (cli.doCompress()) {
        infoSize = h.compress(inStream, outStream);
        std::cout << inStream.tellg() << "\n";
        std::cout << outStream.tellp() - infoSize << "\n";
        std::cout << infoSize << "\n";
    } else if (cli.doExtract()) {
        infoSize = h.extract(inStream, outStream);
        std::cout << inStream.tellg() - infoSize << "\n";
        std::cout << outStream.tellp() << "\n";
        std::cout << infoSize << "\n";
    }

    return 0;
}