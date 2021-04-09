#ifndef HUFFMAN_ARCHIVER_H
#define HUFFMAN_ARCHIVER_H
#include <iostream>
#include <utility>
#include <unordered_map>
#include <bitset>
#include "Huffman.h"

const int BYTE_SIZE = 8;

class Compressor {
public:
    void compress(std::istream &inputStream, std::ostream &outputStream);
    long getInfoSize() const;
    std::unordered_map<char, std::string> getCodes();
private:
    void encode(HuffmanNode* node, const std::string& code);
    void writeBit(char bit, std::string &text);
    std::string writeDecodeTable();
    std::string writeDecodedText(std::string compressedText, std::string text);

    std::unordered_map<char, std::string> codes;
    long infoSize;
    char bitPos;
};

class Extractor {
public:
    void extract(std::istream &inputStream, std::ostream &outputStream);
    long getInfoSize() const;
    std::unordered_map<std::string, char> getCodes();
private:
    bool readBit(std::string &text);
    char readTable(std::string compressedText);
    std::string decodeText(std::string compressedText, char excessElem);

    std::unordered_map<std::string, char> codes;
    int infoSize;
    char bitPos;
    int textPos;
};

class HuffmanArchiver {
public:
    long compress(std::istream &inputStream, std::ostream &outputStream);
    long extract(std::istream &inputStream, std::ostream &outputStream);
private:
    Compressor compr;
    Extractor extr;
};

#endif // HUFFMAN_ARCHIVER_H
