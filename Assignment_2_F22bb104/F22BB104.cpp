
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <unistd.h>
#include <stdlib.h>
using namespace std;

class User;
struct Date
{
    int day;
    int month;
    int year;
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
};

class Comment
{
    static int next_cmnt_id;
    string content;
    string commentor;
    int comment_id;
    time_t time_stamp;

public:
    // Constructor with automatic comment ID incrementation and timestamp
    Comment() : comment_id(next_cmnt_id++), time_stamp(time(0)) {}

    // Parameterized constructor to set content, commentor, comment ID, and timestamp
    Comment(string content, string commentor) : content(content), commentor(commentor), comment_id(next_cmnt_id++), time_stamp(time(0)) {}

    // Getter functions
    string return_content() { return content; }
    string return_commentor() { return commentor; }
    int return_comment_id() { return comment_id; }

    // Display comment information
    void display_comment()
    {
        cout << "Comment: " << content << endl;
        cout << "Commentor: " << commentor << endl;
        cout << "Comment ID: " << comment_id << endl;
        cout << "Time Stamp: " << ctime(&time_stamp) << endl;
    }

    // Set content using user input
    void set_content()
    {
        cout << "Enter comment: ";
        cin >> content;
    }

    // Set commentor
    void set_commentor(string commentor)
    {
        this->commentor = commentor;
    }

    // Return timestamp
    time_t return_time_stamp()
    {
        return time_stamp;
    }

    // Overloaded equality operator
    bool operator==(Comment c1)
    {
        return comment_id == c1.comment_id;
    }
};

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
    // Constructor with automatic post ID incrementation and default values
    Post() : post_id(next_post_id++), title(""), content(""), time_stamp(time(0)), likes(0) {}

    // Parameterized constructor to set title and content, with automatic post ID incrementation and timestamp
    Post(string title, string content) : post_id(next_post_id++), title(title), content(content), time_stamp(time(0)), likes(0) {}

    // Set content using user input
    void set_content()
    {
        cout << "Enter content: " << endl;
        cin.ignore(); // Ignore newline character from previous input
        getline(cin, content);
    }

    // Set title using user input
    void set_title()
    {
        cout << "Enter title: " << endl;
        getline(cin, title);
    }

    // Getter functions
    int return_id() { return post_id; }
    string return_title() { return title; }
    string return_content() { return content; }
    time_t return_time_stamp() { return time_stamp; }

    // Return a pointer to a comment at a specific index
    Comment *return_cmnt(int index)
    {
        return &comments[index];
    }

    // Add a comment to the post
    void add_cmnt(Comment &c1)
    {
        comments.push_back(c1);
    }

    // Remove a comment from the post
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

    // Display post information
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

    // Display comments of the post
    void display_cmnts()
    {
        for (int i = 0; i < comments.size(); i++)
        {
            comments[i].display_comment();
        }
    }

    // Overloaded addition operator to increment likes
    void operator+(int like)
    {
        this->likes = this->likes + like;
    }

    // Overloaded equality operator
    bool operator==(Post p1)
    {
        return p1.post_id == post_id;
    }
};

int Post::next_post_id = 1;

class Message;

class User
{
    string username;
    vector<User> friends;
    string full_name;
    string email;
    Date Date_of_Birth;
    vector<Post> posts;
    vector<Message> messages;

public:
    // Default constructor with default values
    User() : username(""), full_name(""), email(""), Date_of_Birth({0, 0, 0}){};

    // Parameterized constructor to set username, full name, email, and date of birth
    User(string username, string full_name, string email, Date Date_of_Birth) : username(username), full_name(full_name), email(email), Date_of_Birth(Date_of_Birth) {}

    // Destructor
    ~User() {}

    // Set username using user input
    void set_username()
    {
        cout << "Enter username: ";
        getline(cin, username);
    }

    // Set full name using user input
    void set_full_name()
    {
        cout << "Enter full name: ";
        getline(cin, full_name);
    }

    // Set email using user input
    void set_email()
    {
        cout << "Enter email: ";
        getline(cin, email);
    }

    // Set date of birth using user input
    void set_Date_of_Birth()
    {
        cout << "Enter date of birth (DD MM YYYY): ";
        cin >> Date_of_Birth.day >> Date_of_Birth.month >> Date_of_Birth.year;
    }

