//
// Created by andrzej on 18.05.24.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "Dir.h"
#include "File.h"

int main() {
    Dir* top = new Dir(".");
    Dir* home = new Dir("home");
    *top += home;
    *home += new Dir("ewa");
    *home += new File("proj.descr");
    home->add(new File("proj.files.repo"));
    home->add(new Dir("adam"));

    top->findDir("ewa")->add(new Dir("Desk"));

    Dir* ewa = home->findDir("ewa");
    *ewa += new File("pict.jpg");
    top->findDir("ewa")->add(new Dir("work"));

    top->print();
    std::cout << "--------------" << std::endl;
    top->listDirs(1);
    std::cout << std::endl << "--------------" << std::endl;
    top->listDirs(2);
    std::cout << std::endl;

    delete top;
    return 0;
}
