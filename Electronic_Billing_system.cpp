#include <iostream>
#include <fstream>

using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    void menu();
    void adminstrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping ::menu()
{
top:
    int choice;
    string email;
    string password;

    cout << "\t\t\t+--------------------------------------+\n";
    cout << "\t\t\t|                                      |\n";
    cout << "\t\t\t|    Electronic Biling System          |\n";
    cout << "\t\t\t|                                      |\n";
    cout << "\t\t\t+--------------------------------------+\n";

    cout << "\t\t\t                                                     " << endl;
    cout << "\t\t\t=== 1.Administrator  ===                        " << endl;
    cout << "\t\t\t                                                     " << endl;
    cout << "\t\t\t=== 2.Buyer  ===                                " << endl;
    cout << "\t\t\t                                                     " << endl;
    cout << "\t\t\t=== 3.EXIT ===                                  " << endl;
    cout << "\t\t\t                                                     " << endl;
    cout << "\t\t\tPlease select from 1,2 or 3 =>> ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\t\t\t Please Login\n";
        cout << "\t\t\t Enter E-mail id : ";
        cin >> email;
        cout << "\t\t\t Enter Password  : ";
        cin >> password;

        if (email == "admin@gmail.com" && password == "admin123")
        {
            adminstrator();
        }
        else
        {
            cout << "Invalid Email/Password" << endl;
        }
        break;

    case 2:
    {
        buyer();
    }
    break;
    case 3:
    {
        exit(0);
    }
    break;
    default:
    {
        cout << "Please select from the given options";
    }
    }

    goto top;
}
void shopping ::adminstrator()
{
top1:
    int choice;
    cout << "\n\n\t\t\t~~~~~~~~~ADMINISTRATOR MENU~~~~~~~~~~~~~" << endl;
    cout << "\n";
    cout << "\t\t\t+--------------------------------------+" << endl;
    cout << "\t\t\t|     1)Add the product                |" << endl;
    cout << "\t\t\t|                                      |" << endl;
    cout << "\t\t\t|     2)Modify the product             |" << endl;
    cout << "\t\t\t|                                      |" << endl;
    cout << "\t\t\t|     3)Delete the product             |" << endl;
    cout << "\t\t\t|                                      |" << endl;
    cout << "\t\t\t|     4)List the products              |" << endl;
    cout << "\t\t\t|                                      |" << endl;
    cout << "\t\t\t|     5)Exit                           |" << endl;
    cout << "\t\t\t+--------------------------------------+" << endl;
    cout << endl;

    cout << "\n\n\t Please enter your choice : ";
    cin >> choice;

    switch (choice)
    {

    case 1:
        add();
        break;

    case 2:
        edit();
        break;

    case 3:
        rem();
        break;

    case 4:
        list();
        break;

    case 5:
        exit(0);

    default:
        cout << "Invalid choice!";
    }
    goto top1;
}

void shopping ::buyer()
{
top2:
    int choice;
    cout << "\n\n\t\t\t~~~~~~~~~~~~BUYER MENU~~~~~~~~~~~~~~~~~" << endl;
    cout << endl;
    cout << "\t\t\t+--------------------------------------+" << endl;
    cout << "\t\t\t|                                      |" << endl;
    cout << "\t\t\t|     1) Buy a Porduct                 |" << endl;
    cout << "\t\t\t|                                      |" << endl;
    cout << "\t\t\t|     2) Go Back                       |" << endl;
    cout << "\t\t\t|                                      |" << endl;
    cout << "\t\t\t+--------------------------------------+" << endl;
    cout << "\t\t\tEnter your choice! :  ";

    cin >> choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
        break;
    default:
        cout << "Invalid choice";
    }
    goto top2;
}

void shopping ::add()
{
top3:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\n\n\t-----------Add New Product------------";
    cout << "\n\n\tProduct code of the product : ";
    cin >> pcode;
    cout << "\n\n\tName of the  product : ";
    cin >> pname;
    cout << "\n\n\tPrice of the product : ";
    cin >> price;
    cout << "\n\n\tDiscount on product : ";
    cin >> dis;
    data.open("database.txt", ios::in); // File handling operation //in for opening file 'reading mode' && out for 'writing mode'
    if (!data)
    {
        data.open("database.txt", ios::app | ios::out); // if this file doesn't exist open in write mode (app=append mode)
        data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
        data.close(); // Closing the file
    }
    else
    {                             // IF data exist we will read from file
        data >> c >> n >> p >> d; // Initializing the file

        while (!data.eof())
        { // eof = End of file funtion
            if (c == pcode)
            {
                token++;
                cout << "This product code is already in use !" << endl;
            }
            data >> c >> n >> p >> d;
        }
        data.close();

        if (token == 1)
        {
            goto top3;
        }
        else
        {
            data.open("database.txt", ios::app | ios::out);
            data << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            data.close();
        }
    }
    cout << "\n\n\t\t Record Insrted !";
}

void shopping ::edit()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\n\t\t\t--------Modify the record-----------";
    cout << "\n\t\t\t Product code :";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\nFile doesn't exist!";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);

        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\t\t Product new code :";
                cin >> c;
                cout << "\n\t\t Name of the product";
                cin >> n;
                cout << "\n\t\t Price: ";
                cin >> p;
                cout << "\n\t\t Discount :";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\n\t\t Record edited";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Record not found";
        }
    }
}

void shopping::rem()
{
    fstream data, data1;
    int pkey;
    int token = 0;
    cout << "\n\n\t-----------Delete product--------";
    cout << "\n\n\t Enter the product code:";
    cin >> pkey;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "Error : File doesn't exists!";
    }
    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t Product deleted successfully";
                token++;
            }
            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Record not found";
        }
    }
}

void shopping::list()
{
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n_______________________________________________________\n";
    cout << "ProNo\t\tName\t\tPrice\t\tDiscount"
         << "\n";
    cout << "\n\n_______________________________________________________\n";
    data >> pcode >> pname >> price >> dis;
    while (!data.eof())
    {
        cout << pcode << "\t\t" << pname << "\t\t" << price << "\t\t" << dis << endl;
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}

void shopping::receipt()
{
    fstream data;

    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout << "\n\n\t\t\t\t List of Items";
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n Empty database";
    }
    else
    {
        data.close();

        list();
        cout << "\n____________________________________________________\n";
        cout << "\n|                                                   \n";
        cout << "\n              Please place the order                \n";
        cout << "\n|                                                   \n";
        cout << "\n____________________________________________________\n";

        do
        {
        m:
            cout << "\n\n Enter the product code : ";
            cin >> arrc[c];
            cout << "\n\n Enter the product quantity: ";
            cin >> arrq[c];
            for (int i = 0; i < c; ++i)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n\n Duplicate product code.Please try again.";
                    goto m;
                }
            }
            c++;
            cout << "\n\n Do you want to buy another product? if yes then press y else n:  ";
            cin >> choice;

        } while (choice == 'y');

        cout << "\n\n\t\t\t____________________RECEIPT___________________\n";
        cout << "\nProduct No\t Product Name\t Product quantity\tprice\tAmount\tAmount with discount\n";

        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;

            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i]; 
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << "\n"
                         << pcode << "\t\t" << pname << "\t\t\t" << arrq[i] << "\t\t" << price << "\t" << amount << "\t\t" << dis;
                }
                data >> pcode >> pname >> price >> dis;
            }
            data.close();
        }
    }
    cout << "\n\n______________________________________________";
    cout << "\n Total Amount : " << total;
}
int main()
{
    shopping s;
    s.menu();
}