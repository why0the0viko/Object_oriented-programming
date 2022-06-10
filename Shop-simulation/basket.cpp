#include "basket.h"
#include <numeric>
#include <iostream>

std :: vector<Product> Basket :: getBasket()
{
    return basket;
}
void Basket :: setBasket(std :: vector<Product>&bas)
{
    basket = bas;
}
void Basket :: setBasketprod(Product& pro)
{
    basket.push_back(pro);
}
//method for price
double Basket :: PriceOfTheBasket()
{
    double res;
    res = std :: accumulate(basket.begin(), basket.end(), 0.0,[]( double i, Product a){return i + a.getPrice();});
    return res;
}
std :: ostream & operator<<(std :: ostream & out, const Basket &bas)
{
    for(int i = 0; i < bas.basket.size(); ++i)
    {
        out << bas.basket[i] << std :: endl;
    }
    return out;
}
