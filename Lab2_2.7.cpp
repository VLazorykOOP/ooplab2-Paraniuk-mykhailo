#include <iostream>
#include <bitset>
#include <vector>

class TextEncryptor {
public:
    std::vector<std::string> padText(const std::vector<std::string>& text) {
        std::vector<std::string> paddedText;
        for (const auto& line : text) {
            std::string paddedLine = line + std::string(16 - line.size(), ' ');
            paddedText.push_back(paddedLine);
        }
        return paddedText;
    }

    std::vector<unsigned short> encryptText(const std::vector<std::string>& text) {
        std::vector<unsigned short> encryptedText;

        for (size_t row = 0; row < text.size(); ++row) {
            for (size_t col = 0; col < text[row].size(); ++col) {
                char character = text[row][col];
                int asciiCode = static_cast<int>(character);

                // Calculate parity bits
                int rowParity = calculateParity(row);
                int asciiParity = calculateParity(asciiCode);

                // Create the 16-bit representation
                unsigned short encryptedChar = (row << 14) | (col << 10) | (asciiCode << 2) | (rowParity << 1) | asciiParity;
                encryptedText.push_back(encryptedChar);
            }
        }

        return encryptedText;
    }

private:
    int calculateParity(int value) {
        int parity = 0;
        while (value) {
            parity ^= value & 1;
            value >>= 1;
        }
        return parity;
    }
};

int main() {
    TextEncryptor encryptor;

    // Your input text
    std::vector<std::string> inputText = {
        "Hello,",
        "world!",
        "This",
        "is"
    };

    // Pad the text with spaces
    std::vector<std::string> paddedText = encryptor.padText(inputText);

    // Encrypt the text
    std::vector<unsigned short> encryptedText = encryptor.encryptText(paddedText);

    // Display the result
    std::cout << "Encrypted text:" << std::endl;
    for (const auto& charValue : encryptedText) {
        std::cout << std::bitset<16>(charValue) << std::endl;
    }

    return 0;
}