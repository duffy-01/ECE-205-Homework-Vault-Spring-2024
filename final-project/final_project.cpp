#include<iostream>
#include<string>
#include<stack>


class Node
{
public:
  char op;
  Node* left;
  Node* right;
public:
  Node(char op) : op(op), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
private:
  

  static bool compare (char op1, char op2)
  {
    if (op1 == '(' || op1 == ')')
      return false;
    return op1 == '*' || op1 == '/' || op1 == '+' || op1 == '-';
  }

  char pop(std::stack<char>& ops)
  {
    const char op = ops.top();
    ops.pop();
    return op;
  } 

  Node* pop(std::stack<Node*>& nodes)
  {
    Node* node = nodes.top();
    nodes.pop();
    return node;
  } 
  
  Node* makeNode(char op, Node* right, Node* left)
  {
    return new Node(op);
  }

public:
  
  
  Node* expressionTree (std::string str)
  {
    std::stack<Node*> nodes;
    std::stack<char> ops;

    for (const char c : str)
      if(isdigit(c))
        nodes.push(new Node(c));
      else if (c == '(')
        ops.push(c);
      else if (c == ')')
      {
        while (ops.top() != '(')
          nodes.push(makeNode(pop(ops), pop(nodes), pop(nodes)));
        ops.pop();
      }
      else if (c == '+'|| c == '-'|| c == '*'|| c == '/')
      {
        while (!ops.empty() && compare(ops.top(), c))
          nodes.push(makeNode(pop(ops), pop(nodes), pop(nodes)));
        ops.push(c);
      }
    
    while (!ops.empty())
      nodes.push(makeNode(pop(ops), pop(nodes), pop(nodes)));
  
    return nodes.top();
  }
  
  void printPostfix(Node* node)
  {
    if (node)
    {
      printPostfix(node->left);
      printPostfix(node->right);
      std::cout << node->op << " ";
    }
  }
};

int main() 
{
    BinaryTree tree;
    std::string expression = "((5+2)*(8-3))/4";
    Node* root = tree.expressionTree(expression);
    std::cout << "Postfix Expression: ";
    tree.printPostfix(root);
    std::cout << std::endl;

    return 0;
}