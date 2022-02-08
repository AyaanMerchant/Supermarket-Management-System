#include <iostream>
#include <conio.h>
#include <string>
#include <cmath>
#include <ctime>
#include <sstream>
#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

void welcome();
void selectOption();
void administator();
void productSupplier();
int display();
void basketPop();
void deleteProduct();
void buyProduct();
void marketBasket();
void modifyProduct();
void push(int data);
int search(int);
void addCustomer(string name);
void removeCustomer();
void customerList();
string check(int);
void title1();
void title2();
void title3();
void gotoxy(int x, int y);
void rectangle(int x, int y, int l, int b);
bool isEmpty();

//------------Customer-----------------//
class basket
{
public:
    int data;
    basket *link;
};
basket *top;

void push(int data)
{
    basket *temp = new basket();
    if (!temp)
    {
        gotoxy(31, 6);
        cout << "Heap Overflow";
        exit(1);
    }
    temp->data = data;
    temp->link = top;
    top = temp;
}

void basketPop()
{
    title2();
    rectangle(0, 0, 80, 23);
    basket *temp;

    if (top == NULL)
    {
        gotoxy(31, 6);
        cout << "Stack Underflow\n";
        gotoxy(26, 7);
        cout << "Press Any Key To Contiune!";
        getch();
        selectOption();
    }
    else
    {
        temp = top;
        top = top->link;
        temp->link = NULL;
        free(temp);
    }
    gotoxy(26, 6);
    cout << "Your Trolly No. Is: " << top->data << endl;
    gotoxy(26, 7);
    cout << "                  _____" << endl;
    gotoxy(26, 8);
    cout << "                 //  ||" << endl;
    gotoxy(26, 9);
    cout << "                //   --" << endl;
    gotoxy(26, 10);
    cout << " |___ __  ___ _|/     " << endl;
    gotoxy(26, 11);
    cout << " |__/___/___/__|     " << endl;
    gotoxy(26, 12);
    cout << " |_/___/___/___|     " << endl;
    gotoxy(26, 13);
    cout << "    |_______|         " << endl;
    gotoxy(26, 14);
    cout << "      O   O           " << endl;
    gotoxy(26, 16);
    cout << "Press Any Key TO Continue!";
    getch();
}

//-------------------Admin-----------------//
class Node
{
public:
    string customer_Name;
    Node *link;
};

Node *front = NULL;
Node *rear = NULL;

bool isEmpty() //Function to check if queue is empty or not
{
    if (front == NULL && rear == NULL)
        return true;
    else
        return false;
}

void addCustomer(string name) //function to enter elements in queue
{
    Node *ptr = new Node();
    ptr->customer_Name = name;
    ptr->link = NULL;

    if (front == NULL) //insert first node
    {
        front = ptr;
        rear = ptr;
    }
    else
    {
        rear->link = ptr;
        rear = ptr;
    }
}

void removeCustomer() //function to delete from queue
{
    if (isEmpty())
        cout << "Queue is empty\n";
    else

        if (front == rear) //one node in queue.
    {
        free(front);
        front = rear = NULL;
    }
    else
    {
        Node *ptr = front;
        front = front->link;
        free(ptr);
    }
}

void customerList() //Display queue
{
    title1();
    int counter = 7, count = 1;
    gotoxy(29, 6);
    cout << "CUSTOMERS NAMES LIST" << endl;
    if (isEmpty())
    {

        gotoxy(32, 10);
        cout << "Queue Is Empty\n";
        gotoxy(26, 11);
        cout << "Press Any Key To Continue!";
        getch();
    }
    else
    {
        Node *ptr = front;
        while (ptr != NULL)
        {
            gotoxy(4, counter);
            cout << count << "- " << ptr->customer_Name << "\n"
                 << endl;
            ptr = ptr->link;
            counter++;
            count++;
        }
        gotoxy(29, 20);
        cout << "Press Any Key To Continue!";
        getch();
    }
}

