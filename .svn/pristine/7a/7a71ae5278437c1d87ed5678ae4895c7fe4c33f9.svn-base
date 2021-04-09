#ifndef LAB11_BITMANIP_H_INCLUDED
#define LAB11_BITMANIP_H_INCLUDED

#include <stdint.h>
#include <ostream>
#include <istream>
#include <fstream>

class write_le_int32 {
public:
    explicit write_le_int32(const int32_t n);

    int32_t num;
};

std::basic_ostream<char>& operator<<(std::basic_ostream<char>& stream, const write_le_int32& manip);

class read_le_int32 {
public:
    explicit read_le_int32(int32_t& n);

    int32_t &num;
};

std::basic_istream<char>& operator>>(std::basic_istream<char>& stream, const read_le_int32& manip);

class write_bool {
public:
    explicit write_bool(const bool n);

    bool num;
};

std::basic_ostream<char>& operator<<(std::basic_ostream<char>& stream, const write_bool& manip);

class read_bool {
public:
    explicit read_bool(bool &n);
    
    bool &num;
};

std::basic_istream<char>& operator>>(std::basic_istream<char>& stream, const read_bool& manip);

class write_c_str {
public:
    explicit write_c_str(char *s);
    
    char *str;
};

std::basic_ostream<char>& operator<<(std::basic_ostream<char>& stream, const write_c_str& manip);

class read_c_str {
public:
    explicit read_c_str(char* s, int l);

    char* str;
    int len;
};

std::basic_istream<char>& operator>>(std::basic_istream<char>& stream, const read_c_str& manip);

#endif