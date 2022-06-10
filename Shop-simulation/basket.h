#ifndef _BASKET_
#define _BASKET_
#include "Product.h"
#include <vector>
class Basket
{
    private:
    std :: vector<Product> basket;
    public:
    
    std :: vector<Product> getBasket();
    void setBasket(std :: vector<Product>&);
    void setBasketprod(Product&);
    //method for price
    double PriceOfTheBasket();
    friend std :: ostream & operator<<(std :: ostream & out, const Basket & bas);

};
#endif