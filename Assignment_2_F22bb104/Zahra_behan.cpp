#include <iostream>
#include <cstring>
#include <ctime>
#include <vector>
using namespace std;
class post{
    int postid;
    string content;
    static int previous_id;
    int likes;
    time_t timestamp;

public:
    
    post() {
        postid = previous_id++;
        likes = 0;
        timestamp = time(0);
        cout << "The time of the post created is" << timestamp << ctime(&timestamp) << endl;
    }

    post(string conten) : content(conten), postid(previous_id++), timestamp(time(0)), likes(0) {}

    // Getter methodsss
    int returnid() {
        return postid;
    }

    string getcontent() {
        return content;
    }

    int getlikes() {
        return likes;
    }

    time_t gettime() {
        return timestamp;
    }

    // Setter methods
    void setlike(int like) {
        likes = like;
    }

    void setconten(string conten) {
        content = conten;
    }

    void settimestamp(time_t timee) {
        timestamp = timee;
    }

    // Overloaded + operator to increment likes of the posts:
    void operator+(int like) {
        likes += like;
    }
};

// Comment Class
class comment{
    int comid;
    static int comment_id;
    string commentor;
    string content;
    time_t timestamp;

public:
    
    comment() {
        comid = comment_id++;
        timestamp = time(0);
        cout << "The time of the post created " << timestamp << ctime(&timestamp) << endl;
    }

    comment(string commentorr, string contentt)
        : commentor(commentorr), content(contentt), timestamp(time(0)), comid(comment_id) {}

    // Getter methods
    int getid() {
        return comid;
    }

    string getcommentor() {
        return commentor;
    }

    string getcontent() {
        return content;
    }

    time_t gettime() {
        return timestamp;
    }

    // Setter methods
    void setid(int id) {
        comid = id;
    }

    void setcommentor(string commentorrr) {
        commentor = commentorrr;
    }

    void setcontent(string contentt) {
        content = contentt;
    }

    void settimestamp(time_t timee) {
        timestamp = timee;
    }
};
// User Class is as follows:

class User{
    string username;
    string email;
    string full_name;
    string dateofbirth;
    vector<User>friends;
    vector<post>posts;

public:
    // Default constructor and parameterized constructor is called:
    User() = default;
    User(string usernamee, string mail, string fulname, string dob)
        : username(usernamee), email(mail), full_name(fulname), dateofbirth(dob) {}

    // Setter methods are called:  
    void setusername(string usernameee) {
        username = usernameee;
    }

    void setmail(string maill) {
        email = maill;
    }

    void setname(string ful_nam) {
        full_name = ful_nam;
    }

    void setdob(string DOB) {
        dateofbirth = DOB;
    }

    // Getter methods
    string getusername() {
        return username;
    }

    string getemail() {
        return email;
    }

    string getfulname() {
        return full_name;
    }

    string getDOB() {
        return dateofbirth;
    }
    void add_friend(User frind){
        friends.push_back(frind);
    }
    void add_post(post pos){
        posts.push_back(pos);
    }

    // Overloaded equality operator is being called:
    bool operator==(User userr1) {
        return username == userr1.username;
    }
};


// Initializing  static members here out of class

int comment::comment_id = 1;
int post::previous_id = 1;


int main() {
    
    post p;
    comment t;

    return 0;
}