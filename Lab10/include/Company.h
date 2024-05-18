#pragma once

#include <iostream>
#include <vector>
#include <Employee.h>
#include <functional>
#include <algorithm>

class Company
{
public:
    /**
     * Company Main (Deafult) Constructor
     * @return no return
    */
    Company();


    /**
     * Company Object (Destructor
     * @return no return
    */
    ~Company();

    /**
     * @brief Method allowing to manage workers by adding new one 
     * @param[in] name - name of new worker
     * @param[in] job - whats ones new position would be
     * @param[in] hours - how many hours does one work
     * @param[in] salary - how much one earns per hours
     * @return no return
    */
    void addEmployee(const std::string& name,const std::string& job, double hours, double salary);

    /**
     * Method allowing to list all users
     * @return no return
    */
    void displayEmployees() const;

    /**
     * Method allowing to sort users by given comparator function callback
     * @param[in] comparator - function comparing 2 workers returning bool
     * @return no return
    */
    void sortEmployees(std::function<bool(const Employee&, const Employee&)> comparator);

    /**
     * Method allowing to manage workers by removing by condition brought by lambda
     * @return no return
    */
    void removeEmployees(std::function<bool(const Employee&)> condition);
private:
    std::vector<Employee> workers;
};

