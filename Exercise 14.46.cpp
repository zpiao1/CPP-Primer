#include "Sales_data.h"
Sales_data::operator std::string() const
{
    return isbn() + " " + to_string(units_sold) + " " + revenue << " " << avg_price();
}
Sales_data::operator double() const 
{
    return revenue;
}