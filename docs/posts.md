#! Posts

Posts are how tachyons communicate with each other in this multithreaded environment.

The following are the general categories of posts.
+ **Commands** are orders, must be done unless it's impossible (ie, load a non-existent file)
+ **Events** are things that happened (ie inputs, tachyons modified, etc)
+ **Messages** are general messages
+ **Replies** are acknowledgements to requests
+ **Requests** can be conditional commands, can be refused for other grounds (ie, close() but there's unsaved data, inquiry to the user that gets canceled).  OR, they can be requests for information (see replies)

## Mail Groups

These are used by the sender to group recipients; for instance, the Children group is for posts meant for the tachyon's children.

