#include "Document.h"

#include <iostream>
#include <ios>

pxml::Document::Document()
: m_filename("")
{
}

pxml::Document::~Document()
{
}

bool pxml::Document::load(std::string filename)
{
  m_filename = filename;

  m_xmlfile.open(m_filename, std::ios::in);
  if (!m_xmlfile.is_open())
  {
    std::cerr << "Failed to open XML file \"" << m_filename << "\"" << std::endl;
    return false;
  }

  std::string line;
  while (std::getline(m_xmlfile, line))
  {
    m_lines.push_back(line);
  }

  return true;
}

void pxml::Document::free()
{
  m_xmlfile.close();
}

void pxml::Document::print_source(bool lineNumbering)
{
  typedef std::vector<std::string>::size_type vec_str_sz;

  vec_str_sz maxLineNum = m_lines.size();
  int lineNumberingSize = (std::to_string(maxLineNum + 1)).size();

  if (lineNumbering)
  {
    for (vec_str_sz i = 0; i < m_lines.size(); ++i)
    {
      std::string number = std::to_string(i + 1);
      std::string padding = std::string(lineNumberingSize - number.size(), ' ');
      std::string message = padding + number + ": " + m_lines[i];

      std::cout << message << std::endl;
    }
  }
  else
  {
    for (auto line: m_lines)
    {
      std::cout << line << std::endl;
    }
  }
}
