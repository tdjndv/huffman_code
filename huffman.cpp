#include "huffman.h"

Node::Node(Node* left, Node* right, std::pair<char, int> data)
{
    this->left = left;
    this->right = right;
    this->data = data;
}

bool Node::operator<(const Node& node) const
{
    return this->data.second > node.data.second;
}

Huffman::Huffman(std::string source)
{
    this->source = source;
    for (int i = 0; i < source.length(); ++i)
    {
        frequency_table[source[i]]++;
    }
}

void Huffman::find_code_table(Node* node, std::string code)
{
    if (node == NULL) return;
    if (node->data.first != EOF)
    {
        code_table[node->data.first] = code;
    }
    find_code_table(node->left, code + "0");
    find_code_table(node->right, code + "1");
}

void Huffman::print_code_table()
{
    for (const auto& v: code_table)
    {
        if (v.first == ' ')
        {
            std::cout << "\' \'";
        }
        else if (v.first == '\n')
        {
            std::cout << "\'\\n\'";
        }
        else
        {
            std::cout << v.first;
        }
        std::cout << " . " << v.second << std::endl;
    }
    std::cout << "-----------------\n";
}

void Huffman::encode()
{
    std::priority_queue<Node> queue;

    for (const auto& v: frequency_table)
    {
        queue.push(Node(NULL, NULL, v));
    }
    while (queue.size() > 1)
    {
        Node* a = new Node(queue.top());
        queue.pop();
        Node* b = new Node(queue.top());
        queue.pop();
        queue.push(Node(a, b, std::make_pair(EOF, a->data.second + b->data.second)));
    }
    tree = new Node(queue.top());
    queue.pop();
    find_code_table(tree, "");
}

std::string Huffman::get_coded_message()
{
    std::string s = "";
    for (const auto& c : source)
    {
        s += code_table[c];
    }
    return s;
}

std::string Huffman::decode(std::string code)
{
    std::string output = "";
    Node* copy = tree;
    for (int i = 0; i < code.length(); ++i)
    {
        if (copy->data.first != EOF)
        {
            output += copy->data.first;
            copy = tree;
        }
        if (code[i] == '0')
        {
            copy = copy->left;
        }
        else
        {
            copy = copy->right;
        }
    }
    return output;
}
