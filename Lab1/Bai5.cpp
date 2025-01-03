#include <iostream>
#include <string>
#include <cctype>

using namespace std;

enum TokenType {
    IDENTIFIER,
    OPERATOR,
    UNKNOWN
};

struct Token {
    TokenType type;
    string value;
};

void printToken(const Token &token) {
    switch (token.type) {
        case IDENTIFIER:
            cout << "<tên, " << token.value << ">" << endl;
            break;
        case OPERATOR:
            cout << "<toán tử, " << token.value << ">" << endl;
            break;
        default:
            cout << "<không xác định, " << token.value << ">" << endl;
            break;
    }
}

bool isOperator(char c) {
    return c == '=' || c == '+' || c == '-' || c == '*' || c == '/' || c == ';';
}

bool isIdentifierChar(char c) {
    return isalnum(c) || c == '_';
}

int main() {
    string expression = "Bien1=bien2+bien3;";
    string currentToken;
    TokenType currentType = UNKNOWN;

    for (char c : expression) {
        if (isIdentifierChar(c)) {
            if (currentType != IDENTIFIER) {
                if (!currentToken.empty()) {
                    printToken({currentType, currentToken});
                    currentToken.clear();
                }
                currentType = IDENTIFIER;
            }
            currentToken += c;
        } else if (isOperator(c)) {
            if (!currentToken.empty()) {
                printToken({currentType, currentToken});
                currentToken.clear();
            }
            currentToken = c;
            currentType = OPERATOR;
            printToken({currentType, currentToken});
            currentToken.clear();
            currentType = UNKNOWN;
        } else {
            if (!currentToken.empty()) {
                printToken({currentType, currentToken});
                currentToken.clear();
            }
            currentType = UNKNOWN;
        }
    }

    if (!currentToken.empty()) {
        printToken({currentType, currentToken});
    }

    return 0;
}