//----------Supplier------------//
class node
{
public:
    int ID;
    string product_Name;
    double prePrice;
    int quantity;
    struct node *next;
};
node *head = NULL;

void marketBasket()
{
    system("cls");

    title3();
    int id, quant;
    string name;
    double pre;
    node *t = new node;
    node *p = head;

    gotoxy(7, 7);
    cout << "\t\t\tEnter product ID:  ";
    cin >> id;
    t->ID = id;

    gotoxy(7, 9);
    cout << "\t\t\tEnter product Name:  ";
    cin >> name;
    t->product_Name = name;

    gotoxy(7, 11);
    cout << "\t\t\tEnter product price:  ";
    cin >> pre;
    t->prePrice = pre;

    gotoxy(7, 13);
    cout << "\t\t\tEnter product quantity:  ";
    cin >> quant;
    t->quantity = quant;

    if (head == NULL)
    {
        t->next = head;
        head = t;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = t;
        t->next = NULL;
    }
    gotoxy(25, 20);
    cout << "THIS PRODUCT IS INSERTED!";
    getch();
}

int search(int id) //search item in list
{
    int count = 1;
    node *p = head;
    while (p != NULL)
    {
        if (p->ID == id)
            break;
        else
            count++;
        p = p->next;
    }
    return count;
}

