// ParseException.h

#ifndef PARSE_EXCEPTION_H
#define PARSE_EXCEPTION_H

#include <exception>
#include <string>

class ParsingFailureException : public std::exception {
  //
private:
  std::string message;

public:
  ParsingFailureException(const std::string &msg) : message(msg) {}

  const char *what() const noexcept override { return message.c_str(); }
};
#endif
