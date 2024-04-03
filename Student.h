#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "User.h"
#include<string>
using namespace std;
class Student : public User {
public:
    Student();
    Student(const string& userid, const string& password, const string& username);
    bool login(const string& userid, const string& password, const string& username) override;
    void  viewProfile() override;
    void changePassword(const string& userid, const string& password, const string& username);
    void forgotPassword();
protected: 
    string name;
};

#endif


