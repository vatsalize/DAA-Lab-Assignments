#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char c;         
    int data;        
    Node* left;
    Node* right;

    Node(char ch, int d) {
        c = ch;
        data = d;
        left = right = NULL;
    }
};

class cmp {
public:
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;                       // min heap
    }
};

class Solution {
public:

    void printCodes(Node* root, string temp) {

        if(!root) return;

        if(root->left == NULL && root->right == NULL) {                 // Leaf node par actual character hai
            cout << "   "<<root->c << "           " << temp << endl;
            return;
        }

        printCodes(root->left, temp + "0");
        printCodes(root->right, temp + "1");
    }

    void huffmanCodes(string S,vector<int> f,int N) {

        priority_queue<Node*, vector<Node*>, cmp> pq;

        for(int i = 0; i < N; i++) {
            pq.push(new Node(S[i], f[i]));
        }

        while(pq.size() > 1) {

            Node* left = pq.top(); pq.pop();
            Node* right = pq.top(); pq.pop();

            Node* newNode =
                new Node('\0', left->data + right->data);

            newNode->left = left;
            newNode->right = right;

            pq.push(newNode);
        }

        Node* root = pq.top();

        cout << "Character   Huffman Code\n";
        printCodes(root, "");
    }
};

int main() {

    string S = "abcdef";

    vector<int> freq = {5, 9, 12, 13, 16, 45};

    int N = S.size();

    Solution obj;

    obj.huffmanCodes(S, freq, N);

    return 0;
}
