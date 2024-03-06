# Password-Generator
Simple quite random password generator and viewer for POSIX systems

## Installing
1. Clone repository to your machine

`git clone https://github.com/lordcoudy/Password-Generator.git generator`

2. Go to cloned directory: 

`cd generator`

3. Change path to wanted passwords file in generator.cpp:

`#define path "path/to/your/passwords.extension"`

4. Compile generator: 

`g++ -o generate ./generator.cpp`

5. Link executable so it can be found in PATH: 

`ln -s "Path/To/generate" /usr/local/bin`

## Running
Simply run command: `generate`

### Options
- 1: Get Password
- 2: Add Password
- 3: Change Length of Passwords (default = 15)
- 4: Get List of All Passwords
- 5: Clear Screen
- 0: Exit
