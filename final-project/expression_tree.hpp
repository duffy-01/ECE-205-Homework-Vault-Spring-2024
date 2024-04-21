//expressiontree.hpp
#ifndef _EXPRESSION_TREE_
#define _EXPRESSION_TREE_

#include<string>
#include<stack>
#include<map>

class ExpressionTree
{
public:
  struct Node
  {
    Node(std::string v) : Value(v), left(NULL), right(NULL) {}
    std::string Value;
    Node *left, *right;
  }
};

#endif