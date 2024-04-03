#pragma once
#ifndef USER_H
#define USER_H

#include <string>
#include <fstream>
using namespace std;

class User {
public:
    User();
    User(const string& userid, const string& password, const string& username);
    virtual bool login(const string& userid, const string& password, const string& username); 
    virtual void changePassword(const string& newPassword);
    virtual void forgotPassword();
    virtual void viewProfile();
protected:
    string username;
    string password;
    string userid;
};

#endif



