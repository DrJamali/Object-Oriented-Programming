#include <iostream>
#include <cstring>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

const int max_friends = 100;
const int max_comments = 100;
const int max_users = 100;
class User
{
    string username;
    string fullname;
    string dob;
    string email;
    User *friends;
    int friendCount;

public:
    User() : username(""), fullname(""), dob(""), email(""){};
    User(string usern, string fulln, string birth, string mail) : username(usern), fullname(fulln), dob(birth), email(mail){};

    string getUsername() const
    {
        return username;
    }

    // overload == operator to facilitate username-based comparisons
    bool operator==(User &user)
    {
        if (username == user.username)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // constructor to initialize friends array
    User(int max_friends) : friendCount(0)
    {
        friends = new User[max_friends];
    }

    ~User()
    {
        delete[] friends;
    }

    // function to input user details
    void input()
    {
        cout << "Enter Username: ";
        getline(cin, username);
        cout << "Enter name: ";
        getline(cin, fullname);
        cout << "Enter email: ";
        getline(cin, email);
        cout << "Enter date of birth: ";
        getline(cin, dob);
    }

    void addFriends(User &userFriends)
    {
        if (friendCount < max_friends)
        {
            friends[friendCount++] = userFriends;
        }
        else
        {
            cout << "Cannot add more friends. Limit reached!" << endl;
        }
    }

    void displayFriends()
    {
        for (int i = 0; i < friendCount; i++)
        {
            cout << friends[i].fullname << endl;
        }
    }
};

class Comments
{
    // represents comments on a post
private:
    static int commentID;
    int ID;
    string commenter;
    string content;
    time_t timestamp;

public:
    Comments() : commenter(""), content("")
    {
        ID = ++commentID;
        timestamp = time(0);
    };
    Comments(int ID, string c, string c2) : commenter(c), content(c2), timestamp(time(0)){};

    // functions to represent comments
    void getComment()
    {
        cin.ignore();

        cout << "Enter your comment: " << endl;
        getline(cin, content);

        cout << "Enter your name: " << endl;
        getline(cin, commenter);
    }

    void displayComment()
    {
        cout << ID << ": " << content << endl;
        cout << "Commenter: " << commenter << endl;
        cout << "Time: " << timestamp << endl;
    }
};
int Comments::commentID = 0;

class Post
{
    // designed to represent user's posts on social media platform
private:
    string content;
    time_t timeStamp;
    double likes;
    vector<Comments> comment;

public:
    Post() : content(""), likes(0)
    {
        timeStamp = time(0);
    };
    Post(string contentP, int like) : content(contentP), likes(like), timeStamp(time(0)){};

    // overload + operator to allow users to like the post
    Post operator+(User &user)
    {
        likes++;
        return *this;
    };

    void getpost()
    {
        cout << "Enter your content: " << endl;
        getline(cin, content);
    }

    void displayPost()
    {
        cout << "Content: " << content << endl;
        cout << "Time: " << timeStamp << endl;
        cout << "Likes: " << likes << endl;
        cout << "Comments: " << endl;
        for (auto &userComments : comment)
        {
            userComments.displayComment();
        }
    }

    void addComment(const Comments &newComment)
    {
        comment.push_back(newComment);
    }
};

class SocialNetwork
{
    /*Create a SocialNetwork class to manage the overall social media platform.
      Implement methods to add new users, establish friendships, create posts, and add comments to posts.
      */
private:
  static  vector<User> user;
    vector<Post> post;
    int usercount;
    int choice;

public:
    // method to add users to the vector
    void addUserToVector( User* newUser)
    {
        user.push_back(*newUser);
    }

    // method to input user details
    void inputUserDetails(User &newUser)
    {
        newUser.input();
    }

    vector<User> &getUsers()
    {
        return user;
    }

    vector<Post> &getposts()
    {
        return post;
    }

    // function to establish friendships
    void addfriend(User &user1, User &user2)
    {
        user1.addFriends(user2);
        user2.addFriends(user1);
    }

    // function to create posts
    void createPosts(User &user, Post &posts)
    {
        posts.getpost();
        post.push_back(posts);
    }

    void displaypost(Post &uposts)
    {
        uposts.displayPost();
    }

    void addComments(User &user, Post &post, Comments &comments)
    {
        post.addComment(comments);
    }

    void userTimeline()
    {
        cout << "POSTS: " << endl;
        for (auto &userposts : post)
        {
            userposts.displayPost();
        }
    }

