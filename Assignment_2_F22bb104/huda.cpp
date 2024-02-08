#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

using namespace std;

class Comment {
public:
    int id;
    string user;
    string content;
    string timestamp;

    Comment(int commentId, const string& username, const string& text)
        : id(commentId), user(username), content(text) {
        time_t now = time(nullptr);
        timestamp = ctime(&now);
    }
};

class Post {
public:
    int id;
    string content;
    string timestamp;
    int likes;
    vector<Comment> comments;

    Post(int postId, const string& text)
        : id(postId), content(text), likes(0) {
        time_t now = time(nullptr);
        timestamp = ctime(&now);
    }

    void like(const string& username) {
        likes++;
        cout << "User " << username << " liked the post!\n";
    }
};

class User {
public:
    string username;
    string name;
    string dob;
    string email;
    vector<string> friends;
    vector<Post> posts;

    User(const string& uname, const string& fullName, const string& birthDate, const string& emailAddress)
        : username(uname), name(fullName), dob(birthDate), email(emailAddress) {}

    bool isEqual(const User& other) const {
        return username == other.username;
    }

    void sendMessage(const string& friendUsername, const string& message) {
        auto it = find(friends.begin(), friends.end(), friendUsername);
        if (it != friends.end()) {
            cout << "Message sent to " << friendUsername << ": " << message << "\n";
        } else {
            cout << "You can only send private messages to friends.\n";
        }
    }
};

class SocialNetwork {
private:
    vector<User> users;

public:
    void addUser(const User& user) {
        users.push_back(user);
    }

    void addFriendship(const string& user1, const string& user2) {
        auto it1 = find_if(users.begin(), users.end(),
            [&user1](const User& u) { return u.username == user1; });
        auto it2 = find_if(users.begin(), users.end(),
            [&user2](const User& u) { return u.username == user2; });

        if (it1 != users.end() && it2 != users.end()) {
            it1->friends.push_back(user2);
            it2->friends.push_back(user1);
            
        }
    }

    void createPost(const string& username, const string& content) {
        auto it = find_if(users.begin(), users.end(),
            [&username](const User& u) { return u.username == username; });

        if (it != users.end()) {
            Post post(it->posts.size() + 1, content);
            it->posts.push_back(post);
        }
    }

    void addComment(const string& username, int postId, const Comment& comment) {
        auto it = find_if(users.begin(), users.end(),
            [&username](const User& u) { return u.username == username; });

        if (it != users.end() && postId >= 1 && postId <= it->posts.size()) {
            it->posts[postId - 1].comments.push_back(comment);
        }
    }

    void displayTimeline(const string& username) {
        auto it = find_if(users.begin(), users.end(),
            [&username](const User& u) { return u.username == username; });

        if (it != users.end()) {
            vector<Post> timelinePosts = it->posts;

            for (const string& friendUsername : it->friends) {
                auto friendIt = find_if(users.begin(), users.end(),
                    [&friendUsername](const User& u) { return u.username == friendUsername; });

                if (friendIt != users.end()) {
                    timelinePosts.insert(timelinePosts.end(), friendIt->posts.begin(), friendIt->posts.end());
                }
            }

            sort(timelinePosts.begin(), timelinePosts.end(),
                [](const Post& a, const Post& b) { return a.timestamp < b.timestamp; });

            cout << "Timeline for " << username << ":\n";
            for (const Post& post : timelinePosts) {
                cout << "Post ID: " << post.id << "\n";
                cout << "Content: " << post.content << "\n";
                cout << "Timestamp: " << post.timestamp;
                cout << "Likes: " << post.likes << "\n";
                cout << "Comments:\n";
                for (const Comment& comment : post.comments) {
                    cout << " - " << comment.user << ": " << comment.content << " (" << comment.timestamp << ")\n";
                }
                cout << "\n";
            }
        } else {
            cout << "User not found.\n";
        }
    }
};

int main() {
    SocialNetwork socialNetwork;

    // Sample usage
    User huda("huda", "Huda", "01/01/1990", "huda@example.com");
    User ali("ali", "Ali", "02/02/1995", "ali@example.com");
    User shahzaib("shahzaib", "Shahzaib", "03/03/2000", "shahzaib@example.com");

    socialNetwork.addUser(huda);
    socialNetwork.addUser(ali);
    socialNetwork.addUser(shahzaib);

    socialNetwork.addFriendship("huda", "ali");
    socialNetwork.addFriendship("ali", "shahzaib");

    socialNetwork.createPost("huda", "i am in chitral!");
    socialNetwork.createPost("ali", "This is a book.");

    Comment comment1(1, "ali", "Nice post!");
    Comment comment2(2, "shahzaib", "MASALLAH!");

    socialNetwork.addComment("huda", 1, comment1);
    socialNetwork.addComment("huda", 1, comment2);

    socialNetwork.displayTimeline("huda");

    huda.sendMessage("ali", "Hi, friend!");

    return 0;
}