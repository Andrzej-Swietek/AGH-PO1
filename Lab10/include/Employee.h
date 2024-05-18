#pragma once

struct Employee {
    
    /**
     * @brief Worker main constructor
     * @param[in] name - name of new worker
     * @param[in] job - whats ones new position would be
     * @param[in] hours - how many hours does one work
     * @param[in] salary - how much one earns per hours
     * @return no return
    */
    Employee(const std::string& name, const std::string& job, double hours, double salary) : name(name), job(job), salary(salary), hours(hours) {}


    /**
     * @brief Worker deconstructor
    */
    ~Employee() {}


    /**
     * @brief Method giving us workers details
     * @return no return 
    */
    void show() const {
        std::cout << name << " zarabia " << salary << " PLN" << std::endl;
    }


    /**
     * @brief Getter method for salaery
     * @return salery - how much worker earns
    */
    double getSalary() const { return salary; }


    /**
     * @brief Getter method for name
     * @return name - text - whats users name and lastname
    */
    std::string getName() const { return name; }

    std::string name;
    std::string job;
    double salary;
    double hours;
};
