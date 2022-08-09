#pragma once
#include "Libraries.h"
#include "Customer.h"
#include "Hall.h"

using namespace std;

class Billing :protected Customer, Hall
{
private:
    int ticketID;
    double price;
    Customer customer;
    Movie movie;
public:
    //constructors
    Billing() {}    //default constructor

    int getID()
    {
        return ticketID;
    }

    void saveTicket(Customer& customer, Movie movie, int timeshift, int numseats, int price,int ticketid)
    {
        
        fstream tickets;
        tickets.open("tickets.txt", ios::app);
        tickets << ticketID << " " << customer.getName() << " " << customer.getPhoneNumber() << " " << movie.getName() << " " << numseats << " " << price << endl;
        tickets.close();
    }


    /// MEMBER FUCTIONS
    void printTicket(Customer &customer,Movie movie,int timeshift,int numseats,int hall)
    {
        int ticketid = rand() % 899 + 100;
        double price = 0;
        int moviecount = customer.getMovieCount();
        cout << "===== Ticket =====" << endl;
        cout << "Name: " << customer.getName() << endl;
        cout << "Phone number: " << customer.getPhoneNumber() << endl;
        cout << "Movie: " << movie.getName() << endl;
        cout << "Time: ";
        if (timeshift == 1)
        {
            cout << "12:00 PM" << endl;
        }
        else
        {
            cout << "06:00 PM" << endl;
        }
        cout << "Hall: " << hall << endl;
        cout << "--------------------" << endl;
        cout << "Seats: "<<setw(20)<<800*numseats << endl;
        price = 800 * numseats;
        cout << "GST: 20% " << setw(18) << price * 0.20 << endl;
        price += price * 0.20;
        cout << "Discount: "<<setw(17);
        if (moviecount >= 3)
        {
            cout << price * 0.10 << endl;
            price += price * 0.10;
        }
        else
        {
            cout << "0.00" << endl;
        }
        cout << "Total: " << setw(20) << price << endl;
        cout << "\n\n" << endl;
        cout << "TICKET ID: " << ticketid << endl;
        this->ticketID = ticketid;
        this->price = price;
        
    }
    
   double getprice(int id)
    {
        return price;
    }

    void searchTicket()
    {
        int id;
        cout << "ID -> ";
        cin >> id;
///tickets << ticketID << " " << customer.getName() << " " << customer.getPhoneNumber() << " " << movie.getName() << " " << numseats << " " << price << endl;
        int ticketid;
        string name;
        string phonenum;
        string moviename;
        int numseats;
        int price;
        ifstream tickets;
        tickets.open("tickets.txt", ios::in);
        while (tickets >> ticketid >> name >> phonenum >> moviename >> numseats >> price)
        {
            if (id == ticketid)
            {
                system("CLS");
                cout << "===== TICKET DETAILS =====" << endl;
                cout << "Name: " << name << endl;
                cout << "Phone number: " << phonenum << endl;
                cout << "Movie: " << moviename << endl;
                cout << "Seats: " << numseats << endl;
                cout << "Price: " << price << endl;
            }
        }
        tickets.close();
    }
};

