#ifndef HUFFMAN_H
#define HUFFMAN_H
#include <queue>
#include <iostream>
#include <utility>

class HuffmanNode {
public:
    HuffmanNode(char symbol, int freq, HuffmanNode *l, HuffmanNode *r) : symbol(symbol),
                                                                         freq(freq),
                                                                         left(l),
                                                                         right(r) {}
    ~HuffmanNode() {
        symbol = '\0';
        freq = 0;
        left = nullptr;
        right = nullptr;
    }
    char symbol;
    int freq;
    HuffmanNode *left;
    HuffmanNode *right;
};

class Compare {
public:
    bool operator() (HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq;
    }
};

class HuffmanTree {
public:
    explicit HuffmanTree(std::string input) : input_text(input) {
        makeHuffmanTree();
    }
    ~HuffmanTree() {
        deleteHuffmanTree(tree.top());
    }
    std::priority_queue<HuffmanNode *, std::vector<HuffmanNode *>, Compare> getQueue();
    std::vector<HuffmanNode *> getFreqs();
private:
    void makeHuffmanTree();
    void countFreqs();
    void makeQueue();
    void deleteHuffmanTree(HuffmanNode *node);
    std::vector<HuffmanNode *> symbolFreq;
    std::priority_queue<HuffmanNode *, std::vector<HuffmanNode *>, Compare> tree;
    std::string input_text;
};
#endif // HUFFMAN_H
