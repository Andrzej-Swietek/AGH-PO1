//
// Created by andrzej on 18.05.24.
//

#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "FSElement.h"


class Dir : public FSElement {
    std::string name;
    std::vector<FSElement*> elements;

public:
    Dir(const std::string& name) : name(name) {}
    ~Dir() {
        for (FSElement* elem : elements) {
            delete elem;
        }
    }

    std::string getName() const override { return name; }
    bool isDir() const override { return true; }
    void add(FSElement* elem) { elements.push_back(elem); }

    Dir* findDir(const std::string& name) {
        for (FSElement* elem : elements) {
            if (elem->isDir() && elem->getName() == name) {
                return static_cast<Dir*>(elem);
            }
        }
        return nullptr;
    }

    void print(int indent = 0) const override {
        for (int i = 0; i < indent; ++i) std::cout << "  ";
        std::cout << name << " (DIR)" << std::endl;
        for (FSElement* elem : elements) {
            elem->print(indent + 1);
        }
    }

    void listDirs(int depth, int currentDepth = 0) const {
        if (currentDepth > depth) return;

        for (FSElement* elem : elements) {
            if (elem->isDir()) {
                std::cout << elem->getName() << " ";
                if (currentDepth < depth) {
                    static_cast<Dir*>(elem)->listDirs(depth, currentDepth + 1);
                }
            }
        }
    }

    void operator+=(FSElement* elem) {
        add(elem);
    }
};