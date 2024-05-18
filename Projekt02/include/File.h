//
// Created by andrzej on 18.05.24.
//

#pragma once

#include <iostream>
#include <string>

#include "FSElement.h"

class File : public FSElement {
    std::string name;

public:
    File(const std::string& name) : name(name) {}
    std::string getName() const override { return name; }
    bool isDir() const override { return false; }
    void print(int indent = 0) const override {
        for (int i = 0; i < indent; ++i) std::cout << "  ";
        std::cout << name << " (FILE)" << std::endl;
    }
};
