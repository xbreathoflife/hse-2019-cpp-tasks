#ifndef LAB11_EMPLOYEES_H_INCLUDED
#define LAB11_EMPLOYEES_H_INCLUDED

#include <fstream>
#include <stdint.h>
#include <string>
#include <cstdlib>

#include "bin_manip.h"

const int32_t MAX_NAME_LEN = 102;

enum EmployeeType {
    DEV_TYPE = 1,
    SALMAN_TYPE = 2
};

void CheckStream(const std::basic_ios<char>& stream);

class Employee {
public: 
    Employee();
    virtual ~Employee();
    virtual int salary() const = 0;
    friend std::istream& operator>>(std::istream& stream, Employee& employee);
    friend std::ostream& operator<<(std::ostream& stream, const Employee& employee);
    friend std::ofstream& operator<<(std::ofstream& stream, const Employee& employee);
    friend std::ifstream& operator>>(std::ifstream& stream, Employee& employee);

protected:
    virtual void write(std::ostream& stream) const{}
    virtual void read(std::istream& stream) {}
    virtual void write_bin(std::ofstream& stream) const {}
    virtual void read_bin(std::ifstream& stream) {}
    char* _name = nullptr;
    int32_t _base_salary = 0;
};

class Developer : public Employee {
public:
    Developer() = default;
    ~Developer() = default;
    Developer& operator=(const Developer& other) = delete;
    int salary() const override;

protected:
    void write(std::ostream& stream) const override;
    void read(std::istream& stream) override;
    void write_bin(std::ofstream& stream) const override;
    void read_bin(std::ifstream& stream) override;

private:
    bool _has_bonus = 0;
};

class SalesManager : public Employee {
public:
    SalesManager() = default;
    ~SalesManager() = default;
    SalesManager& operator=(const SalesManager& other) = delete;
    int salary() const override;

protected:
    void write(std::ostream& stream) const override;
    void read(std::istream& stream) override;
    void write_bin(std::ofstream& stream) const override;
    void read_bin(std::ifstream& stream) override;

private:
    int32_t _sold_nm = 0, _price = 0;
};

class EmployeesArray {
public:
    EmployeesArray(int32_t capacity = 5);
    ~EmployeesArray();
    void add(Employee* employee);
    int total_salary() const;

    friend std::ostream& operator<<(std::ostream& stream, const EmployeesArray& array);
    friend std::istream& operator>>(std::istream& stream, EmployeesArray& array);
    friend std::ofstream& operator<<(std::ofstream& stream, const EmployeesArray& array);
    friend std::ifstream& operator>>(std::ifstream& stream, EmployeesArray& array);
private:
    Employee ** _employees;
    int32_t _size, _capacity;
};

#endif