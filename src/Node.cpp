#include "Node.h"

pxml::Node::Node()
: m_tag("")
, m_innerText("")
, m_parent(nullptr)
{
}

pxml::Node::~Node()
{
}

bool pxml::Node::load(Node *parent)
{
  m_parent = parent;

  return true;
}