    void displayfriends()
    {
        cout << "Friends: " << endl;
        for (auto &userFriends : user)
        {
            userFriends.displayFriends();
        }
    }
    // Method to find a user by username
    User *findUser(const string &username)
    {
        for (auto &users : user)
        {
            if (users.getUsername() == username)
            {
                return &users;
            }
        }
        return nullptr; // User not found
    }
};

int main()
{
    SocialNetwork S1;
    User* users=new User();
    Post posts;
    Comments comments;
    int input;
    S1.inputUserDetails(*users);
    S1.addUserToVector(users);
    while (1)
    {
        cout << "Choose from following: " << endl;
        cout << "1. Add posts" << endl
             << "2. Add comments to posts" << endl
             << "3. Like any post " << endl
             << "4. Make friends" << endl
             << "5. View friends" << endl
             << "6. View Timeline " << endl
             << "7. Change user " << endl
             << "8. Exit " << endl
             << "Your choice(1-7): ";
        cin >> input;
        cin.ignore();
        // add posts
        if (input == 1)
        {
            S1.createPosts(*users, posts);
            continue;
        }
        // add comments to posts
        else if (input == 2)
        {
            cout << "All posts: " << endl;
            for (int i = 0; i < S1.getposts().size(); i++)
            {
                cout << "----------------------" << endl;
                cout << "Post number: " << i + 1 << endl;
                S1.displaypost(S1.getposts()[i]);
                cout << "----------------------" << endl;
            }

            int postIndex;
            cout << "Choose a post to add a comment (by post number): ";
            cin >> postIndex;
            int index = postIndex - 1;

            if (index >= 0 && index < S1.getposts().size())
            {
                // Create a new Comments object for each comment
                Comments newComment;
                newComment.getComment();

                // Add the new comment to the post
                S1.addComments(*users, S1.getposts()[index], newComment);
                cout << "Comment added to post " << index + 1 << endl;
            }
            else
            {
                cout << "Invalid post index." << endl;
            }

            continue;
        }
        // like any post
        else if (input == 3)
        {
            cout << "All posts: " << endl;
            for (int i = 0; i < S1.getposts().size(); i++)
            {
                cout << "----------------------" << endl;
                cout << "Post number: " << i + 1 << endl;
                S1.displaypost(S1.getposts()[i]);
                cout << "----------------------" << endl;
            }
            int postIndex;
            cout << "Choose a post to like: ";
            cin >> postIndex;

            if (postIndex >= 0 && postIndex < S1.getposts().size())
            {
                S1.getposts()[postIndex] = S1.getposts()[postIndex] + *users;
                cout << "Post liked!" << endl;
            }
            else
            {
                cout << "Invalid post index." << endl;
            }

            continue;
        }
        // make friends
        else if (input == 4)
        {
            // Display a list of existing users
            cout << "Existing users: " << endl;
            for (const User &existingUser : S1.getUsers())
            {
                cout << existingUser.getUsername() << endl;
            }

            // Ask the user to choose two users to become friends
            cout << "Choose two users to become friends: " << endl;
            string username1, username2;
            cin >> username1 >> username2;

            // Find the User objects corresponding to the chosen usernames
            User *user1 = S1.findUser(username1);
            User *user2 = S1.findUser(username2);

            // Check if the User objects were found
            if (user1 && user2)
            {
                // Establish friendship
                S1.addfriend(*user1, *user2);
                continue;
            }
            else
            {
                cout << "Error: One or both users not found." << endl;
                continue;
            }
        }
        // view friends
        else if (input == 5)
        {
            for (int i = 0; i < S1.getposts().size(); i++)
            {
                cout << "----------------------" << endl;
                cout << "Post number: " << i + 1 << endl;
                S1.displayfriends();
                cout << "----------------------" << endl;
            }
        }
        // view timeline
        else if (input == 6)
        {
            S1.userTimeline();
            continue;
        }
        // switch user
        else if (input == 7)
        {
            // Create a new user
            users=new User();

            // Input user details
            S1.inputUserDetails(*users);
            cout<<"Still running..."<<endl;
            // Add the user to the vector
            S1.addUserToVector(users);
            cout<<"Still running... 2"<<endl;

            // Use getline to consume the newline character left in the input buffer
            // cin.ignore();

            // Update the original user with the new user details
            

            continue;
        }
        else if (input == 8)
        {
            break;
        }
        else
        {
            cout << "Choose a valid option!" << endl;
            continue;
        }
    }
}