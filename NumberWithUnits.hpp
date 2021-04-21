

namespace ariel
{
    class NumberWithUnits
    {
    private:
        double _number;
        std::string _unit;
    
    public:
        NumberWithUnits(double number, std::string unit): _number(number), _unit(unit){}
        static void read_units(std::ifstream &file_name);
        int get_number(){return _number;}
        std::string get_unit(){return _unit;}

        NumberWithUnits operator+(const NumberWithUnits& other) const;
        NumberWithUnits& operator+=(const NumberWithUnits& other);
        NumberWithUnits& operator+();

        NumberWithUnits operator-(const NumberWithUnits& other) const;
        NumberWithUnits& operator-=(const NumberWithUnits& other);
        NumberWithUnits operator-();

        friend bool operator==(const NumberWithUnits& A, const NumberWithUnits& B);
        friend bool operator!=(const NumberWithUnits& A, const NumberWithUnits& B);
        friend bool operator>(const NumberWithUnits& A, const NumberWithUnits& B);
        friend bool operator>=(const NumberWithUnits& A, const NumberWithUnits& B);
        friend bool operator<(const NumberWithUnits& A, const NumberWithUnits& B);
        friend bool operator<=(const NumberWithUnits& A, const NumberWithUnits& B);

        NumberWithUnits operator++(); //prefix
        NumberWithUnits operator++(int flag); //postfix
        NumberWithUnits operator--(); //prefix
        NumberWithUnits operator--(int flag); //postfix

        NumberWithUnits operator*(double size);
        friend NumberWithUnits operator*(double size, const NumberWithUnits& other);

        friend std::istream& operator>>(std::istream& is, NumberWithUnits number_unit);
        friend std::ostream& operator<<(std::ostream& os, NumberWithUnits number_unit);


        


        std::ostream& operator<<(std::ostream& os);
        std::istream& operator>>(std::istream& is);
        

    };

    
}