#include "Shop.h"
void Shop :: setProduct(std :: vector<Product>& vec)
{
    catalog = vec;
}
void Shop :: setDiscount(Discount *dis)
{
    _discount = dis;
}
void Shop :: addProduct(Product& pro)
{
    catalog.push_back(pro);
}
Product& Shop :: getCatalog(int i)
{
    return catalog[i];
}
double Shop :: finPrice(Basket& ba)
{
    // if(dynamic_cast<FixedDiscount*>(_discount) != NULL)
    // {
    //     return _discount->discount_basket(ba);
    // }
    // else if(dynamic_cast<RatioDiscount*>(_discount) != NULL)
    // {
    //     return _discount->discount_basket(ba);
    // }
    return _discount->discount_basket(ba);
}