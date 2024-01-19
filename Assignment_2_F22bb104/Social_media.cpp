#include <iostream>
#include <vector>
#include <string>
#include<ctime>
using namespace std;
struct Date
{
    int day;
    int month;
    int year;
};
class User
{
    string username;
    vector<User> Friends;
    string full_name;
    string email;
    Date Date_of_Birth;

public:
    User() = default;
    User(string username, string full_name, string email, Date Date_of_Birth) : username(username), full_name(full_name), email(email), Date_of_Birth(Date_of_Birth) {}
    string return_username()
    {
        return username;
    }
    string return_full_name()
    {
        return full_name;
    }
    string return_email()
    {
        return email;
    }
    Date return_Date_of_Birth()
    {
        return Date_of_Birth;
    }
    vector<User> return_Friends()
    {
        return Friends;
    }
    bool operator==( User &other)
    {
        return username == other.username;
    }
};

class Post{

    static int next_post_id;
    int post_id;
    int likes;
    string title;
    string content;
    time_t time_stamp;
    public:

    Post() = default;
    Post(string title, string content) : post_id(next_post_id++), title(title), content(content), time_stamp(time(0)) {
        likes = 0;
    }
    int return_id(){ return post_id; }
    string return_title(){ return title; }
    string return_content(){ return content; }
    time_t return_time_stamp(){ return time_stamp; }
    void operator+(int like){
       this->likes= this->likes+like;
    } 

};
int Post::next_post_id = 1;

int main() {

    std::string a = "Jamali";
    
    if (a.find("alij") != std::string::npos) {
        std::cout << "yes";
    } else {
        std::cout << "no";
    }
    return 0;
}
