#include "Company.h"

Company::Company()
{
}

Company::~Company()
{
}


void Company::addEmployee(const std::string& name,const std::string& job, double hours, double salary){
    Employee tmp(name, job, hours, salary);
    workers.push_back(tmp);
}


void Company::displayEmployees() const {
    for (const auto& worker : workers) {
        std::cout << worker.getName() << " - " << worker.getSalary()*worker.hours << " PLN" << std::endl;
    }
}


void Company::sortEmployees(std::function<bool(const Employee&, const Employee&)> comparator) {
    std::sort(workers.begin(), workers.end(), comparator);
}


void Company::removeEmployees(std::function<bool(const Employee&)> condition) {
    workers.erase(std::remove_if(workers.begin(), workers.end(), condition), workers.end());
}