    // Getter functions
    string return_username() { return username; }
    string return_full_name() { return full_name; }
    string return_email() { return email; }
    Date return_Date_of_Birth() { return Date_of_Birth; }
    vector<User> return_Friends() { return friends; }

    // Overloaded equality operator
    bool operator==(User &other)
    {
        return username == other.username;
    }

    // Add a friend to the user
    void add_friend(User &frnd)
    {
        friends.push_back(frnd);
    }

    // Remove a friend from the user
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

    // Return a pointer to a friend at a specific index
    User *return_Friend(int index)
    {
        return &friends[index];
    }

    // Add a post to the user's posts
    void add_post(Post &post)
    {
        posts.push_back(post);
    }

    // Return a pointer to a post with a specific ID
    Post *return_post(int key_id)
    {
        for (int i = 0; i < friends.size(); i++)
        {
            for (int j = 0; j < friends[i].posts.size(); j++)
            {
                if (friends[i].posts[j].return_id() == key_id)
                {
                    return &posts[j];
                }
            }
        }
    }

    // Remove a post from the user's posts
    void remove_post(Post &post)
    {
        for (int i = 0; i < posts.size(); i++)
        {
            if (posts[i] == post)
            {
                posts.erase(posts.begin() + i);
            }
        }
    }

    // Display user information
    void display_info()
    {
        cout << "Username: " << username << endl;
        cout << "Full Name: " << full_name << endl;
        cout << "Email: " << email << endl;
        cout << "Date of Birth: " << Date_of_Birth.day << "/" << Date_of_Birth.month << "/" << Date_of_Birth.year << endl;
    }

    // Display user timeline
    void display_user_timeline()
    {
        cout << "Friends: " << endl;
        if (friends.empty())
        {
            cout << "No friends available" << endl;
        }
        else
        {
            this->own_display_posts();
            this->users_friends_posts();
        }
    }

    // Display posts of friends
    void users_friends_posts()
    {
        cout << "Friends Posts: " << endl;
        for (int i = 0; i < friends.size(); i++)
        {
            cout << friends[i].return_full_name() << endl;
            friends[i].own_display_posts();
        }
    }

    // Display friends
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
                cout << friends[i].return_full_name() << endl;
            }
        }
    }

    // Display user's own posts
    void own_display_posts()
    {
        cout << "My Posts: " << endl;
        if (posts.empty())
        {
            cout << "No posts available" << endl;
        }
        else
        {
            for (int i = 0; i < posts.size(); i++)
            {
                posts[i].display_post();
            }
        }
    }

    // Function to receive or send a message
    void recieve_or_send_message(string key);
};

int Comment::next_cmnt_id = 1;

class Message
{
    static int next_id;
    User sender;
    User receiver;
    string message;
    int id;
    time_t timestamp;

public:
    // Constructor with automatic message ID incrementation and timestamp
    Message() : id(next_id++), timestamp(time(0)) {}

    // Parameterized constructor to set sender, receiver, message, message ID, and timestamp
    Message(User &sender, User &receiver, string message) : sender(sender), receiver(receiver), message(message), id(next_id++), timestamp(time(0)) {}

    // Getter functions
    User return_sender() { return sender; }
    User return_receiver() { return receiver; }
    string return_message() { return message; }
    int return_id() { return id; }
    time_t return_timestamp() { return timestamp; }

    // Set message using user input
    void set_message()
    {
        cout << "Enter Your message..." << endl;
        cin.ignore(); // Ignore newline character from previous input
        getline(cin, message);
    }

    // Set sender
    void set_sender(User &sender)
    {
        this->sender = sender;
    }

    // Set receiver
    void set_receiver(User &receiver)
    {
        this->receiver = receiver;
    }

    // Display message information
    void display_message()
    {
        cout << "Sender: " << sender.return_full_name() << endl;
        cout << "Receiver: " << receiver.return_full_name() << endl;
        cout << "Message: " << message << endl;
        cout << "ID: " << id << endl;
        cout << "Timestamp: " << timestamp << endl;
    }
};

