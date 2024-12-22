// ParseException.h

#ifndef PARSE_EXCEPTION_H
#define PARSE_EXCEPTION_H

#include <exception>
#include <string>

class ParseException : public std::exception {
  //
private:
  std::string message;

public:
  ParseException(const std::string &msg) : message(msg) {}

  virtual const char *what() const noexcept override { return message.c_str(); }
};
#endif
