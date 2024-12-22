// ParseException.h

#ifndef PARSE_EXCEPTION_H
#define PARSE_EXCEPTION_H

#include <exception>
#include <string>

class ParseException : public std::exception {
  //
private:
  std::string message;
};

#endif
