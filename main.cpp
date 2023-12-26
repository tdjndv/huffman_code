#include "huffman.h"
#include <fstream>

#define LOG(x) std::cout << x << std::endl

std::string readFile(const std::string& path)
{
    std::string output = "";
    std::string text;

    std::ifstream file(path);

    while (getline(file, text))
    {
        output += text;
        output += '\n';
    }
    return output;
}

int main(int argc, char* argv[])
{
    if (argc > 1)
    {
        Huffman h(readFile(argv[1]));
        h.encode();
        h.print_code_table();
        auto s = h.get_coded_message();
        LOG(h.decode(s));
    }
}
