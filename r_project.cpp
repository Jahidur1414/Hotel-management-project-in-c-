/*
Author : Jahidur Rahman Fahim
Mail : jahidur15-1414@diu.edu.bd
*/
#include <bits/stdc++.h>
#include <conio.h>
#include <string>

using namespace std;
void start();

struct hotel
{
    string c_name;
    string c_mobile;
    int room_number;
    string room_type;
    int room_price;
    int b;
} arr[100];

int disison()
{
    cout<<"\n\t\t\tPress 1 for go back to main page and press 2 for exit !"<<endl;
    cout<<"\t\t\tInput --- >   ";
    int t;
    cin>>t;

    if(t==1)
    {
        system("cls");
        start();
    }
    else
    {
        system("cls");
        cout<<" See you again ! "<<endl;
        return 0;
    }
}
void checkroom()
{
    system("cls");
    cout<<"\n\t\t\t +----------------------------------------------------------+";
    cout<<"\n\t\t\t | Room Number    |       Room Type        |     Price      |";
    cout<<"\n\t\t\t +----------------------------------------------------------+"<<endl;
    cout<<endl;

    for(int i=0; i<100; i++)
    {
        if(arr[i].b==0)
        {
            cout<<"\n    \t\t\t|\t";
            cout<<arr[i].room_number;
            cout<<"\t|\t";
            cout<<arr[i].room_type;
            cout<<"\t|\t";
            cout<<arr[i].room_price<<"\t |"<<endl;
        }
    }
    disison();
}
void bookroom()
{
    system("cls");
    cout<<"\n\t\t\t\t Enter Room Number "<<endl;
    cout<<"\n\t\t Input ------ > ";
    int r;
    cin>>r;

    if(arr[r-1].b==1)
    {
        cout<<"\n\t\t\t This room is already booked .... Please try another one !"<<endl;
        cout<<endl;
        cout<<endl;
        disison();
    }
    else
    {
        arr[r-1].b=1;
        cout<<"\n\t\t\t\t Enter Customer Name "<<endl;
        cout<<"\n\t\t Input ------ > ";
        string name;
        cin>>name;
        arr[r-1].c_name=name;
        cout<<"\n\t\t\t\t Enter Customer Mobile Number "<<endl;
        cout<<"\n\t\t Input ------ > ";
        string number;
        cin>>number;
        arr[r-1].c_mobile=number;
        cout<<endl;

        cout<<"\t\t\t Total bill for this room is "<<arr[r-1].room_price<<" BDT"<<endl;
        cout<<"\n\t\t\t\t Thank You "<<endl;

        disison();
    }
}
void see_room_details()
{
    system("cls");
    cout<<"\n\t\t\t Press 1 for see all booked room with customer details "<<endl;
    cout<<"\n\t\t\t Press 2 for see available room "<<endl;
    cout<<"\n\t\t\t Press 3 for see specific room "<<endl;
    cout<<"\n\t\t Input ------ > ";
    int q;
    cin>>q;

    if(q==1)
    {
        system("cls");
        cout<<"\n\t\t\t +----------------------------------------------------------------------+";
        cout<<"\n\t\t\t | Room Number    |       Customer Name        |       Mobile Number    |";
        cout<<"\n\t\t\t +----------------------------------------------------------------------+"<<endl;
        cout<<endl;
        for(int i=0; i<100; i++)
        {
            if(arr[i].b==1)
            {
                cout<<"\n    \t\t\t|\t";
                cout<<arr[i].room_number;
                cout<<"\t|\t";
                cout<<arr[i].c_name;
                cout<<"\t|\t";
                cout<<arr[i].c_mobile<<"\t |"<<endl;
            }
        }
        disison();
    }
    else if(q==2)
    {
        checkroom();
    }
    else if(q==3)
    {
        cout<<"\t\t\t Enter the room number "<<endl;
        int e; cin>>e;
        system("cls");

        if(arr[e-1].b==0)
        {
            cout<<"\t\t\t This room is available"<<endl;
            cout<<"\t\t\t This is a "<<arr[e-1].room_type<<" type room"<<endl;
            cout<<"\t\t\t Price for this room is "<<arr[e-1].room_price<<" BDT"<<endl;
        }
        else{
            cout<<"\t\tThis room is booked and the customer name of this room is "<<arr[e-1].c_name<<endl;
            cout<<"\t\t\t Mobile number of "<<arr[e-1].c_name<<" is "<<arr[e-1].c_mobile<<endl;
        }
    }
    else{
        disison();
    }
}

