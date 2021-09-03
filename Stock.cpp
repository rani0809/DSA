#include <iostream>
#include "1_stock00.h"

void Stock::acquire (const std:: string & co, long n, double pr)
{
    company = co;
    
    if (n < 0)
    {
        std:: cout << "Number of shares cant be negative.\n" << company << " shares set to 0.\n";
        shares = 0;
    }
    else 
        shares = n;
    share_value = pr;
    set_total();
}

void Stock:: buy (long num, double price)
{
    if (num < 0)
         std::cout << "Number if shares cant be negative.\nTransaction is aborted.\n";
     else 
     {
         shares += num;
         share_value = price;
         set_total();
     }
}

void Stock:: sell(long num, double price)
{
    using std::cout;
    if (num < 0)
        cout << "Number of shares sold can't be negative.\nTransaction is aborted.\n";
     else if (num > shares)
         cout << "You cant sell more than you have.\nTransaction is aborted.\n";
     else 
     {
         shares -= num;
         share_value = price;
         set_total();
     }
}

void Stock :: show()
{
    std::cout << "Company: " << company << "\n"
            << "Shares: " << shares << "\n"
            << "Share Price: " << share_value << "\n"
            << "Total Worth: " << total_value << "\n";
}
