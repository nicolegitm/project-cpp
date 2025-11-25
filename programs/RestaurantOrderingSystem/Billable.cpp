#include <iostream>
#include <cstring>
#include "Billable.h"
#include "Utils.h"

using namespace std;

namespace seneca {

    // sets name to nullptr and price to zero 
    Billable::Billable()
        : m_name(nullptr), m_price(0.0) {}

    // duplicated price and name 
    Billable::Billable(const Billable& other)
        : m_name(nullptr), m_price(other.m_price) {
        if (other.m_name)
            ut.alocpy(m_name, other.m_name);  
    }

    Billable& Billable::operator=(const Billable& other) {
        if (this != &other) {
            m_price = other.m_price;
            ut.alocpy(m_name, other.m_name);   // safely copies name
        }
        return *this;
    }
 
    // frees the dynamically allocated name
    Billable::~Billable() {
        delete[] m_name;
    }

    // price stores to value 
    void Billable::price(double value) {
        m_price = value;
    }

    // set name
    void Billable::name(const char* nm) {
        ut.alocpy(m_name, nm);
    }

    // function to get price 
    double Billable::price() const {
        return m_price;
    }
 
    Billable::operator const char* () const {
    return (m_name && m_name[0] != '\0') ? m_name : nullptr;
}

    // adds price of billable to double and returns total 
    double operator+(double money, const Billable& B) {
        return money + B.price();
    }

    double& operator+=(double& money, const Billable& B) {
        money += B.price();
        return money;
    }

    // calls print
    ostream& operator<<(ostream& ostr, const Billable& B) {
    const char* nm = (const char*)B;
    if (nm) ostr << nm;
    return ostr;
}

}
