#include <unordered_map>
#include <algorithm>
#include "Huffman.h"

void HuffmanTree::countFreqs() {
    std::unordered_map<char, int> countedFreq;
    for (char &i : input_text) {
	    countedFreq[i]++;
    }

    for (auto symbol : countedFreq) {
        HuffmanNode *node = new HuffmanNode(symbol.first, symbol.second, nullptr, nullptr);
	    symbolFreq.push_back(node);
    }

}

void HuffmanTree::makeQueue() {
    countFreqs();
    for (auto &i : symbolFreq)
        tree.push(i);
}

void HuffmanTree::makeHuffmanTree() {
    makeQueue();
    if (tree.size() == 1) {
        HuffmanNode *elem = tree.top();
        tree.pop();
        HuffmanNode *node = new HuffmanNode('\0', elem->freq + 1, elem, nullptr);
        tree.push(node);
        return;
    }
    while (tree.size() >= 2) {
        HuffmanNode *fst = tree.top();
        tree.pop();
        HuffmanNode *snd = tree.top();
        tree.pop();

        HuffmanNode *node = new HuffmanNode('\0', fst->freq + snd->freq, fst, snd);
        tree.push(node);
    }
}

std::priority_queue<HuffmanNode *, std::vector<HuffmanNode *>, Compare> HuffmanTree::getQueue() {
    return tree;
}

void HuffmanTree::deleteHuffmanTree(HuffmanNode *node) {
    if (!node)
        return;
    deleteHuffmanTree(node->left);
    deleteHuffmanTree(node->right);
    delete node;
}

std::vector<HuffmanNode *> HuffmanTree::getFreqs() {
    return symbolFreq;
}
