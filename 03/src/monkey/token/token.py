#!/usr/bin/python3

class TokenType:


class Token:
    def __init__(self, token_type):
        self._token_type = token_type

    @property
    def token_type(self) -> TokenType:
        return self._token_type
