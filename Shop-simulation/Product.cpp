#include "Product.h"
#include <iostream>
Product :: Product()
{
    name = "skol";
    price = 2.99;
    category = "food";

}
Product :: Product(std :: string na, double pr, std :: string cat) : name(na), price(pr), category(cat) {}
void Product :: setName(std :: string n)
{
    name = n;
}
void Product :: setprice(double pr)
{
    price = pr;
}
void Product :: setCategory(std :: string ca)
{
    category = ca;
}
std :: string Product :: getName()
{
    return name;
}
std :: string Product :: getCategory()
{
    return category;
}
double Product :: getPrice()
{
    return price;
}
std :: ostream& operator<<(std :: ostream& out, const Product &obj)
{
    out << "Name : "<< obj.name << ", " << "The original price : " << obj.price << ", " << "The category : "<< obj.category << std :: endl;
    return out;
}