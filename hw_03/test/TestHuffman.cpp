#include "doctest.h"
#include "Huffman.h"

TEST_CASE("COUNTING FREQUENCY") {
    HuffmanTree tree("aaa");
    CHECK(tree.getFreqs().size() == 1);
    CHECK(tree.getFreqs()[0]->symbol == 'a');
    CHECK(tree.getFreqs()[0]->freq == 3);

    HuffmanTree tree2("aab");
    bool expr = (tree2.getFreqs()[0]->symbol == 'a' && tree2.getFreqs()[0]->freq == 2) ||
                (tree2.getFreqs()[0]->symbol == 'b' && tree2.getFreqs()[0]->freq == 1);
            CHECK(expr);
    bool expr2 = (tree2.getFreqs()[1]->symbol == 'a' && tree2.getFreqs()[1]->freq == 2) ||
                 (tree2.getFreqs()[1]->symbol == 'b' && tree2.getFreqs()[1]->freq == 1);
    CHECK(expr2);
}

TEST_CASE("CHECHING QUEUE") {
    HuffmanTree tree("aaa");
    CHECK(tree.getQueue().top()->symbol == '\0');
    CHECK(tree.getQueue().top()->freq == 4);
    CHECK(tree.getQueue().top()->left->symbol == 'a');
    CHECK(tree.getQueue().top()->left->freq == 3);
    CHECK(tree.getQueue().top()->right == nullptr);

    HuffmanTree tree2("aab");
    CHECK(tree2.getQueue().size() == 1);
    CHECK(tree2.getQueue().top()->symbol == '\0');
    CHECK(tree2.getQueue().top()->freq == 3);
    CHECK(tree2.getQueue().top()->left->symbol == 'b');
    CHECK(tree2.getQueue().top()->left->freq == 1);
    CHECK(tree2.getQueue().top()->right->symbol == 'a');
    CHECK(tree2.getQueue().top()->right->freq == 2);
}