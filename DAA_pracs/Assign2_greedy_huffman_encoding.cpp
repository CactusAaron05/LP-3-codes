#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Node {
   char ch;
   int freq;
   Node *left, *right;

   Node(char c, int f, Node* l = nullptr, Node* r = nullptr)
       : ch(c), freq(f), left(l), right(r) {}
};

struct Compare {
   bool operator()(Node* a, Node* b) {
       return a->freq > b->freq;
   }
};

void printCodes(Node* root, string code = "") {
   if (!root)
       return;

   if (!root->left && !root->right) {
       cout << root->ch << " : "
            << (code.empty() ? "0" : code) << endl;
       return;
   }

   printCodes(root->left, code + "0");
   printCodes(root->right, code + "1");
}

void huffman(const vector<char>& chars, const vector<int>& freq) {
   priority_queue<Node*, vector<Node*>, Compare> pq;

   for (int i = 0; i < chars.size(); i++)
       pq.push(new Node(chars[i], freq[i]));

   while (pq.size() > 1) {
       Node* left = pq.top();
       pq.pop();
       Node* right = pq.top();
       pq.pop();

       pq.push(new Node('$', left->freq + right->freq, left, right));
   }

   cout << "\nHuffman Codes:\n";
   printCodes(pq.top());
}

int main() {
   int n;
   cout << "Enter number of characters: ";
   cin >> n;

   if (n <= 0) {
       cout << "Invalid number of characters.\n";
       return 0;
   }

   vector<char> chars(n);
   vector<int> freq(n);

   cout << "Enter characters and frequencies:\n";
   for (int i = 0; i < n; i++) {
       cin >> chars[i] >> freq[i];

       if (freq[i] < 0) {
           cout << "Frequency cannot be negative.\n";
           return 0;
       }
   }

   huffman(chars, freq);
   return 0;
}
