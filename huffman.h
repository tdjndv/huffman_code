#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <utility>
#include <queue>
#include <unordered_map>
#include <string>
#include <iostream>

class Node
{
    public:
        Node(Node* left, Node* right, std::pair<char, int> data);
        Node* left;
        Node* right;
        std::pair <char, int> data;

        bool operator<(const Node& p) const;
};

class Huffman
{
    private:
        std::string source;
        std::unordered_map<char, int> frequency_table;
        std::unordered_map<char, std::string> code_table;
        Node* tree;
        void find_code_table(Node* node, std::string code);
    public:
        Huffman(std::string source);
        void encode();
        void print_code_table();
        std::string decode(std::string code);
        std::string get_coded_message();
};

#endif
