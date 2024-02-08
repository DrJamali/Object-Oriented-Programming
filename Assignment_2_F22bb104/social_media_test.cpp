#include <iostream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;
class Comment
{
    static int next_id;
    int id;
    string content;
    string commentor;
    time_t time_stamp;

public:
    Comment()
    {
        id = next_id++;
        time_stamp = time(0);
    }
    Comment(string content, string commentor)
    {
        id = next_id++;
        content = content;
        commentor = commentor;
        time_stamp = time(0);
    }
    int getId()
    {
        return id;
    }
    string getContent()
    {
        return content;
    }
    string getCommentor()
    {
        return commentor;
    }
    time_t getTime_stamp()
    {
        return time_stamp;
    }
    void setId(int id)
    {
        this->id = id;
    }
    void setContent(string content)
    {
        this->content = content;
    }
    void display_cmnts()
    {
        cout << "id: " << id << endl;
        cout << "content: " << content << endl;
        cout << "commentor: " << commentor << endl;
        cout << "time stamp: " << time_stamp << endl;
    }
};
class Post
{
    static int next_id;
    int id;
    string content;
    time_t time_stamp;
    int likes;
    vector<Comment> comments;

public:
    Post()
    {
        id = next_id++;
        time_stamp = time(0);
        likes = 0;
    }
    Post(string content) : id(next_id++), content(content), time_stamp(time(0)), likes(0) {}
    int getId()
    {
        return id;
    }
    string getContent()
    {
        return content;
    }
    time_t getTime_stamp()
    {
        return time_stamp;
    }
    int getLikes()
    {
        return likes;
    }
    void setId(int id)
    {
        this->id = id;
    }
    void setContent(string content)
    {
        this->content = content;
    }
    void setTime_stamp(time_t time_stamp)
    {
        this->time_stamp = time_stamp;
    }
    void setLikes(int likes)
    {
        this->likes = likes;
    }
    void display()
    {
        cout << "Id: " << this->id << endl;
        cout << "Content: " << this->content << endl;
        cout << "Likes: " << this->likes << endl;
        cout << "Time Stamp: " << this->time_stamp << endl;
        for(int i = 0; i <comments.size();i++) {
            comments[i].display_cmnts();
        }
    }
    void operator+(int lik)
    {
        likes = likes + lik;
    }
};
class User
{
    string username;
    string email;
    string fullname;
    string DOB;
    vector<User> friends;
    vector<Post> posts;

public:
    User() = default;
    User(string username, string email, string fullname, string DOB) : username(username), email(email), fullname(fullname), DOB(DOB)
    {
    }
    string getUsername()
    {
        return username;
    }
    string getEmail()
    {
        return email;
    }
    string getFullname()
    {
        return fullname;
    }
    string getDOB()
    {
        return DOB;
    }
    void setUsername(string username)
    {
        this->username = username;
    }
    void setEmail(string email)
    {
        this->email = email;
    }
    void setFullname(string fullname)
    {
        this->fullname = fullname;
    }
    void setDOB(string DOB)
    {
        this->DOB = DOB;
    }
    void add_friend(User frnd)
    {
        friends.push_back(frnd);
    }
    void add_post(Post p)
    {
        posts.push_back(p);
    }
    bool operator==(User u1)
    {
       return this->username == u1.username;
    }
    void display_user_timeline()
    {
        cout << "User timeline: " << endl;
        cout << "Name: " << this->fullname << endl;
        cout << "email: " << this->email << endl;
        cout << "DOB: " << this->DOB << endl;
        for (int i = 0; i < posts.size(); i++)
        {
            posts[i].display();
        }
    }
};

int Comment::next_id = 1;
int Post::next_id = 1;
int main()
{
    User u1;
    Post p1;
    u1.add_post(p1);
    User u2;
    u1.add_friend(u2);
    u2.add_friend(u1);

    return 0;
}