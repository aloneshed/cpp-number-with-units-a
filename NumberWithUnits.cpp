#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "NumberWithUnits.hpp"
using namespace ariel;

void NumberWithUnits::read_units(ifstream &file_name){

}

NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits& other) const{
    return *this;
}

NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits& other) {
    return *this;
}

NumberWithUnits& NumberWithUnits::operator+() {
    return *this;
}

NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits& other) const{
    return *this;
}

NumberWithUnits& NumberWithUnits::operator-=(const NumberWithUnits& other) {
    return *this;
}

NumberWithUnits NumberWithUnits::operator-() {
    return *this;
}

bool ariel::operator==(const NumberWithUnits& A, const NumberWithUnits& B){
    return true;
}

bool ariel::operator!=(const NumberWithUnits& A, const NumberWithUnits& B){
    return false;
}

bool ariel::operator>(const NumberWithUnits& A, const NumberWithUnits& B){
    return false;
}

bool ariel::operator>=(const NumberWithUnits& A, const NumberWithUnits& B){
    return false;
}

bool ariel::operator<(const NumberWithUnits& A, const NumberWithUnits& B){
    return false;
}

bool ariel::operator<=(const NumberWithUnits& A, const NumberWithUnits& B){
    return false;
}

NumberWithUnits NumberWithUnits::operator++(){ //prefix
    return *this;
} 

NumberWithUnits NumberWithUnits::operator++(int flag) { //postfix
    return *this;
}

NumberWithUnits NumberWithUnits::operator--(){ //prefix
    return *this;
}

NumberWithUnits NumberWithUnits::operator--(int flag){ //postfix
    return *this;
}

NumberWithUnits NumberWithUnits::operator*(double size){
    this->_number *= size;
    return *this;
}

NumberWithUnits ariel::operator*(double size, const NumberWithUnits& other){
    return NumberWithUnits(size, "");
}

// ostream& NumberWithUnits::operator<<(ostream& os){
//     return(os << to_string(_number) << '[' << _unit << ']');
// }

// istream& NumberWithUnits::operator>>(istream& is){
//     return is;
// } 

istream& ariel::operator>>(istream& is, NumberWithUnits number_unit){
    return is;
}

ostream& ariel::operator<<(ostream& os, NumberWithUnits number_unit){
    return(os << to_string(number_unit._number) << '[' << number_unit._unit << ']');
}