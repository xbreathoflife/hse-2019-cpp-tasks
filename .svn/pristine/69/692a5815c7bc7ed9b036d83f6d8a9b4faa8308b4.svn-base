#include <iostream>
#include <cstring>
#include "bin_manip.h"


write_le_int32::write_le_int32(const int32_t n) : num(n) {}

std::basic_ostream<char>& operator<<(std::basic_ostream<char>& stream, const write_le_int32& manip) {
    stream.write((char*)(&manip.num), 4);

    return stream;
}

read_le_int32::read_le_int32(int32_t& n) : num(n) {}

std::basic_istream<char>& operator>>(std::basic_istream<char>& stream, const read_le_int32& manip) {
    stream.read((char*)(&manip.num), 4);

    return stream;
}

write_bool::write_bool(const bool n) : num(n) {}

std::basic_ostream<char>& operator<<(std::basic_ostream<char>& stream, const write_bool& manip) {
    stream.write((char*)(&manip.num), 1);

    return stream;
}

read_bool::read_bool(bool& n) : num(n) {}

std::basic_istream<char>& operator>>(std::basic_istream<char>& stream, const read_bool& manip) {
    stream.read((char*)(&manip.num), 1);

    return stream;
}

write_c_str::write_c_str(char* s) : str(s) {}

std::basic_ostream<char>& operator<<(std::basic_ostream<char>& stream, const write_c_str& manip) {
    int len = strlen(manip.str) + 1;
    stream.write(manip.str, len);
    return stream;
}

read_c_str::read_c_str(char* s, int l) : str(s), len(l) {}

std::basic_istream<char> &operator>>(std::basic_istream<char> &stream, const read_c_str& manip) {
    char ch = 'a';
    int len = 0;
    while (ch != 0 && !stream.eof() && len < manip.len) {
	    stream.read(&ch, 1);
	    manip.str[len++] = ch;
    }
    if (manip.str[len - 1] != 0)
	    stream.setstate(std::ios::failbit);
    return stream;
}