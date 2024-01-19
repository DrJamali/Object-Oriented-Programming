#include <iostream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;
struct Date
{
    int day;
    int month;
    int year;
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
};
class Post;
class User
{
    string username;
    vector<User> friends;
    string full_name;
    string email;
    Date Date_of_Birth;
    vector<Post> Posts;

public:
    User() : username(""), full_name(""), email(""), Date_of_Birth({0, 0, 0}){};
    User(string username, string full_name, string email, Date Date_of_Birth) : username(username), full_name(full_name), email(email), Date_of_Birth(Date_of_Birth) {}
    ~User() {}
    void set_username()
    {
        cout << "Enter username: ";
        cin >> username;
    }
    void set_full_name()
    {
        cout << "Enter full name: ";
        cin >> full_name;
    }
    void set_email()
    {
        cout << "Enter email: ";
        cin >> email;
    }
    void set_Date_of_Birth()
    {
        cout << "Enter date of birth(DD MM YYYY): ";
        cin >> Date_of_Birth.day >> Date_of_Birth.month >> Date_of_Birth.year;
    }

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
        return friends;
    }
    bool operator==(User &other)
    {
        return username == other.username;
    }
    void add_friend(User &frnd)
    {
        friends.push_back(frnd);
    }
    void remove_friend(User &frnd)
    {
        for (int i = 0; i < friends.size(); i++)
        {
            if (friends[i] == frnd)
            {
                friends.erase(friends.begin() + i);
            }
        }
    }
    void add_post(Post &post)
    {
        Posts.push_back(post);
    }
    Post *return_post(int index)
    {
        return &Posts[index];
    }
    void remove_post(Post &post)
    {
        for (int i = 0; i < Posts.size(); i++)
        {
            if (Posts[i] == post)
            {
                Posts.erase(Posts.begin() + i);
            }
        }
    }
    void display_user()
    {
        cout << "Username: " << username << endl;
        cout << "Full Name: " << full_name << endl;
        cout << "Email: " << email << endl;
        cout << "Date of Birth: " << Date_of_Birth.day << "/" << Date_of_Birth.month << "/" << Date_of_Birth.year << endl;
        cout << "Friends: " << endl;
        if (friends.empty())
        {
            cout << "No friends available" << endl;
        }
        else
        {
            for (int i = 0; i < friends.size(); i++)
            {
                friends[i].display_user();
            }
        }
        cout << "Posts: " << endl;
        if (Posts.empty())
        {
            cout << "No posts available" << endl;
        }
        else
        {
            for (int i = 0; i < Posts.size(); i++)
            {
                Posts[i].display_post();
            }
        }
    }
    void display_frnds()
    {
        cout << "Friends: " << endl;
        if (friends.empty())
        {
            cout << "No friends available" << endl;
        }
        else
        {
            for (int i = 0; i < friends.size(); i++)
            {
                friends[i].display_user();
            }
        }
    }
};
class Comment
{
    static int next_cmnt_id;
    string content;
    User commentor;
    int comment_id;
    time_t time_stamp;

public:
    Comment() : comment_id(next_cmnt_id++), time_stamp(time(0)) {}
    Comment(string content, User commentor) : content(content), commentor(commentor), comment_id(next_cmnt_id++), time_stamp(time(0)) {}
    string return_content()
    {
        return content;
    }
    User return_commentor()
    {
        return commentor;
    }

    int return_comment_id()
    {
        return comment_id;
    }
    void display_comment()
    {

        cout << "Comment: " << content << endl;
        cout << "Commentor: " << commentor.return_username() << endl;
        cout << "Comment ID: " << comment_id << endl;
        cout << "Time Stamp: " << ctime(&time_stamp) << endl;
    }
    void set_content(string content)
    {
        this->content = content;
    }
    void set_commentor(User commentor)
    {
        this->commentor = commentor;
    }

    time_t return_time_stamp()
    {
        return time_stamp;
    }
    bool operator==(Comment c1)
    {
        return comment_id == c1.comment_id;
    }
};
int Comment::next_cmnt_id = 1;
class Post
{

    static int next_post_id;
    int post_id;
    int likes;
    string title;
    string content;
    time_t time_stamp;
    vector<Comment> comments;

public:
    Post() : post_id(next_post_id++), title(""), content(""), time_stamp(time(0)), likes(0) {}
    Post(string title, string content) : post_id(next_post_id++), title(title), content(content), time_stamp(time(0))
    {
        likes = 0;
    }
    void set_content(string content)
    {
        this->content = content;
    }
    void set_title(string title)
    {
        this->title = title;
    }

    int return_id() { return post_id; }
    string return_title() { return title; }
    string return_content() { return content; }
    time_t return_time_stamp() { return time_stamp; }
    Comment *return_cmnt(int index)
    {
        return &comments[index];
    }

    void add_cmnt(Comment &c1)
    {
        comments.push_back(c1);
    }
    void remove_cmnt(Comment &c1)
    {
        for (int i = 0; i < comments.size(); i++)
        {
            if (comments[i] == c1)
            {
                comments.erase(comments.begin() + i);
            }
        }
    }
    void display_post()
    {
        cout << "Post ID: " << post_id << endl;
        cout << "Title: " << title << endl;
        cout << "Content: " << content << endl;
        cout << "Time Stamp: " << ctime(&time_stamp) << endl;
        cout << "Comments: " << endl;
        if (comments.empty())
        {
            cout << "No comments available" << endl;
        }
        else
        {
            for (int i = 0; i < comments.size(); i++)
            {
                comments[i].display_comment();
            }
        }
    }
    void display_cmnts()
    {
        for (int i = 0; i < comments.size(); i++)
        {
            comments[i].display_comment();
        }
    }
    void operator+(int like)
    {
        this->likes = this->likes + like;
    }
    bool operator==(Post p1)
    {
        return p1.post_id == post_id;
    }
};
int Post::next_post_id = 1;
class Social_Media
{
    vector<User> users;

public:
    void add_user()
    {
        User u1;
        u1.set_username();
        u1.set_full_name();
        u1.set_email();
        u1.set_Date_of_Birth();
        users.push_back(u1);
    }
    void display_user()
    {
    }
    void signing_in_or_up()
    {
        User u1;
        cout << "Press 1 to sign in" << endl
             << "Press 2 to sign up" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            u1.set_username();
            u1.set_full_name();
            u1.set_email();
            u1.set_Date_of_Birth();
            users.push_back(u1);
        }
        else if (choice == 2)
        {
            cout << "Enter your username for signing in..." << endl;
            string key;
            cin >> key;
            for (int i = 0; i < users.size(); i++)
            {
                if (key == users[i].return_username())
                {
                    u1 = users[i];
                }
            }
        }
    }
};
int main()
{

    User u1("John", "<NAME>", "<EMAIL>", Date(1, 1, 1990));
    u1.display_user();
    Comment c1("This is a comment", u1);
    c1.display_comment();

    return 0;
}
