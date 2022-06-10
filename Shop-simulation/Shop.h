#ifndef _SHOP_
#define _SHOP_
#include "Product.h"
#include <vector>
#include "Strategy.h"
class Shop
{
    private: 
    std :: vector<Product> catalog;
    Discount * _discount;

    public:
    void setProduct(std :: vector<Product>&);
    Product& getCatalog(int i);
    void setDiscount(Discount *);
    void addProduct(Product& pro);
    double finPrice(Basket&);
};
#endif