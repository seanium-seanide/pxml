#ifndef PXML_DOCUMENT_H
#define PXML_DOCUMENT_H

#include <string>
#include <fstream>
#include <vector>

#include "Node.h"

namespace pxml
{

class Document
{
public:

  Document();
  ~Document();

  bool load(std::string filename);
  void free();

  void print_source(bool lineNumbering = false);

private:

  std::string m_filename;
  std::ifstream m_xmlfile;
  std::vector<std::string> m_lines;

};

}

#endif
