#ifndef PXML_NODE_H
#define PXML_NODE_H

#include <string>

namespace pxml
{

class Node
{
public:

  Node();
  ~Node();

  bool load(Node *parent);
  void free();

private:

  std::string m_tag;
  std::string m_innerText;

  Node *m_parent;
};

}

#endif
