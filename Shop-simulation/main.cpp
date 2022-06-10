#include <iostream>
#include "Shop.h"
#include "Product.h"
#include "Strategy.h"
#include "basket.h"
int main()
{
    //create a shop
    Shop shop;
    //creating products to fill a catalog
    Product prod1("johano Milk", 2.99, "food");
    Product prod2("charly golden choco bar", 12.85, "food");
    Product prod3("fork for justice", 1.55, "utensils");
    Product prod4("not today saTan knife", 2.55, "utensils");
    Product prod5("see better window-cleaner fluid", 3.74, "car stuff");
    Product prod6("need-for-slow brake fluid", 4.45, "car stuff");
    //fill the catalog
    shop.addProduct(prod1);
    shop.addProduct(prod2);
    shop.addProduct(prod3);
    shop.addProduct(prod4);
    shop.addProduct(prod5);
    shop.addProduct(prod6);
    //create dsicounts 
    /*
    FixedDiscount *fixDis = new FixedDiscount(13, 8.66);
    RatioDiscount *ratDis = new RatioDiscount(12, 15);
    */
    //TO DO: dynamic product objects, cuz i fucked it up

    //Basket creation and adding the Product from Catalog to Basket
    Basket bas;
    bas.setBasketprod(shop.getCatalog(0));
    bas.setBasketprod(shop.getCatalog(5));
    bas.setBasketprod(shop.getCatalog(2));
    bas.setBasketprod(shop.getCatalog(1));
    // print the content of the basket
    std :: cout << bas << std :: endl;
    std :: cout << "The price of the basket without discounts : " << bas.PriceOfTheBasket() << std :: endl;
    /*
    //use one discount <Fixed discount>
    shop.setDiscount(fixDis);
    std :: cout << "Price of the basket with fixed discount : " << shop.finPrice(bas) << std :: endl;
    //now change the discount type <Ratio discount>
    shop.setDiscount(ratDis);
    std :: cout << "Price of the basket with Ratio discount : " << shop.finPrice(bas) << std :: endl;
    
    //delete the pointers
    delete fixDis;
    delete ratDis;
    */
    Basket bas2;
    bas2.setBasketprod(shop.getCatalog(1));
    bas2.setBasketprod(shop.getCatalog(2));
    //bas2.setBasketprod(shop.getCatalog(5));
    bas2.setBasketprod(shop.getCatalog(4));
    bas2.setBasketprod(shop.getCatalog(6));
    std :: cout << "The price of the basket(2) without discounts : " << bas2.PriceOfTheBasket() << std :: endl;

    Basket bas3;
    bas3.setBasketprod(shop.getCatalog(2));
    std :: cout << "The price of the basket(3) without discounts : " << bas3.PriceOfTheBasket() << std :: endl;
   /*

    CHAIN OF RESPONSIBILITY <FIXED DISCOUNT>

   */

   //create a chain of fixed discounts
   //the last one in the chain
   FixedDiscount * fixdis10 = new FixedDiscount(nullptr, 10, 2.15);
   //the middle one in the chain
   FixedDiscount * fixdis15 = new FixedDiscount((Discount *)fixdis10, 15, 4.75);
   //the first one in the chain
   FixedDiscount * fixdis20 = new FixedDiscount((Discount *)fixdis15, 20, 7.84);
    
    //now we point to the chain <Fixed discount>

    shop.setDiscount(fixdis20);
    //ohh boy now its the first try
    std :: cout << "Price of the basket with fixed discount : " << shop.finPrice(bas) << std :: endl;
    std :: cout << "Price of the basket(2) with fixed discount : " << shop.finPrice(bas2) << std :: endl;
    std :: cout << "Price of the basket(3) with fixed discount : " << shop.finPrice(bas3) << std :: endl;


    /*
    CHAIN OF RESPONSIBILITY <RATIO DISCOUNT>
    */

    RatioDiscount * ratDis10 = new RatioDiscount(nullptr, 10, 8);
    RatioDiscount * ratDis15 = new RatioDiscount((Discount *)ratDis10, 15, 10);
    RatioDiscount * ratDis20 = new RatioDiscount((Discount *)ratDis15, 20, 11.5);

    shop.setDiscount(ratDis20);
    std :: cout << "Price of the basket with Ratiio discount : " << shop.finPrice(bas) << std :: endl;
    std :: cout << "Price of the basket(2) with Ratio discount : " << shop.finPrice(bas2) << std :: endl;
    std :: cout << "Price of the basket(3) with Ratio discount : " << shop.finPrice(bas3) << std :: endl;

    delete fixdis10;
    delete fixdis15;
    delete fixdis20;
    delete ratDis10;
    delete ratDis15;
    delete ratDis20;
    return 0;
}