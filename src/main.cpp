#include "main.h"

#include <iostream>

#include "pxml.h"

int main()
{
  pxml::Document doc;
  if (doc.load("resources/document.xml"))
  {
    doc.free();
  }

  doc.print_source(true);

  return 0;
}
