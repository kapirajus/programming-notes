
// Copyright (c) 2014 Venkateswara Rao Sanaka

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <cstdint>
#include <cstddef>

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

#define POPULATE(t) \
    print<t>(#t)

template <typename type_t>
void print(string s) {
    cout << "type " << s
        << " --- sizeof --- " << sizeof(type_t)
        << " --- alignment --- " << __alignof__(type_t)
        << endl;
}

class Sample {
    public:
        Sample() {}
        //virtual
        ~Sample() {}

    private:
        //
};

struct structa_t {
    char        c;
    short int   s;
};

struct structb_t {
    short int   s;
    char        c;
    int         i;
};

struct structc_t {
    char        c;
    double      d;
    int         s;
};

struct structd_t {
    double      d;
    int         s;
    char        c;
};

class ref_size_t {
    public:
        ref_size_t(int &y) : x(y) {}

    private:
        int &x;
};

struct ref_offset_t {
    ref_offset_t(int &y) : x(y) {}

    int &x;
    char c;
};

void test_01() {
    off_t offset = offsetof(ref_offset_t, c);
    std::cout << "c offset - " << offset << " bytes (space occupied by reference)" << std::endl;
}

int main(void) {
    POPULATE(char);
    POPULATE(short);
    POPULATE(int);
    POPULATE(long);
    POPULATE(unsigned);
    POPULATE(unsigned long);
    POPULATE(double);
    POPULATE(long double);
    POPULATE(signed short);
    POPULATE(unsigned short);
    POPULATE(unsigned char);
    POPULATE(void *);
    POPULATE(long &);
    POPULATE(short &);
    POPULATE(short *);
    POPULATE(int &);
    POPULATE(const int);

    POPULATE(int8_t);
    POPULATE(int16_t);
    POPULATE(int32_t);
    POPULATE(int64_t);
    POPULATE(uint8_t);
    POPULATE(uint16_t);
    POPULATE(uint32_t);
    POPULATE(uint64_t);

    POPULATE(uintptr_t);

    POPULATE(Sample);
    POPULATE(structa_t);
    POPULATE(structb_t);
    POPULATE(structc_t);
    POPULATE(structd_t); // This will surprise on i686 machines, with size 16 bytes at an alignment of 4 bytes

    POPULATE(std::shared_ptr<int>);
    POPULATE(std::unique_ptr<int>);

    POPULATE(ref_size_t);
    POPULATE(ref_offset_t);

    test_01();

    return 0;
}