void delete_update()
{
    system("cls");

    cout<<"\t\t\t Press 1 for cancel any booking "<<endl;
    cout<<"\t\t\t Press 2 for update anything"<<endl;
    cout<<"\n\t\t Input ------ > ";
    int w; cin>>w;

    if(w==1)
    {
        system("cls");
        cout<<"\t\t\t Enter the room number "<<endl;
        cout<<"\n\t\t Input ------ > ";
        int u; cin>>u;

        cout<<"\t\t Room number "<<u<<" which is booked by "<<arr[u-1].c_name<<" is canceled !"<<endl;
        arr[u-1].b=0;
        arr[u-1].c_mobile="";
        arr[u-1].c_name="";

        disison();
    }
    else if(w==2)
    {
        system("cls");

        cout<<"\t\t\t Press 1 for change room "<<endl;
        cout<<"\n\t\t Input ------ > ";
        int f; cin>>f;

        if(f==1)
        {
            cout<<"\t\t\t Enter old room number and new room number "<<endl;
            int n, o;
            cout<<"\n\t\t Old ------ > ";
            cin>>o;
            cout<<"\n\t\t New ------ > ";
            cin>>n;

            arr[n-1].b=1;
            arr[o-1].b=0;
            arr[n-1].c_mobile=arr[o-1].c_mobile;
            arr[o-1].c_mobile="";
            arr[n-1].c_name=arr[o-1].c_name;
            arr[o-1].c_name="";

            cout<<"\t\t For new room new price is "<<arr[n-1].room_price<<endl;
            cout<<"\t\t\t Room changed !"<<endl;
             disison();
        }
    }
    else{
        system("cls");
        cout<<"\t\t\t Wrong Input try again"<<endl;
        delete_update();
    }
}
void start()
{
    int choice;

    system("cls");
    //cout << string( 100, '\n' );
    cout<<"\n\t\t\t\t *************";
    cout<<"\n\t\t\t\t **THE HOTEL**";
    cout<<"\n\t\t\t\t *************";
    cout<<"\n\t\t\t\t * MAIN MENU *";
    cout<<"\n\t\t\t\t *************";
    cout<<"\n\t\t\t\t Press 1 for check available room";
    cout<<"\n\t\t\t\t press 2 for book room";
    cout<<"\n\t\t\t\t press 3 for see room details";
    cout<<"\n\t\t\t\t press 4 for delete booking or update booking";
    cout<<"\n\t\t\t\t press 5 for exit"<<endl;

    cout<<" Enter your choice ---- > ";

    cin>>choice;
    switch(choice)
    {
    case 1:
        checkroom();
        //cout<<" Check room "<<endl;
        break;
    case 2:
        bookroom();
        //cout<<" Bookroom "<<endl;
        break;
    case 3:
        see_room_details();
        //cout<<" See room details "<<endl;
        break;
    case 4:
        delete_update();
        //cout<<" Delete booking or update booking "<<endl;
        break;
    case 5:
        system("cls");
        cout<<" See you again ! "<<endl;
        break;
    default:
    {
        cout<<"\n\n\t\t\tWrong choice.";
        cout<<"\n\t\t\tPress 1 for try again and press 2 for exit !"<<endl;
        cout<<"\t\t\tInput --- >   ";
        int t;
        cin>>t;

        if(t==1)
        {
            system("cls");
            start();
        }
        else
        {
            system("cls");
            cout<<" See you again ! "<<endl;
        }
    }
    }
}
void data()
{
    for( int i=0; i<100; i++)
    {
        arr[i].b=0;
        arr[i].room_number=i+1;
        if(i+1<=10)
        {
            arr[i].room_type="Normal Single";
            arr[i].room_price=2000;
        }
        else if(i+1>10 && i+1<=30)
        {
            arr[i].room_type="Normal Double";
            arr[i].room_price=3000;
        }
        else if(i+1>30 && i+1<=50)
        {
            arr[i].room_type="Semi VIP Single";
            arr[i].room_price=4500;
        }
        else if(i+1>50 && i+1<=70)
        {
            arr[i].room_type="Semi VIP Double";
            arr[i].room_price=6000;
        }
        else if(i+1>70 && i+1<=90)
        {
            arr[i].room_type="VIP Single";
            arr[i].room_price=7000;
        }
        else
        {
            arr[i].room_type="VIP Double";
            arr[i].room_price=9000;
        }
    }
}
int main()
{
    data();
    system("clear");
    start();

    return 0;
}
