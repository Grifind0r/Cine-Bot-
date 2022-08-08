#include<iostream>
#include<fstream>
#include<windows.h>
#include<iomanip>
#include<conio.h>
#include<cstring>
#include<string>
#include <stdlib.h>
#include<time.h>

#ifdef _MSC_VER
#define getch() _getch()
#endif
int tickets = 0;
using namespace std;
class codeVerifier {
public:
    int code;
    void generate(){
        
        int temp;
        srand(time(0));
        re:
        code = (rand() % 5000) + 100;
        /*ifstream in("codes.txt");
        {
            while (!in.eof())
            {
                in >> temp;
                if (temp == code)
                {
                    goto re;
                }
            }
        }
        in.close();*/
        
        ofstream wr("codes.txt",ios::app);
        {
            wr << code << endl;
        }
        wr.close();
    }
    
};
class admin {
    string admin_id;
    string admin_pass;
public:
    void change_Admin_pass()
    {
        
        cout << "\nEnter new admin user name=";
        cin >> admin_id;
        cout << "\nEnter new admin password=";
        cin >> admin_pass;
        ofstream oa("admins.txt");
        {
            oa << admin_id << " " << admin_pass;
        }
        oa.close();
        cout << "\nSaved\n";
        
        cout << "\nPress any key to Continue.\n";
        getch();
        system("CLS");
    }

};
class customer {
public:    string name, gender, contact;

   
    
   
    void getdata() {
        ofstream out("Customers.txt");
        {
            cout << "Name=";
            cin >> this->name;
            cout << "Gender=";
            cin >> this->gender;
            cout << "Contact No=";
            cin >> this->contact;
        }
        out << this->name << " "  <<this->gender<<   " " << this->contact << endl;
        
        out.close();
        cout << "Saved!!!\nPress enter to go-to next menu\n" << endl;

    }
    char arr[1000];
    void display() {
        ifstream in("Customers.txt",ios:: app);
        {
            if (!in)
            {
                cout << "File Error!";
            }
            while (!(in.eof()))
            {
                in.getline(arr, 1000);
                cout << arr<<endl;
            }
            in.close();
        }
    }
};

class movie {

    
public:
    char movie_name[100];//admin
    string select_movie;//user movie seletion
    //char* smovieptr = &select_movie[0];
    int price = 0;
    int ticket_count=0;
    char mov[1000];
    int check;
    string type;
    
    
    void AddMovie() {
        ofstream add("Movies.txt", ios::app);
        {
            cout << "\nEnter a movie=";
            cin >> this->movie_name;
            
            cout << "\nSaved....\n";
            cout << "\nPress any key to Continue...\n";
        }
        add << movie_name << endl;
        add.close();
        getch();
        system("CLS");
    }
    void displayMovies()
    {
        ifstream in("Movies.txt");
        {
            if (!in)
            {
                cout << "File Error!";
            }
            while (!(in.eof()))
            {
                in.getline(mov,100);
                cout << mov << endl;
            }
            in.close();
        }
        cout << "\nPress any key to Continue...\n";
        getch();
        //system("CLS");
    }
    
    void SelectMovie()
    {
        int subcheck = 0;
       
        string temp;
        
           
            string ch;
            
            select_again:
            cout << "Enter the movie name=";
            cin >> ch;
            
            ifstream bring("Movies.txt");
            {
                if (!bring)
                {
                    cout << "File Error!";
                }
                while (!(bring.eof()))
                {
                    
                   bring>> temp;
                   /* cout << temp<<endl;
                    cout << ch<<endl;*/
                    if (compare(ch,temp))

                    {
                        subcheck = 1;
                        break;
                    }
                    
                    
                }
                bring.close();
                
            }
            if (subcheck == 1)
            {
                
                    this->select_movie=temp;
               
                
            }
            else
            {
               
                cout <<endl<< "Movie not found/not available\n";
                cout << "\nPress any key to select again\n";
                getch();
                system("CLS");
                goto select_again;
            }
            getch();
            system("CLS");
            
        
    }
    bool compare(string s1,string s2)
    {
       
            if (s1 != s2)
            {
                return false;
            }
            
        
        return true;
    }
    void selectTicketCount()
    {
        

        cout << "\nQuantity=";
        cin >> this->ticket_count;
        tickets = ticket_count;
        system("CLS");
        
    }
};
class hall {
public:
    int seats[40];
    int *user_seats = new int[tickets];

