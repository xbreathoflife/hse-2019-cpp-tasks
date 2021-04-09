#include <iostream>
#include "matrix.h"

const int REGNUMBER = 10;
int main() {
    Matrix regs[REGNUMBER];
    while (true) {
        std::string command, reg;
        std::cin >> command;
        if (!command.compare("exit")) {
            break;
        } else if (!command.compare("load")) {
            std::string filename;
            std::cin >> reg >> filename;
            reg[0] = '0';
            int index = stoi(reg);
            try { 
                regs[index].read(filename);
            } catch(const FileException& e) {
                std::cout << e.what() << std::endl;
            }
        } else if (!command.compare("print")) {
            std::cin >> reg;
            reg[0] = '0';
            int index = stoi(reg);
            regs[index].print();
        } else if (!command.compare("add")) {
            std::string reg2;
            std::cin >> reg >> reg2;
            reg[0] = '0';
            reg2[0] = '0';
            int index1 = stoi(reg);
            int index2 = stoi(reg2);
            try {
                regs[index1].add(regs[index2]);
            } catch(const MatrixException& e) {
                std::cout << e.what() << std::endl;
            }
        } else if (!command.compare("mul")) {
            std::string reg2;
            std::cin >> reg >> reg2;
            reg[0] = '0';
            reg2[0] = '0';
            int index1 = stoi(reg);
            int index2 = stoi(reg2);
            try {
                regs[index1].mul(regs[index2]);
            } catch(const MatrixException& e) {
                std::cout << e.what() << std::endl;
            }
        } else if (!command.compare("elem")) {
            int row, col, value;
            std::cin >> reg >> row >> col;
            reg[0] = '0';
            int index = stoi(reg);
            try {
                value = regs[index].get(row, col);
                std::cout << value << "\n";
            } catch(const MatrixException& e) {
                std::cout << e.what() << std::endl;
            }
        }
    }
    return 0;
}