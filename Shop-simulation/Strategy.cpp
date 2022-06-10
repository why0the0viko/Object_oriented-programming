#include "Strategy.h"
#include <iostream>
//discount
Discount :: Discount(Discount *_next , double _bound) 
: nextDiscount(_next), bound(_bound) {}
double Discount :: getBound() const
{
    return bound;
}
void Discount :: setBound(double _bound)
{
    bound = _bound;
}
Discount * Discount :: getDiscount() const
{
    return nextDiscount;
}
double Discount :: discount_basket(Basket & bas)
{
    return bas.PriceOfTheBasket();
}
//fixed discount
FixedDiscount :: FixedDiscount(Discount *_next, double _bound, double _minus) : Discount(_next, _bound)
{
    discountSum = _minus;
}
void FixedDiscount :: DisSumSet(double _minus)
{
    discountSum = _minus;
}
double FixedDiscount :: DisSumGet() const
{
    return discountSum;
}
void FixedDiscount :: BoundSet(double _bound)
{
    setBound(_bound);
}
double FixedDiscount :: BoundGet() const
{
    return getBound();
}
double FixedDiscount :: discount_basket(Basket& bas) 
{
    if(bas.PriceOfTheBasket() >= getBound())
    {
        return (bas.PriceOfTheBasket() - discountSum);
    }
    else if(bas.PriceOfTheBasket() < getBound())
    {
        if(getDiscount() == nullptr)
        {
            return bas.PriceOfTheBasket();
        }
        getDiscount()->discount_basket(bas); 
    }
}
//ratio discount
RatioDiscount :: RatioDiscount(Discount * _next, double _bound, double _proc) : Discount(_next, _bound)
{
    proc = _proc;
}
void RatioDiscount :: ProcSet(double _proc)
{
    proc = _proc;
}
void RatioDiscount :: BoundSet(double _bound)
{
    setBound(_bound);
}
double RatioDiscount :: ProcGet() const
{
    return proc;
}
double RatioDiscount :: BoundGet() const
{
    return getBound();
}
double RatioDiscount :: discount_basket(Basket& ba)
{
    double basketpr = ba.PriceOfTheBasket();
    if(basketpr >= getBound())
    {
        return (basketpr - (basketpr * (proc / 100)));
    }
    else if(basketpr < getBound())
    {
        if(getDiscount() == nullptr)
        {
            return basketpr;
        }
        getDiscount()->discount_basket(ba);
    }
    //return basketpr;
}