    void setter(){
        int scheck=0;//for seat check 
        cout << "Enter seat numbers to reserve them.\n";
        for (int i = 0; i < tickets; i++)
        {
        again:
            cout << "\nSeat No=";
            int scheck = 0;
            int check = 0;
            int temp = 0;
            cin >> temp;
            ifstream ou("reservedseats.txt");
            while (!(ou.eof()))
            {
                ou >> check;
                if (temp == check)
                {
                    scheck=1;
                    break;
                }

            }
            ou.close();
            if (scheck == 0)
            {
                this->user_seats[i] = temp;
                ofstream of("reservedseats.txt",ios::app);
                {
                    of << this->user_seats[i] << " ";
                }
            }
            else {
                cout << "Already reserved\n";
                goto again;
            }
        }
    }
    void display() {
        string str[40];
       // cout << "\n|-------------------------------------|\n";
        for (int i = 0; i < 40; i++)
        {
            int check = 0;
            ifstream ou("reservedseats.txt");
            while (!(ou.eof()))
            {
                ou >> check;
                if ((i + 1) == check)
                {
                    str[i]= "R ";
                    break;

                }
                
            }
            


        }
        cout << "\n|           CINEMA MAIN HALL          |\n";
        cout << "\n|-------------------------------------|\n";
        for (int i = 0; i < 40; i++)
        {
            if ((i + 1) == 10 || (i + 1) == 20 || (i + 1) == 30 )
            {
                cout  << i + 1 << endl;
            }
            else{
                if (str[i] == "R ")
                {
                    cout << str[i] << "  ";
                }
                else {
                    cout << i + 1 << "  ";
                }
            }
            
        }
        
       cout << "\n|-------------------------------------|\n";
    }
    

};
class reciept: public customer,movie,hall {
public:
    int total_bill=0;
    void display_reciept(customer &c1,movie &m1,hall &h1){
        codeVerifier cv1;
        cv1.generate();
        cout << "................CINE-BILL..................."<<endl;
        cout << "_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_"<<endl;
        cout <<"   -> Name           = " << c1.name<< endl;
        cout <<"   -> Movie          = " << m1.select_movie  <<endl;
        cout <<"   -> Tickets count  = " << tickets   <<endl;
        cout <<"   -> Seats reserved = ";
        for (int i = 0; i < tickets; i++)
        {
            cout << h1.user_seats[i] << " ";
        }
        cout  << endl;
        cout <<"   -> Hall           = Main Cinema Hall" <<endl;
        cout <<"   -> Total Bill     = " << 800 * tickets  <<endl;
        cout <<endl<<endl<< "  -> Verification Id= " << cv1.code << endl;
        cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-"<<endl;
        cout << "\n........Thank you for using CINEBOT.........\n";
        
        ofstream wr("verify.txt",ios::app);
        {
            wr << c1.name << " " << m1.select_movie << " " << tickets << " " << cv1.code << endl;

        }
        wr.close();
        cout << "\nPress any key for the start-up menu\n";
        getch();

    }
    
};
bool com(char arr1[], char arr2[])
{
    for (int i = 0; i < 100; i++)
    {
        if (arr1[i] != arr2[i])
        {
            return false;
        }

    }
    return true;
}
class Admin_Menu {
public:
    movie m1;
    void Display_Menu() {
        do {
            int check = 0;
            system("CLS");
            cout << "\n1. Add a movie\n2. Display all movies\n3. Change admin/pass\n4. Exit\n";
            cin >> check;
            if (check == 1)
            {
                system("CLS");
                m1.AddMovie();

            }
            else if (check == 2)
            {
                system("CLS");
                m1.displayMovies();
            }
            else if (check == 3)
            {
                system("CLS");
                admin a1;
                a1.change_Admin_pass();
            }

            else if (check == 4)
            {
                break;
            }
            else {
                cout << "Invalid Input";
                getch();
                break;
                system("CLS");
            }
        } while (1);
    }
};
void Customer_menu()
{

    while (1)
    {
        int main_check = 0;
        system("CLS");
        cout << "\n1. 1 FOR ADMIN CONTROLS\n2. 2 FOR CUSTOMER SERVICES\n ";
        cin >> main_check;
        if (main_check == 1)
        {
            char user_name[100];
            char pass[100];
            system("CLS");
            cout << "User Name=";
            cin >> user_name;
            cout << endl << "Password=";
            cin >> pass;
            char uiuser[100];
            char uipass[100];
            int new_check = 0;
            int new_check1 = 0;
            ifstream ui("admins.txt");
            {
                if (!ui)
                {
                    cout << "File Error!";
                }
                while (!(ui.eof()))
                {
                    ui >> uiuser>> uipass;

                    if (com(uiuser, user_name))

                    {
                        new_check = 1;
                        
                    }
                    if (com(uipass, pass))

                    {
                        new_check1 = 1;
                        
                    }
                }
                ui.close();

            }
            if (new_check == 1 && new_check1== 1)
            {
                system("CLS");
                
                Admin_Menu am;
                am.Display_Menu();
                system("CLS");
                
            }
            else {
                cout << "\nunauthorized\n";
                cout << "\nPress any key to go to previous menu.\n";
                system("CLS");
            }
        }
        else 
        {
            int user_select = 0;
            system("CLS");
            cout << "..........Enter your personal details.........." << endl;

            customer c1;
            c1.getdata();
            getch();
            system("CLS");
            cout << "1. 1 FOR DISPLAY ALL AVAILABLE MOVIES\n2. 2 FOR SELECT THE MOVIE\n3. 3 FOR EXIT\n";
            cin >> user_select;
            movie m1;
            if (user_select == 1)
            {
                int recheck0 = 0;
                system("CLS");
                m1.displayMovies();
                
                cout << "\nPress 1 to select the movie\n";
                cin >> recheck0;
                if (recheck0 == 1)
                {
                    goto s0;
                }

            }
            else if (user_select == 2)
            {
            s0:
                system("CLS");
                m1.SelectMovie();
                system("CLS");
                m1.selectTicketCount();
                system("CLS");
                hall h1;
                h1.display();
                h1.setter();
                system("CLS");
                reciept r1;
                r1.display_reciept(c1, m1, h1);
            }
            else if (user_select == 3)
            {
                system("CLS");
                cout << "........Thank you for using CINEBOT.........";
                break;
            }
            else {
                system("CLS");
                cout << "Wrong Input";
                getch();
                break;
            }
        }
        }
}

//class billing {
//public:
//    //Customer_menu();
//    movie m1;
//    void bill()
//    {
//        //c1.getdata();
//        system("CLS");
//      
//        m1.SelectMovie();
//        m1.selectTicketCount();
//
//        /*cout << "Name=" << c1.name << endl;
//        cout << "Movie=" << m1.select_movie<<endl;
//        cout << "Tickets=" << m1.ticket_count << endl;
//        cout << "Total Bill=" << (800 * m1.ticket_count) << endl;
//        */
//
//    }


//};
int main() {
    Customer_menu();
    /*billing b1;
    b1.bill();*/
}
