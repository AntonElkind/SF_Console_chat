# Console chat
#### Skill Factory Console chat final project
##### Project state after module 16
+ The custom container has been replaced with a <vector> for mailboxes
+ The custom container has been replaced with an <unordered_map> for chat members
+ Implemented SHA-1 encryption for user passwords

##### Project state after module 9
This project provides basic chat functionality. There are main menu for guest users and one sub-menu for
successfully registered users:

+ User registration with email, name and password;
+ Log in by email and password. After log in it is possible:
  + Print the last received message;
  + Print all inbox;
  + Write message to any registered user by name;
  + Write message to all registered users;
+ Log out;

The application assumes that only one user can be logged in at a time.

#### Getting started
Clone master branch and open project by Microsoft Visual Studio.

##### Author
Anton Elkind