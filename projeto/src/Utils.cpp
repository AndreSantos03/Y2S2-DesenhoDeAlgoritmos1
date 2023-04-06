//
// Created by diogo on 06/04/2023.
//

#include "../include/Utils.h"

string toUpperCase(const string &str) {
    string result;

    for (char c : str) {
        if (c >= 'a' && c <= 'z') {
            result += char(c - ('a' - 'A'));
        }
        else {
            result += c;
        }
    }

    return result;
}