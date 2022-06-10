#ifndef _STRATEGY_
#define _STRATEGY_
#include "basket.h"
class Discount
{
    private:
    Discount * nextDiscount;
    double bound;
    public:
    //constructor
    Discount(Discount *_next = nullptr, double _bound = -1);
    //virtual double discount_basket(Basket&) = 0;
    virtual double discount_basket(Basket&);
    double getBound() const;
    void setBound(double );
    Discount *getDiscount() const;
    
};
class FixedDiscount : public Discount
{
    private:
    double discountSum;
    public:
    FixedDiscount(Discount * _next, double, double);
    void DisSumSet(double);
    double DisSumGet() const;
    void BoundSet(double);
    double BoundGet() const;
    double discount_basket(Basket&) override;
};
class RatioDiscount : public Discount
{
    private:

    double proc;


    public:
    RatioDiscount(Discount * _next , double, double);
    void ProcSet(double);
    void BoundSet(double);
    double ProcGet() const;
    double BoundGet() const;
    double discount_basket(Basket&) override;
};
#endif