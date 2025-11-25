
#ifndef SENECA_BILLABLE_H
#define SENECA_BILLABLE_H

#include <iostream>
#include <fstream>

namespace seneca {

    class Billable {
        char* m_name{};     // dynamically allocated name
        double m_price{};   // base price

    protected:
        // set price
        void price(double value);

        // set name with dynamic allocation
        void name(const char* nm);

    public:
        // Rule of Three
        Billable();
        Billable(const Billable& other);
        Billable& operator=(const Billable& other);
        virtual ~Billable();

        // Access for base price
        virtual double price() const;

        // must be implemented by derived classes
        virtual std::ostream& print(std::ostream& ostr = std::cout) const = 0;
        virtual bool order() = 0;
        virtual bool ordered() const = 0;
        virtual std::ifstream& read(std::ifstream& file) = 0;

        // conversion operator for name access
        operator const char* () const;

        // friend operator overloads for adding price
        friend double operator+(double money, const Billable& B);
        friend double& operator+=(double& money, const Billable& B);
    };

    // insertion operator 
    std::ostream& operator<<(std::ostream& ostr, const Billable& B);

}

#endif // SENECA_BILLABLE_H
