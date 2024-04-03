#include<iostream>
#include<string>
#include"Student.h"
#include"Teacher.h"
using namespace std;
int main()
{
    Student s;
    Teacher t;
    while (true) {
        int choice;
        string userid, pass, username;
        cout << "Chon mot tuy chon\n";
        cout << "1.Dang nhap\n";
        cout << "2.Doi mat khau\n";
        cout << "3.Quen mat khau\n";
        cout << "4.Thoat phan mem\n";
        cin >> choice;
        system("cls");
        switch (choice) {
        case 1: {
            cout << "Ban da chon dang nhap.\n";
            int login;
            cout << "1.Giang vien\n";
            cout << "2.Sinh vien\n";
            cout << "Moi chon: "; cin >> login;
            cin.ignore();
            if (login == 1) {
                int attempt = 1;
                while (attempt <= 5) {
                    cout << "Nhap tai khoan: ";
                    getline(cin, userid);
                    cout << "Nhap mat khau:";
                    getline(cin, pass);
                    system("cls");
                    bool logingv = t.login(userid, pass, username);
                    if (logingv == true) {
                        cout << "Dang nhap thanh cong";
                        t.viewProfile();
                        cout << "Nhap mot tuy chon:\n";
                        cout << "1.Dang ki ca\n";
                        cout << "2.Huy ca\n";
                        cout << "3.Xem thong bao\n";
                        cout << "4.Phan hoi\n";
                        /////////////////////////
                        int n;
                        cin >> n;
                        break;
                    }
                    else {
                        cout << "Tai khoan hoac mat khau sai. Thu lai\n";
                        attempt++;
                    }
                    if (attempt > 5) {
                        cout << "Ban da nhap sai qua so lan cho phep";
                        t.forgotPassword();
                    }
                }
            }
            if (login == 2) {
                int attempt = 1;
                while (attempt <= 5) {
                    cout << "Nhap tai khoan: ";
                    getline(cin, userid);
                    cout << "Nhap mat khau:";
                    getline(cin, pass);
                    bool loginsv = s.login(userid, pass, username);
                    if (loginsv == true) {
                        cout << "Dang nhap thanh cong";
                        s.viewProfile();
                        cout << "Nhap mot tuy chon:\n";
                        cout << "1.Xem danh sach mon hoc\n";
                        cout << "2.Dang ki mon\n";
                        cout << "3.Huy mon\n";
                        cout << "4.Xem thoi khoa bieu";
                        cout << "5.Xem thong bao\n";
                        cout << "6.Phan hoi\n";
                        /////////////////////////
                        break;
                    }
                    else {
                        cout << "Tai khoan hoac mat khau sai. Thu lai\n";
                        attempt++;
                    }
                    if (attempt > 5) {
                        cout << "Ban da nhap sai qua so lan cho phep";
                        s.forgotPassword();
                    }
                }
            }
            break;
        }
        case 2:
            cout << "Ban da chon doi mat khau.\n";
            int change;
            cout << "1.Giang vien\n";
            cout << "2.Sinh vien\n";
            cout << "Moi chon: "; cin >> change;
            cin.ignore();
            if (change == 1) {
                t.changePassword(userid, pass, username);
            }
            if (change == 2) {
                s.changePassword(userid, pass, username);
            }
            break;
        case 3:
            cout << "Ban da chon quen mat khau.\n";
            s.forgotPassword();
            break;
        case 4:
            cout << "Chuong trinh da thoat";
            return 0;
        default:
            cout << "Lua chon khong hop le. Chon lai\n";
            break;
        }
    }
    
}