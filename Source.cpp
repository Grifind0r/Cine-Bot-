#include "Admin.h"
#include "Customer.h"
#include "Billing.h"
#include "Libraries.h"
#include "Hall.h"
#include "Seats.h"
#include "MoviesRepo.h"
#include "CustomerRepo.h"
using namespace std;

///Global variables

void pressEnter()
{
	char ch;
	ch = _getch();
}
int timecheck()
{
	system("CLS");
	int n;
	cout << "Select time\n";
	cout << "1. 12:00\n2. 06:00" << endl;
	cin >> n;
	return n;
}

int movieid()
{
	int id;
	cout << "ID -> ";
	cin >> id;
	return id;
}

int numSeats()
{
	int x;
	cout << "No of seats -> ";
	cin >> x;
	return x;
}

int MainMenu()
{
	int x;
	cout << "1. Admin" << endl;
	cout << "2. Customer" << endl;
	cout << "3. Exit" << endl;
	cout << "\n-> ";
	cin >> x;
	return x;
}

int main()
{
	srand(time(0));
	Admin a1;
	MoviesRepo mvrp;
	Hall h1;
	Movie movie;
	Hall h2;
	Billing bill;
	Customer c1;
	Customerrepo cr;
	bool stillWannaGo = true;
	cout << "--------------------------" << endl;
	cout << "Welcome To Cinebot\nYour World Of Movies Awaits" << endl << endl << endl;
	pressEnter();
	system("CLS");
	do
	{
		cout << "===== MAIN MENU =====" << endl;
		int x = MainMenu();
		string username;
		string password;
		bool check;
		int ticketid;
		int shift;
		int adminInput;
		int customerInput = 0;
		int customersignin;
		int selectedMovieID;
		int customerLogin;
		int numseats;
		bool stillCustomer = 1;
		switch (x)
		{
		case 1:
			system("CLS");
			check = a1.login();
			if (check)
			{
				do
				{
					system("CLS");
					adminInput = a1.Menu(check);
					switch (adminInput)
					{
					case 1:
						a1.changeCredentials();
						break;
					case 2:
						a1.addMovie();
						break;
					case 3:
						a1.displayMovies();
						pressEnter();
						break;
					case 4:
						a1.displayMovies();
						a1.deleteMovie();
						break;
					default:
						break;
					}
				} while (adminInput != 5);
			}
			else
			{
				system("CLS");
				cout << "DONT LOGIN AGAIN" << endl;
			}
			break;
		case 2:
			mvrp.fillMovies();
			cr.fill();
			customerLogin = c1.customerLoginMenu();
			switch (customerLogin)
			{
			case 1:
				system("CLS");
				cout << "==== CUSTOMER LOGIN ====" << endl;
				cout << "Username -> ";
				cin >> username;
				cout << "Password -> ";
				cin >> password;
				customersignin = cr.login(username,password);
				if (customersignin == 1)
				{
					c1 = cr.setCustomer(username, password);
					while (customerInput != 5)
					{
						system("CLS");
						customerInput = c1.customerMenu();
						system("CLS");
						switch (customerInput)
						{
						case 1:
							mvrp.showMovies();
							pressEnter();
							break;
						case 2:
							mvrp.showdetails();
							pressEnter();
							break;
						case 3:
							mvrp.showMovies();
							selectedMovieID = movieid();
							movie = mvrp.setmovie(selectedMovieID);
							shift = timecheck();
							system("CLS");
							numseats = numSeats();
							system("CLS");
							if (shift == 1)
							{
								h1.bookseat(numseats);
								pressEnter();
								system("CLS");
								bill.printTicket(c1, movie, shift, numseats, 1);
								ticketid = bill.getID();
								bill.saveTicket(c1, movie, shift, numseats, bill.getprice(ticketid), ticketid);
								cr.customerIncrease(username);
								pressEnter();
							}
							else
							{
								h2.bookseat(numseats);
								pressEnter();
								system("CLS");
								bill.printTicket(c1, movie, shift, numseats, 2);
								ticketid = bill.getID();
								bill.saveTicket(c1, movie, shift, numseats, bill.getprice(ticketid), ticketid);
								cr.customerIncrease(username);
								pressEnter();
							}
							cr.savedata();
							break;
						case 4:
							system("CLS");
							bill.searchTicket();
							pressEnter();
							break;
						default:
							break;
						}
					}
					
				}
				else
				{
					cout << "NOT FOUND" << endl;
				}
				break;
			case 2:
				c1.registerCustomer();
				cr.fill();
				break;
			default:
				break;
			}
			break;
		case 3:
			cout << endl;
			cout << "Have a great day ahead :)" << endl;
			cout << "BYE BYE" << endl;
			stillWannaGo = 0;
			break;
		default:
			cout << "Error" << endl;
			break;
		}
	} while (stillWannaGo);

	return 0;
}