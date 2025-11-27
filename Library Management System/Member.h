#pragma once
#include <string>
using namespace std;

class Member {
private:
    static int nextMemberID;
    int memberID;
    string name;
    string email;

public:
    Member(string name, string email);
    int getId();
    string getName();
    string getEmail();
};
