#pragma once
#ifndef TEACHER_H
#define TEACHER_H

#include "User.h"
using namespace std;

class Teacher : public User {
public:
    Teacher();
    Teacher(const string& userid, const string& password, const string& username);
    bool login(const string& userid, const string& password, const string& username) override;
    void viewProfile();
    void changePassword(const string& userid, const string& password, const string& username);
    void forgotPassword();
};

#endif

