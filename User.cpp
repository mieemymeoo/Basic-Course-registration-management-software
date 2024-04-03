#include "User.h"
#include <iostream>
using namespace std;
User::User(){}

User::User(const string& userid, const string& password, const string& username)
    : userid(userid), password(password), username(username) {}

bool User::login(const string& userid, const string& password, const string& username) {
    return true;
}

void User::changePassword(const string& newPassword) {
    password = newPassword;
    cout << "Doi mat khau thanh cong.\n";
}

void User::forgotPassword() {
    cout << "Lien he voi quan tri vien de thay doi mat khau";
}
void User::viewProfile() {
    cout<<username;

}
