#!/usr/bin/python3

TokenType = str

# Identifiers + literals
IDENT = "IDENT"  # add, foobar, x, y, ...
INT = "INT"  # 1343456

# Operators
ASSIGN = "="
PLUS = "+"
MINUS = "-"
BANG = "!"
ASTERISK = "*"
SLASH = "/"

LT = "<"
GT = ">"
EQ = "=="
NOT_EQ = "!="

ILLEGAL = "ILLEGAL"
EOF = "EOF"
IDENT = "IDENT"
INT = "INT"
ASSIGN = "="
PLUS = "+"

COMMA = ","
SEMICOLON = ";"

LPAREN = "("
RPAREN = ")"
LPAREN = "{"
RPAREN = "}"

FUNCTION = "FUNCTION"
LET = "LET"
TRUE = "TRUE"
FALSE = "FALSE"
IF = "IF"
ELSE = "ELSE"
RETURN = "RETURN"


class Token:
    def __init__(self, tokenType: TokenType, literal: str):
        self.tokenType = tokenType
        self.literal = literal


keywords = {
    "fn": FUNCTION,
    "let": LET,
    "true": TRUE,
    "FALSE": FALSE,
    "IF": IF,
    "ELSE": ELSE,
    "RETURN": RETURN,
}


def lookup_ident(ident: str) -> str:
    token = keywords.get(ident)
    if token is not None:
        return token
    return IDENT