void deleteProduct()
{
    system("cls");
    title3();
    int c = 0, i = 10; //C for count products
    node *p = head;
    gotoxy(2, 6);
    cout << "Existing products are:\n";
    gotoxy(2, 8);
    cout << "ID\t\tProduct Name\t\tPrice\t\tQuantity\n";
    gotoxy(2, 9);
    cout << "---------------------------------------------------------------\n";
    while (p != NULL)
    {
        gotoxy(2, i);
        cout << p->ID << "\t\t" << p->product_Name << "\t\t\t" << p->prePrice << "\t\t" << check(p->quantity) << "\n"; //    call   check func and pass quantity
        p = p->next;
        c = c + 1;
        i++;
    }
    if (c == 0)
    {
        gotoxy(28, 20);
        cout << "No Product To Delete!";
        gotoxy(31, 21);
        cout << "List is empty!";
        getch();
        return;
    }
    int id;
    node *cur = head;
    node *pre = head;
    gotoxy(2, 15);
    cout << "Enter ID To Delete That Product: ";
    cin >> id;
    int pos = 0; //for load no of nodes
    int count = c;
    pos = search(id); //check node is exist or not
    if (pos == 1)     //for delete 1st product
    {
        head = head->next;
    }
    if (pos <= count)
    {
        while (cur->ID != id) //for delete rest of products
        {
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        gotoxy(30, 20);
        cout << "<<Item Is Deleted>>";
        getch();
    }
    else
    {
        gotoxy(30, 20);
        cout << "<<Item Not found>>";
        getch();
    }
}

void modifyProduct()
{
    title3();
    int id;
    double pre;
    string pName;
    int nid;
    int nq; // nq for new name
    if (head == NULL)
    {
        gotoxy(32, 7);
        cout << "List Is Empty!";
        getch();
    }
    else
    {
        int c = 0, i = 10; //C for count products
        node *p = head;
        gotoxy(2, 6);
        cout << "Existing Products Are:";
        gotoxy(2, 8);
        cout << "ID\t\tProduct Name\t\tPrice\t\tQuantity";
        gotoxy(2, 9);
        cout << "---------------------------------------------------------------";
        while (p != NULL)
        {
            gotoxy(2, i);
            cout << p->ID << "\t\t" << p->product_Name << "\t\t\t" << p->prePrice << "\t\t" << check(p->quantity) << "\n"; //    call   check func and pass quantity
            p = p->next;
            c = c + 1;
            i++;
        }
        gotoxy(2, 15);
        cout << "Enter ID to modify product Name and its price: ";
        cin >> id;
        node *cur = head;
        int pos = 0; //load no of nodes
        pos = search(id);
        int count = c; //heck node is exist or not

        if (pos <= count)
        {
            while (cur->ID != id)
            {
                cur = cur->next;
            }
            gotoxy(2, 17);
            cout << "Old ID: " << cur->ID;
            gotoxy(2, 18);
            cout << "Old Name: " << cur->product_Name;
            gotoxy(2, 19);
            cout << "Old Price: " << cur->prePrice;
            gotoxy(2, 20);
            cout << "Old Quantity: " << cur->quantity;

            gotoxy(45, 17);
            cout << "Enter New ID: ";
            cin >> nid;
            cur->ID = nid;
            gotoxy(45, 18);
            cout << "Enter New Name: ";
            cin >> pName;
            cur->product_Name = pName;
            gotoxy(45, 19);
            cout << "Enter New Price: ";
            cin >> pre;
            cur->prePrice = pre;
            gotoxy(45, 20);
            cout << "Enter New Quantity: ";
            cin >> nq;
            cur->quantity = nq;
            gotoxy(19, 21);
            cout << "Click Any Key To Confirm!";
            getch();
        }

        else
        {
            gotoxy(32, 21);
            cout << id << " is Not found!\n\n";
            gotoxy(28, 22);
            cout << "Click Any Key To Contiune!";
            getch();
        }
    }
}

int display()
{
    int c = 0, i = 10;
    node *ptr = head;
    gotoxy(2, 6);
    cout << "Existing products are:\n";
    gotoxy(2, 8);
    cout << "ID\t\tProduct Name\t\tPrice\t\tQuantity\n";
    gotoxy(2, 9);
    cout << "---------------------------------------------------------------\n";
    while (ptr != NULL)
    {
        gotoxy(2, i);
        cout << ptr->ID << "\t\t" << ptr->product_Name << "\t\t\t" << ptr->prePrice << "\t\t" << check(ptr->quantity) << "\n"; //    call   check func and pass quantity
        ptr = ptr->next;
        c = c + 1;
        i++;
    }
    gotoxy(22, 21);
    cout << "Total products in our store is : " << c;
    getch();
    return c;
}

string check(int quant) //check function
{
    int a = quant;
    stringstream ss;
    ss << a;
    string quantity = ss.str();

    if (quant <= 0)
        return "out of stock!";
    else
        return quantity;
}

void buyProduct()
{
    system("cls");
    title2();
    rectangle(0, 0, 80, 35);
    int a = 0, b = 10;
    node *p = head;
    gotoxy(2, 6);
    cout << "Existing products are:\n";
    gotoxy(2, 8);
    cout << "ID\t\tProduct Name\t\tPrice\t\tQuantity\n";
    gotoxy(2, 9);
    cout << "---------------------------------------------------------------\n";
    while (p != NULL)
    {
        gotoxy(2, b);
        cout << p->ID << "\t\t" << p->product_Name << "\t\t\t" << p->prePrice << "\t\t" << check(p->quantity) << "\n"; //    call   check func and pass quantity
        p = p->next;
        a++;
        b++;
    }

    string products[20]; //for display items which are sold
    int pay = 0, no, c = 0, price, id, i = 1;

    if (head == NULL)
    {
        gotoxy(28, 25);
        cout << "There Is No Items To Buy";
        gotoxy(27, 26);
        cout << "Press Any Key To Continue!";
        getch();
        selectOption();
    }
    else
    {
        gotoxy(3, 17);
        cout << "How Many Items You Want To Buy: ";
        cin >> no;
        int counter = 19;
        while (i <= no)
        {
            node *cur = head;
            int quant, cho; //quant = quantity and cho = choice
        a:
            gotoxy(3, counter);
            cout << "Enter Id Of Item You Want To Buy: ";
            int id, pos = 0;
            cin >> id;

            if (id == -1)
            {
                system("cls");
                return;
            }
            pos = search(id);
            if (pos <= a)
            {
                while (cur->ID != id) //item is available in store
                {
                    cur = cur->next;
                }
                gotoxy(3, counter + 1);
                cout << "How Many Quantity You want: ";
                cin >> quant;

                if (cur->quantity < quant)
                {
                    gotoxy(3, counter + 1);
                    cout << "The Quantity You Entered Is Not Available!";
                    counter = counter + 3;
                    goto a;
                }
                products[c] = cur->product_Name; //this conatin items names which we buy
                c++;

                pay = pay + (cur->prePrice * quant);
                cur->quantity = cur->quantity - quant; //change quantity
                i++;
                counter = counter + 3;
            }
            else
            {
                gotoxy(3, counter + 1);
                cout << "This Item Is Not Available In Our Supermarket At This Time!";
                counter = counter + 3;
            }
        }
        string customer;
        gotoxy(46, 17);
        cout << "Enter Your Name: ";
        cin >> customer;
        addCustomer(customer);
        gotoxy(46, 18);
        cout << "You Have Bought: ";
        for (int i = 0; i < no; i++)
        {
            cout << products[i] << ", "; //show product we bought
        }
        gotoxy(46, 20);
        cout << "Total Price: " << pay << " Rupees Only";
        gotoxy(46, 21);
        cout << "Thank You! For The Shopping";
        gotoxy(28, 34);
        cout << "Press Enter To Continue!";
        getch();
        selectOption();
    }
}

void administator()
{
    system("cls");
    int ch;

    do
    {
        title1();
        gotoxy(30, 6);
        cout << "ADMINSTATOR PORTAL" << endl;
        gotoxy(27, 8);
        cout << "1. Display All Products";
        gotoxy(27, 10);
        cout << "2. Customers List";
        gotoxy(27, 12);
        cout << "3. Dequeue Customer";
        gotoxy(27, 14);
        cout << "4. Back To Main Menu";
        gotoxy(1, 17);
        for (int i = 0; i < 78; i++)
            printf("_");
        gotoxy(20, 19);
        printf("Press a choice between the range [1-4] ");
        cin >> ch;
        switch (ch)
        {

        case 1:
            system("cls");
            title1();
            display();
            break;

        case 2:
            system("cls");
            customerList();
            break;

        case 3:
            system("cls");
            removeCustomer();
            customerList();
            break;

        case 4:
            system("cls");
            selectOption();
            break;

        default:
            system("cls");
        }
    } while (ch != 8);
}

void productSupplier()
{
    system("cls");
    int ch;

    do
    {
        title3();

        gotoxy(30, 6);
        cout << "SUPPLIER PORTAL" << endl;
        gotoxy(27, 8);
        cout << "1. Add A New Product" << endl;
        gotoxy(27, 10);
        cout << "2. Display All Products" << endl;
        gotoxy(27, 12);
        cout << "3. Modify Existing Product" << endl;
        gotoxy(27, 14);
        cout << "4. Delete A Product" << endl;
        gotoxy(27, 16);
        cout << "5. Back To Main Menu" << endl;
        gotoxy(1, 17);
        for (int i = 0; i < 78; i++)
            printf("_");
        gotoxy(20, 19);
        printf("Press a choice between the range [1-5] ");
        cin >> ch;
        switch (ch)
        {

        case 1:
            marketBasket();
            break;

        case 2:
            system("cls");
            title3();
            display();
            break;

        case 3:
            modifyProduct();
            break;

        case 4:
            deleteProduct();
            break;

        case 5:
            selectOption();
            break;

        default:
            system("cls");
        }
    } while (ch != 5);
}

void title1()
{
    int i;
    char ascii = 196;
    time_t t = time(NULL);
    tm *tPtr = localtime(&t);
    system("cls");
    rectangle(0, 0, 80, 23);
    gotoxy(25, 1);
    cout << "Supermarket Management System";
    gotoxy(4, 3);
    cout << "Current User: Admin";
    gotoxy(62, 3);
    cout << "Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
    gotoxy(1, 5);
    for (i = 0; i < 78; i++)
        cout << ascii;
}

void title2()
{
    int i;
    char ascii = 196;
    time_t t = time(NULL);
    tm *tPtr = localtime(&t);
    system("cls");

    gotoxy(25, 1);
    cout << "Supermarket Management System";
    gotoxy(4, 3);
    cout << "Current User: Customer";
    gotoxy(62, 3);
    cout << "Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
    gotoxy(1, 5);
    for (i = 0; i < 78; i++)
        cout << ascii;
}

void title3()
{
    int i;
    char ascii = 196;
    time_t t = time(NULL);
    tm *tPtr = localtime(&t);
    system("cls");
    rectangle(0, 0, 80, 23);
    gotoxy(25, 1);
    cout << "Supermarket Management System";
    gotoxy(4, 3);
    cout << "Current User: Supplier";
    gotoxy(62, 3);
    cout << "Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
    gotoxy(1, 5);
    for (i = 0; i < 78; i++)
        cout << ascii;
}

void welcome()
{
    int i;
    char ascii = 196;
    system("cls");
    rectangle(0, 0, 80, 20);
    gotoxy(24, 4);
    cout << "SUPERMARKET MANAGEMENT SYSTEM";
    gotoxy(24, 5);
    for (i = 0; i < 29; i++)
        cout << ascii;
    gotoxy(25, 8);
    cout << "Designed and Programmed by:";
    gotoxy(25, 9);
    for (i = 0; i < 27; i++)
        cout << ascii;
    gotoxy(28, 11);
    cout << "1- Ayaan Merchant";
    gotoxy(28, 13);
    cout << "2- Imadadullah";
    gotoxy(28, 15);
    cout << "3- Mohammad Shayan";
    gotoxy(24, 18);
    cout << "Press Any key to continue...";
    getch();
}

COORD coord = {0, 0};
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void rectangle(int x, int y, int l, int b)
{
    int i, m;
    char ascii1 = 201, ascii2 = 205, ascii3 = 187, ascii4 = 186, ascii5 = 200, ascii6 = 188;
    gotoxy(x, y);
    cout << ascii1;
    for (i = x + 1; i < l - 1; i++)
    {
        gotoxy(i, y);
        cout << ascii2;
    }
    gotoxy(i, y);
    cout << ascii3;

    for (m = y + 1; m < b; m++)
    {
        gotoxy(x, m);
        for (i = x; i < l; i++)
        {
            if (i == x || i == l - 1)
            {
                gotoxy(i, m);
                cout << ascii4;
            }
        }
    }
    gotoxy(x, m);
    cout << ascii5;
    for (i = x + 1; i < l - 1; i++)
    {
        gotoxy(i, m);
        cout << ascii2;
    }
    gotoxy(i, m);
    cout << ascii6;
}

void selectOption()
{
    char c;
    do
    {
        system("cls"); //Clears the screen
        rectangle(8, 9, 92, 13);
        gotoxy(10, 11);
        cout << "Press A to Log in as ADMIN or S to log in as SUPPLIER or C to log in as CUSTOMER\n\n\n\t\t\t\t\t";
        c = getche(); //Variable c stores the key pressed by user

        if (c == 'A' || c == 'a')
        {
            administator();
            break;
        }

        if (c == 'S' || c == 's')
        {
            productSupplier();
            break;
        }

        if (c == 'C' || c == 'c')
        {
            basketPop();
            buyProduct();
            break;
        }

        if (c == 27)
            exit(0); //27 is ASCII code of escape key, means program exits when user presses Esc key insted to A or S

    } while (1); //infinite loop incase any key other than Esc, A, or S is pressed.

    return;
}

int main()
{
    for (int i = 0; i <= 51; i++)
    {
        push(i);
    }
    welcome();
    selectOption();
}
