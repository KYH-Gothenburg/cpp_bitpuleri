#include <iostream>
#include <bitset>
#include <string>

using namespace std;

string bin_str16(unsigned short n) {
    bitset<16> bs(n);
    return bs.to_string();
}

template <typename T>
string bin_str8(T n) {
    bitset<8> bs(n);
    return bs.to_string();
}

string bin_str16_2(unsigned short value) {
    string result = "";
    int count = 0;
    for(int i = 1; i < 32769; i*=2){
        if((value & i) == i) {
            result = "1" + result;
        }
        else {
            result = "0" + result;
        }
        if (++count % 4 == 0) {
            result = " " + result;
        }
    }

    return result;
}

void test_operators() {
        unsigned short value = 20342;
        // binary and (&) bitwise and
        cout << value << " in binary is " << bin_str16(value) << endl;
        cout << value << " in binary is " << bin_str16_2(value) << endl;

        // binary or (|) bitwise or
        cout << bin_str16_2(value | 8) << endl;

        // binary xor (^) bitwise xor
        unsigned short value1 = 8;
        unsigned short value2 = 12;
        cout << value1 << " in binary is " << bin_str16_2(value1) << endl;
        cout << value2 << " in binary is " << bin_str16_2(value2) << endl;
        cout << (value1 ^ value2) << endl;
        cout << (4 ^ value1) << endl;

        // binary right shift operator (>>)
        cout << value << " in binary is " << bin_str16_2(value) << endl;
        value = value >> 2;
        cout << value << " in binary is " << bin_str16_2(value) << endl;
        auto new_value = value;
        for (int i = 0; i < 16; i++) {
            if(new_value & 1) {
                cout << "1";
            }
            else {
                cout << "0";
            }
            new_value >>= 1;
        }
        cout << endl;

        // binary left shift operator (<<)
        cout << value << " in binary is " << bin_str16_2(value) << endl;
        value = value << 2;
        cout << value << " in binary is " << bin_str16_2(value) << endl;

};


template <typename T>
T toggleBit(T n, int bit) {
    return (n ^ (1 << (bit - 1)));
}

int main() {
    cout << sizeof(bool) << endl;
    //cout << sizeof(char) << endl;
    char signed_value = -14;
    unsigned char unsigned_value = 14;
    cout << bin_str8(signed_value) << endl;
    signed_value = toggleBit(signed_value, 7);
    cout << bin_str8(signed_value) << endl;
    //cout << bin_str8(unsigned_value) << endl;

    string bin_str = "1111001011110010";
    unsigned short x = stoi(bin_str, nullptr, 2);
    cout << x << endl;
    string hex_str = "ac34";
    unsigned short y = stoi(hex_str, nullptr, 16);
    cout << y << endl;
    //cout << (rotate_bits_left(y, 7))

    return 0;
}
