#pragma once

enum TypeToken {
    L_BRACE = 1, // {
    R_BRACE,
    L_PAREN, // (
    R_PAREN,
    L_SQUARE, // [
    R_SQUARE,

    INTEGER,

    INT,
    CHAR,
    CONST_CHAR,
    STRING,
    CONST_STRING,

    RETURN,

    SEMICOLON,
    COLON,
    COMMA,
    DOT,

    PLUS,
    MINUS,
    STAR,
    SLASH,
    PERCENT,

    EQUAL,
    EQUALEQUAL,
    LESS,
    GREATER,
    EXCLAIMEQUAL,

    AMPAMP,// &&
    PIPEPIPE, // ||
    
    DOUBLEQUOTES,
    QUOTES,
    WHILE,
    IF,
    ELSE,
    STATIC,
    VOID,
    ID,
    NEW,

    PRINT,
    INPUT,

    CONST_WORD,

    UNKNOWN
};