void User::recieve_or_send_message(string key)
{
    Message m1;
    m1.set_message();
    for (int i = 0; i < friends.size(); i++)
    {
        if (key == friends[i].username)
        {
            friends[i].messages.push_back(m1);
            this->messages.push_back(m1);
            m1.set_receiver(friends[i]);
            m1.set_sender(*this);
            m1.display_message();
            cout << "Private Message sent!" << endl;
        }
    }
}

class Social_Media
{
    vector<User> users;
    int choice;
    string key;

public:
    // Function to sign in or sign up a user
    User &signing_in_or_up()
    {
        User *u1 = new User();
        cout << "Press 1 to sign in" << endl
             << "Press 2 to sign up" << endl;
        cin >> choice;
        if (choice == 1)
        {
            cin.ignore(); // Ignore newline character from previous input
            u1->set_username();
            u1->set_full_name();
            u1->set_email();
            u1->set_Date_of_Birth();
            users.push_back(*u1);
            return *u1;
        }
        else if (choice == 2)
        {
            cout << "Enter your username for signing in..." << endl;

            cin >> key;
            for (int i = 0; i < users.size(); i++)
            {
                if (key == users[i].return_username())
                {
                    *u1 = users[i];
                }
            }
            return *u1;
        }
    }

    // Main menu function
    void menu()
    {
        User u1 = Social_Media::signing_in_or_up();
        u1.display_user_timeline();
        while (1)
        {
            cout << "Press 1 to post a post" << endl
                 << "Press 2 to view your friends posts" << endl
                 << "Press 3 to view your friends" << endl
                 << "Press 4 to make a friend" << endl
                 << "Press 5 to view your timeline" << endl
                 << "Press 6 to view your own profile" << endl
                 << "Press 7 to message your friend" << endl
                 << "Press 8 for creating a new account" << endl
                 << "Press 9 to switch users" << endl;
            cin >> choice;
            if (choice == 1)
            {
                Post *p1 = new Post();
                cin.ignore();
                p1->set_title();
                p1->set_content();
                u1.add_post(*p1);
                p1->display_post();
            }
            else if (choice == 2)
            {
                u1.users_friends_posts();
                cout << "Enter the id of the post you want to like or comment." << endl;
                int key;
                cin >> key;
                Post *p = u1.return_post(key);
                cout << "Press 1 to like the post" << endl;
                cout << "Press 2 to comment on the post" << endl;
                cin >> choice;
                if (choice == 1)
                {
                    *p + 1;
                }
                else if (choice == 2)
                {
                    Comment c1;
                    c1.set_content();
                    c1.set_commentor(u1.return_full_name());
                    p->add_cmnt(c1);
                }
            }
            else if (choice == 3)
            {
                u1.display_frnds();
            }
            else if (choice == 4)
            {
                for (int i = 0; i < users.size(); i++)
                {
                    cout << "Name: " << users[i].return_full_name() << endl;
                    cout << "Username: " << users[i].return_username() << endl;
                    cout << "Email: " << users[i].return_email() << endl;
                }
                cout << "Enter the username of the user you want to add" << endl;

                cin >> key;
                for (int i = 0; i < users.size(); i++)
                {
                    if (key == users[i].return_username())
                    {
                        u1.add_friend(users[i]);
                        users[i].add_friend(u1);
                    }
                }
            }
            else if (choice == 5)
            {
                u1.display_user_timeline();
            }
            else if (choice == 6)
            {
                u1.display_info();
                u1.own_display_posts();
            }
            else if (choice == 7)
            {
                u1.display_frnds();
                cout<<"Enter the username of the friend you want to messgae ."<<endl;
                string key;
                cin >> key;
                u1.recieve_or_send_message(key);
                cin.ignore();
            }

            else if (choice == 8)
            {
                User u2 = signing_in_or_up();
            }
            else if (choice == 9)
            {
                for (int i = 0; i < users.size(); i++)
                {
                    cout << users[i].return_username() << endl;
                }
                cout << "Enter the username of the user you want to switch to" << endl;

                cin >> key;
                for (int i = 0; i < users.size(); i++)
                {
                    if (key == users[i].return_username())
                    {
                        u1 = users[i];
                    }
                }
                u1.display_user_timeline();
            }
        }
    }
};
int Message::next_id = 1;
int main()
{
    Social_Media s1;
    s1.menu();
    return 0;
}
