#pragma once

// �����Կ
constexpr char key1 = '\x01';
constexpr char key2 = '\x02';

constexpr char* XorData(char* src, char* dest, int len) {
    for (int i = 0; i < len; i++) {
        dest[i] = src[i] ^ key1 ^ key2;
    }
    return dest;
}

template <int len>
class Obfuscator {
public:
    char obfString[len];

    // ����ʱ���ܴ洢����
    constexpr Obfuscator(char* str) : obfString{} {
        XorData(str, obfString, len);
    }

    // ����ʱ����, �ֲ�����������ջ��, �������лᱻ����
    char* Decrypt() {
        XorData(obfString, obfString, len);
        return obfString;
    }
};

#define OBF(str) []{ constexpr Obfuscator<sizeof(str)> obf(str); return obf; }().Decrypt()