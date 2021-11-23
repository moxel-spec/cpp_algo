
#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;


struct Node
{
  char ch;
  int freq;
  Node *left, *right;
};


Node* getNode(char ch, int freq, Node* left, Node* right)
{
  Node* node = new Node();

  node->ch = ch;
  node->freq = freq;
  node->left = left;
  node->right = right;

  return node;
}


struct comp
{
  bool operator()(Node* l, Node* r)
  {
    
    return l->freq > r->freq;
  }
};


void encode(Node* root, string str,
  unordered_map<char, string> &huffmanCode)
{
  if (root == nullptr)
    return;

 
  if (!root->left && !root->right) {
    huffmanCode[root->ch] = str;
  }

  encode(root->left, str + "0", huffmanCode);
  encode(root->right, str + "1", huffmanCode);
}


void decode(Node* root, int &index, string str)
{
  if (root == nullptr) {
    return;
  }

  
  if (!root->left && !root->right)
  {
    cout << root->ch;
    return;
  }

  index++;

  if (str[index] == '0')
    decode(root->left, index, str);
  else
    decode(root->right, index, str);
}


void buildHuffmanTree(string text)
{
  setlocale(LC_ALL, "Russian");
  
  unordered_map<char, int> freq;
  for (char ch : text) {
    freq[ch]++;
  }

 
  priority_queue<Node*, vector<Node*>, comp> pq;


  for (auto pair : freq) {
    pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
  }

  
  while (pq.size() != 1)
  {
   
    Node *left = pq.top(); pq.pop();
    Node *right = pq.top();  pq.pop();

    
    int sum = left->freq + right->freq;
    pq.push(getNode('\0', sum, left, right));
  }

  
  Node* root = pq.top();

  
  unordered_map<char, string> huffmanCode;
  encode(root, "", huffmanCode);
  cout << "|----------------------------------|" << endl;
  cout << "|В виде кода Хаффмана :            |" << '\n';
  for (auto pair : huffmanCode) {
    cout <<"|"<< pair.first << " " << pair.second << '\n';
  }
  cout << "|                                  |" << endl;
  cout << "|----------------------------------|" << endl;
  cout << "\n\n\n  " << endl;
  
  cout << "|----------------------------------|" << endl;
  cout << "|Оригинальный заданый текст :      |\n" << "|"<<text << '\n';
  cout << "|----------------------------------|" << endl;

  
  string str = "";
  for (char ch : text) {
    str += huffmanCode[ch];
  }
  cout << "\n\n\n  " << endl;
  cout << "|--------------------------------------------------------------------|" << endl;
  cout << "|Закодированый текст :                                               |\n" <<"|"<< str << '\n';
  cout << "|--------------------------------------------------------------------|" << endl;

  int index = -1;
  cout << "\n\n\n  " << endl;
  cout << "|----------------------------------|" << endl;
  cout << "|Розшифрованый текст:              | \n";
  while (index < (int)str.size() - 2) {
    decode(root, index, str);


}
  cout << "  " << endl;
  cout << "|----------------------------------|" << endl;
}


int main()
{
  setlocale(LC_ALL, "Russian");
  string text = "";
  int choice;
  for (;;)
  {
       cout << endl;
       cout  << " 1.Пример:\n" << endl;
       cout  << " 2 - Зашифровать ->  merezhkomaxim\n" << endl;
       cout << " 3 - Зашифровать -> предложение с клавиатуры.\n" << endl;
       cout << " 4 - Exit.\n" << endl;
       cout << " Enter your choice and press return: ";
      cin >> choice;
      switch (choice)
      {
        case 1:
        {
            text = "karazin university";
            buildHuffmanTree(text);
            break;
        }
        case 2:
        {
            text = "merezhkomaxim";
            buildHuffmanTree(text);
            break;
        }
        case 3:
        {
        std::cin.ignore(32767, '\n');
            //cin >> text;
             std::getline(std::cin,text);
             buildHuffmanTree(text);
             break;
        }
        case 4:
        {
            cout << "Выход из программы..." << endl;
            exit(EXIT_SUCCESS);
            break;
        }
        default:
        {
        cerr << "Неверный вариант!" << endl;
        exit(EXIT_FAILURE);
        }
      }
  }
 
    
   
    
    
    

    
  
}
