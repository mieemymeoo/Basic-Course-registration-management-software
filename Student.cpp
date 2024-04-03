#include "Student.h"
#include <fstream>
#include <sstream>
#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
using namespace std;

Student::Student() {}

Student::Student(const string& userid, const string& password, const string& username)
    : User(userid, password, username) {}

bool Student::login(const string& userid, const string& password, const string& username) {
    ifstream file("studentaccount.txt");
    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string user, pass;
        if (!(iss >> user >> pass)) { break; }

        string name;
        getline(iss, name);  

        if (user == userid && pass == password) {
            this->username = name;
            return true;
        }
    }
    return false;
}




void Student::changePassword(const string& userid, const string& password, const string& username) {
    string currentUsername, currentPassword;

    cout << "Nhap tai khoan hien tai:";
    getline(cin, currentUsername);

    cout << "Nhap mat khau hien tai:";
    getline(cin, currentPassword);

    ifstream file("studentaccount.txt");
    string line;

    bool found = false;

    while (getline(file, line)) {
        istringstream iss(line);
        string user, pass, name;
        if (!(iss >> user >> pass >> name)) {
            cout << "Loi dong nay: " << line << endl;
            continue;
        }

        if (user == currentUsername && pass == currentPassword) {
            found = true;
            break;
        }
    }

    file.close();

    if (!found) {
        cout << "Tai khoan hoac mat khau hien tai khong chinh xac.\n";
        return;
    }

    string newPassword;
    cout << "Nhap mat khau moi: ";
    getline(cin, newPassword);

    vector<string> newLines;

    file.open("studentaccount.txt");
    while (getline(file, line)) {
        istringstream iss(line);
        string user, pass, name;
        if (!(iss >> user >> pass >> name)) {
            cout << "Loi dong nay: " << line << endl;
            continue;
        }

        if (user == currentUsername && pass == currentPassword) {
            pass = newPassword;
        }

        newLines.push_back(user + " " + pass + " " + name);
    }

    file.close();

    ofstream file_out("studentaccount.txt");

    for (const string& newLine : newLines) {
        file_out << newLine << "\n";
    }

    file_out.close();

    this->password = newPassword;
    cout << "Doi mat khau thanh cong.\n";
}

void Student::viewProfile() {
    cout << "\nChao mung:" << username << "\n";
}

void Student::forgotPassword() {
    User::forgotPassword();
}