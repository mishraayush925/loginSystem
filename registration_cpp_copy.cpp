#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <time.h>

using namespace std;

void signup_function()
{
    system("CLS");
    ofstream new_file;
    fstream record_file;
    record_file.open("registration_record.txt", ios::app);

    char gender;
    string username, password, name, father, dob, email, phone, year, stram, college;

    cout << "*********  Personal Details **************" << endl
         << endl;
    cout << "User Name: ";
    cin >> username;
    new_file.open(username.c_str());

    cout << endl
         << "Password : ";

    cin >> password;
    new_file << password << endl;
    new_file << username << endl;
    cout << endl
         << "Name : ";
    cin.ignore();
    getline(cin, name);
    new_file << "Name : " << name << endl;
    cout << endl
         << "Gender(M/F) : ";
    cin >> gender;
    if (gender == 'M' || gender == 'm')
        new_file << "Gender : Male" << endl;
    else if (gender == 'f' || gender == 'F')
        new_file << "Gender : Female" << endl;
    else
    {
        cout << "Enter a Valid Gender !!!" << endl;

        cin >> gender;
        if (gender == 'M' || gender == 'm')
            new_file << "Gender : Male\n"
                     << endl;
        else if (gender == 'f' || gender == 'F')
            new_file << "Gender : Female\n"
                     << endl;
        else
        {
            cout << "Enter a Valid Gender !!!" << endl;
            return;
        }
    }

    cout << endl
         << "Date of Birth : ";
    cin >> dob;
    new_file << "Date of Birth : " << dob << endl;
    cout << endl
         << "Father's Name : ";
    cin.ignore();

    getline(cin, father);
    new_file << "Father's Name : " << father << endl;
    cout << endl
         << "Mobile Num : ";
    cin >> phone;
    new_file << "Mobile Num : " << phone << endl;
    cout << endl
         << "Email id : ";
    cin >> email;
    new_file << "Email : " << email << endl;
    cout << endl
         << "*********  Academic Details **************" << endl
         << endl;
    cout << endl
         << "College Name : ";
    cin.ignore();

    getline(cin, college);
    new_file << "College Name : " << college << endl;
    cout << endl
         << "Stream : ";
    cin.ignore();

    getline(cin, stram);
    new_file << "Stream : " << stram << endl;

    cout << endl
         << "Year : ";
    cin >> year;
    new_file << "Year : " << year << endl
             << endl;
    new_file << "***************************************************************";
    record_file << endl
                << endl;
    record_file << "Name          : " << name << endl;
    record_file << "Father's Name : " << father << endl;
    record_file << "College Name  : " << college << endl;
    record_file << "Stream        : " << stram << endl;

    record_file << "Email         : " << email << endl;
    record_file << "Contact Num   : " << phone << endl;
    time_t my_time = time(NULL);
    //cout<< ctime(&my_time);
    record_file << "Registered On :" << ctime(&my_time);
    record_file << "........................................................." << endl;
    new_file.close();
    record_file.close();
}

void login_function()
{
    char ans;
    string user_id, password, password_saved, words;
    ifstream new_file2;
    cout << "Enter Your User ID : ";
    cin >> user_id;
    new_file2.open(user_id.c_str(), ios::in);
    if (!new_file2)
    {
        cout << "No Record Found !!!" << endl;
        cout << "Do You Want To Register Yourself (Y/N)?" << endl;
        cin >> ans;
        if (ans == 'y' || ans == 'Y')
            signup_function();
        else
            return;
    }
    cout << "Enter your Password : ";
    cin >> password;
    new_file2 >> password_saved;
    if (password == password_saved)
    {
        system("CLS");
        cout << endl
             << "Logged in Successfully !!" << endl
             << endl;
        getline(new_file2, words);
        getline(new_file2, words);
        cout << "                      Hello User : " << words << "                      " << endl
             << endl;
        while (new_file2.eof() == 0)
        {
            getline(new_file2, words);
            cout << words << endl;
        }
    }
    else
    {
        cout << "Invalid Password !!!" << endl;
        return;
    }
}

void show_list()
{
    system("CLS");
    ifstream record_file;
    string words;
    cout << ".............. List of Registered Candidates............." << endl;
    record_file.open("registration_record.txt");
    while (record_file.eof() == 0)
    {
        getline(record_file, words);
        cout << words << endl;
    }
    record_file.close();
}

int main()
{
    int ch = 0;

    cout << "..................WELCOME TO REGISTRATION PORTAL ................" << endl
         << endl;

    cout << endl;

    while (ch != 4)
    {
        cout << endl
             << "1.Login" << endl
             << "2.Sign-Up" << endl
             << "3.List of Registered Candidates" << endl
             << "4.Exit" << endl
             << endl
             << "Input : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            login_function();
            cout << endl;
            break;
        case 2:
            cout << "Registration Form" << endl;
            signup_function();
            break;
        case 3:
            show_list();
            break;
        default:
            break;
        }
    }
    //login_function();
}