#pragma once
#include <string>
using namespace std;

class Member {
private:
    inline static int nextMemberID = 0;
    int memberID;
    string name;
    string email;

public:
    Member(string name, string email);

    string getId();
    string getName();
    string getEmail();
};
