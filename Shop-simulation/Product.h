#ifndef _PRODUCT_
#define _PRODUCT_
#include <string.h>
#include <string>
class Product
{
    private:

    std :: string name;
    double price;
    std :: string category;

    public:

    //construct
    Product();
    Product(std :: string name, double pr, std :: string cat); 
    void setName(std :: string);
    void setprice(double);
    void setCategory(std :: string);
    std :: string getName();
    std :: string getCategory();
    double getPrice();
    friend std :: ostream & operator<<(std :: ostream& out, const Product &obj);


};
#endif