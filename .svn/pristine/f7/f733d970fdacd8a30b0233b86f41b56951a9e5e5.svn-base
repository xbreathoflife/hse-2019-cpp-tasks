#include <fstream>

#include "HuffmanArchiver.h"

long HuffmanArchiver::compress(std::istream &inputStream, std::ostream &outputStream) {
    compr.compress(inputStream, outputStream);
    return compr.getInfoSize();
}

long HuffmanArchiver::extract(std::istream &inputStream, std::ostream &outputStream) {
    extr.extract(inputStream, outputStream);
    return extr.getInfoSize();
}

void Compressor::compress(std::istream &inputStream, std::ostream &outputStream) {
    std::string text((std::istreambuf_iterator<char>(inputStream) ),
                     (std::istreambuf_iterator<char>()));

    if (text.empty()) {
        outputStream.write(text.c_str(), text.size());
        infoSize = 0;
        return;
    }
    HuffmanTree tree(text);
    encode(tree.getQueue().top(), "");

    std::string compressedText = writeDecodeTable();
    infoSize = compressedText.size();
    compressedText = writeDecodedText(compressedText, text);
    outputStream.write(compressedText.c_str(), compressedText.size());
}

void Compressor::encode(HuffmanNode *node, const std::string &code) {
    if (!node)
        return;
    if (!node->left && !node->right) {
        codes[node->symbol] = code;
    }
    encode(node->left, code + "0");
    encode(node->right, code + "1");
}

void Compressor::writeBit(char bit, std::string &text) {
    bool bt;
    static uint8_t buffer = 0;
    bt = bit == '1';

    if (bt)
        buffer |= (1 << bitPos);

    if (bitPos-- == 0) {
        text += buffer;
        buffer = 0;
        bitPos = BYTE_SIZE - 1;
    }
}

std::string Compressor::writeDecodeTable() {
    bitPos = BYTE_SIZE - 1;
    std::string compressedText = "";
    int size = codes.size();
    std::string binNum = std::bitset<sizeof(int) * BYTE_SIZE>(size).to_string();
    for (char ch : binNum)
        writeBit(ch, compressedText);

    //compressedText += size;
    for (auto &element : codes) {
        binNum = std::bitset<BYTE_SIZE>(element.first).to_string();
        for (char ch : binNum)
            writeBit(ch, compressedText);
        binNum = std::bitset<BYTE_SIZE>(element.second.size()).to_string();
        for (char ch : binNum)
            writeBit(ch, compressedText);
        for (char ch : element.second)
            writeBit(ch, compressedText);
    }
    return compressedText;
}

std::string Compressor::writeDecodedText(std::string compressedText, std::string text) {
    for (char &symbol : text) {
        for (char codeElement : codes[symbol])
            writeBit(codeElement, compressedText);
    }

    char excessElem = 0;
    while (bitPos != 7) {
        writeBit('0', compressedText);
        excessElem++;
    }
    compressedText = excessElem + compressedText;
    return compressedText;
}

std::unordered_map<char, std::string> Compressor::getCodes() {
    return codes;
}

long Compressor::getInfoSize() const {
    return infoSize;
}

void Extractor::extract(std::istream &inputStream, std::ostream &outputStream) {
    std::string compressedText((std::istreambuf_iterator<char>(inputStream)),
                               (std::istreambuf_iterator<char>()));
    if (compressedText.empty()) {
        infoSize = 0;
        return;
    }

    char excessElem = readTable(compressedText);
    infoSize = textPos - ((bitPos == 8) ? 0 : 1);
    std::string extractedText = decodeText(compressedText, excessElem);
    outputStream << extractedText;
}

bool Extractor::readBit(std::string &text) {
    if (bitPos == 8) {
        textPos++;
        bitPos = 0;
    }
    std::string byte = std::bitset<BYTE_SIZE>(text[textPos]).to_string();
    return byte[bitPos++] != '0';
}

char Extractor::readTable(std::string compressedText) {
    char excessElem = uint8_t(compressedText[0]);
    bitPos = 0;
    textPos = 1;

    std::bitset<sizeof(int) * BYTE_SIZE> size;
    for (int j = BYTE_SIZE * sizeof(int) - 1; j >= 0; j--) {
        bool bit = readBit(compressedText);
        size.set(j, bit);
    }
    std::size_t numOfSymbols = size.to_ulong();
    for (std::size_t i = 0; i < numOfSymbols; i++) {
        // take letter
        std::bitset<BYTE_SIZE> byte;
        for (int j = BYTE_SIZE - 1; j >= 0; j--) {
            bool bit = readBit(compressedText);
            byte.set(j, bit);
        }
        char symbol = char(byte.to_ulong());
        byte.reset();
        // take code length
        for (int j = BYTE_SIZE - 1; j >= 0; j--) {
            byte.set(j, readBit(compressedText));
        }
        int codeLength = char(byte.to_ulong());
        // make code
        std::string code;
        for (int j = 0; j < codeLength; j++) {
            code += readBit(compressedText) != 0 ? '1' : '0';
        }
        // add to map
        codes[code] = symbol;
    }
    return excessElem;
}

std::string Extractor::decodeText(std::string compressedText, char excessElem) {
    int n = compressedText.size();
    std::string extractedText;
    std::string text;
    while (textPos < n - 1) {
        text += readBit(compressedText) != 0 ? '1' : '0';
    }
    int leftEl = 8 - excessElem - bitPos;
    for (int i = 0; i < leftEl; i++)
        text += readBit(compressedText) != 0 ? '1' : '0';
    std::string cur = "";
    for (std::size_t i = 0; i < text.size(); i++) {
        cur += text[i];
        if (codes.find(cur) != codes.end()) {
            extractedText += codes[cur];;
            cur = "";
        }
    }
    return extractedText;
}


std::unordered_map<std::string, char> Extractor::getCodes() {
    return codes;
}

long Extractor::getInfoSize() const {
    return infoSize;
}
