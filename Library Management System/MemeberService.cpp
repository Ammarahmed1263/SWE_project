#include "MemberService.h"
#include "Member.h"
using namespace std;
// Create a new library member. Check for email. Menu prompts user for input.
bool MemberService::addMember(string name,string email){
        // Check if email already exists
    for(Member &member:members){
        if(member.getEmail()== email){
            return false;
        }
    }
     // Add member to storage
    Member m(name,email);
    members.push_back(m);
    return true;
}


bool MemberService::removeMember(int memberID){
    for(auto it=members.begin(); it!=members.end() ;it++){
        if(it->getId()==memberID){
            members.erase(it);
            return true;
        }
    }
    return false;
}

//Show a formatted list of all members.
vector<Member>& MemberService::getAllMembers(){
    return members;
}

//Search by name, ID, or email. Case-insensitive. Menu prints results.
vector<Member> MemberService::searchMembers(string query){
    //new vector to add the matched members
    vector<Member> result;
    for (Member &m : members) {
        if ( m.getName() == query ||  m.getEmail() == query || to_string(m.getId()) == query) {
            result.push_back(m);
        }
    }

    return result;
}
