//
// Created by andrzej on 18.05.24.
//

#pragma once

#include <iostream>
#include <string>

class FSElement {
public:
    virtual ~FSElement()  = default;
    virtual std::string getName() const = 0;
    virtual bool isDir() const = 0;
    virtual void print(int indent = 0) const = 0;
};