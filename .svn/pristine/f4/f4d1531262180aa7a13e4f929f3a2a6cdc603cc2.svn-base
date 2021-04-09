#include <iostream>
#include <string>
#include <cstring>

#include "employees.h"

void CheckStream(const std::basic_ios<char>& stream) {
    if (stream.bad())
        std::cout << "Error while reading or writing data\n";
    if (stream.fail())
        std::cout << "Error: loss of integrity of the stream\n";
}

Employee::Employee() {
    _name = new char[MAX_NAME_LEN];
}

Employee::~Employee() {
    delete[] _name;
}

std::istream& operator>>(std::istream& stream, Employee& employee) {
    employee.read(stream);
    CheckStream(stream);
    return stream;
}

std::ostream& operator<<(std::ostream& stream, const Employee& employee) {
    employee.write(stream);
    CheckStream(stream);
    return stream;
}

int Developer::salary() const {
    int salary = _base_salary;
    if (_has_bonus) {
        salary += 1000;
    }
    return salary;
}

std::ofstream& operator<<(std::ofstream& stream, const Employee& employee) {
    employee.write_bin(stream);
    CheckStream(stream);
    return stream;
}

std::ifstream& operator>>(std::ifstream& stream, Employee& employee) {
    employee.read_bin(stream);
    CheckStream(stream);
    return stream;
}

void Developer::write(std::ostream& stream) const {
    stream << "Developer" << "\n" << "Name: " << _name << "\n" << "Base Salary: "
	    << _base_salary << "\n" << "Has bonus: ";
    if (_has_bonus)
	    stream << "+";
    else
	    stream << "-";
}

void Developer::read(std::istream& stream) {
    stream >> _name >> _base_salary >> _has_bonus;
}

void Developer::write_bin(std::ofstream& stream) const {
    stream << write_le_int32(DEV_TYPE) << write_c_str(_name) << write_le_int32(_base_salary) << write_bool(_has_bonus);
}

void Developer::read_bin(std::ifstream& stream) {
    stream >> read_c_str(_name, MAX_NAME_LEN) >> read_le_int32(_base_salary) >> read_bool(_has_bonus);
}

int SalesManager::salary() const {
    return _base_salary + _sold_nm * _price * 0.01;
}

void SalesManager::write(std::ostream& stream) const {
    stream << "Sales Manager" << "\n" << "Name: " << _name << "\n" << "Base Salary: " <<
	    _base_salary << "\n" << "Sold items: " << _sold_nm << "\n" << "Item price: " << _price;
}

void SalesManager::read(std::istream& stream) {
    stream >> _name >> _base_salary >> _sold_nm >> _price;
}

void SalesManager::write_bin(std::ofstream& stream) const {
    stream << write_le_int32(SALMAN_TYPE) << write_c_str(_name) << write_le_int32(_base_salary) << write_le_int32(_sold_nm) << write_le_int32(_price);
}

void SalesManager::read_bin(std::ifstream& stream) {
    stream >> read_c_str(_name, MAX_NAME_LEN) >> read_le_int32(_base_salary) >> read_le_int32(_sold_nm) >> read_le_int32(_price);
}
    
EmployeesArray::EmployeesArray(int32_t capacity) : _size(0), _capacity(capacity) {
    _employees = new Employee*[_capacity];
}

EmployeesArray::~EmployeesArray() {
    for (int32_t i = 0; i < _size; i++)
        delete _employees[i];
    delete [] _employees;
}

void EmployeesArray::add(Employee* employee) {
    if (_size == _capacity) {
        _capacity *= 2;
        Employee **employees_ = new Employee*[_capacity];
        memcpy(employees_, _employees, _size * sizeof(Employee *));
        delete [] _employees;
        _employees = employees_;
    }

    _employees[_size++] = employee;
}

int EmployeesArray::total_salary() const {
    int sum = 0;
    for (int32_t i = 0; i < _size; i++)
        sum += _employees[i]->salary();
    return sum;
}

std::ostream& operator<<(std::ostream& stream, const EmployeesArray& array) {
    for (int32_t i = 1; i <= array._size; i++) {
	    stream << i << ". " << *array._employees[i - 1] << "\n";
    }
    stream << "== Total salary: " << array.total_salary() << "\n";
    CheckStream(stream);
    return stream;
}

std::istream& operator>>(std::istream& stream, EmployeesArray& array) {
    int type;
    Employee *employee = nullptr;
    stream >> type;
    
	if (type == DEV_TYPE) {
        employee = new Developer;
	} else if (type == SALMAN_TYPE) {
        employee = new SalesManager;
	} else {
	    stream.setstate(std::ios::failbit);
	}
    stream >> *employee;
    array.add(employee);

    CheckStream(stream);
    return stream; 
}

std::ofstream& operator<<(std::ofstream& stream, const EmployeesArray& array) {
    stream << write_le_int32(array._size);
    for (int32_t i = 0; i < array._size; i++) {
	    stream << *array._employees[i];
    }

    CheckStream(stream);
    return stream;
}

std::ifstream& operator>>(std::ifstream& stream, EmployeesArray& array) {
    int32_t number_of_notes;
    stream >> read_le_int32(number_of_notes);
    for (int32_t i = 0; i < number_of_notes; i++) {
	    int32_t type;
        Employee *employee = nullptr;
	    stream >> read_le_int32(type);
	    if (type == DEV_TYPE) {
	        employee = new Developer;
	    } else if (type == SALMAN_TYPE) {
            employee = new SalesManager;
        } else {
	        stream.setstate(std::ios::failbit);
	        break;
	    }
        stream >> *employee;
        array.add(employee);
    }

    CheckStream(stream);
    return stream;
}