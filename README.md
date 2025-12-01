# Sphare Mail

> A lightweight, modular SMTP server developed by **Sphare Co.**
> 
![Version](https://img.shields.io/badge/version-0.1-green)

**v0.1 :** Basic TCP Connection & Project Structure Setup

 It's a mail service just like `gmail`, `hotmail` or `zohomail` etc.



## HOW TO BUILD :
`Ensure you have MinGW/G++ installed.`


**Step-1:**
```sh
g++ src/main.cpp src/Server.cpp -o bin/server_test.exe -lws2_32
```

**Step-2:**
```sh
./bin/server_test.exe
```




### Open another terminal in VSCode or ouside the VSCode 

Run this command in the 2nd terminal:

```sh
telnet localhost 2525
```

### Ouput 
Second terminal : 
```text
220 SphareMail v0.1 Service Ready
220 SphareMail v0.1 Service Ready


Connection to host lost.
```

First Terminal : 

```text
[INFO] A client connected!
[INFO] Greeting sent. Closing connection.
[LOG] Server Instance close successfully
[INFO] A client connected!
[INFO] Greeting sent. Closing connection.
[LOG] Server Instance close successfully
```
