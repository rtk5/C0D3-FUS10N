# Challenge Name: 
#### Author: K R DUVA

#### Difficulty: Hard +999

#### Points: 200

#### Wave: 4

#### Number of Solves: 0

### Scenario :
Voldemort has finally obtained Harry Potter's password files! However, his triumph was short-lived when he discovered only the hash remained. After interrogating Dobby, he learned that Harry's password exists within the infamous *ROCKYOU.txt* wordlist.

### Challenge
Help Voldemort crack Harry's password hash to access his secrets!

### Details
- The password hash was found in Harry's files
- Confirmed: password is in the ROCKYOU.txt wordlist
- Requires hash cracking techniques

### Objective
Crack the hash to retrieve Harry's original password.

### Flag Format
```
FLAG-RAID{HARRY'SPASSWORD}
```
## STEPS:

In this task, you are provided with two files: `shadow.txt` and `password.txt`. Your objective is to crack the hashed passwords by first combining the information from both files, and then using **John the Ripper** to brute-force the passwords using a customized wordlist.

#### Step 1: Unshadow the Passwords

The `shadow.txt` file contains the hashed passwords, while the `password.txt` file contains the user information. To crack the passwords, you first need to combine these two files into a format that **John the Ripper** can understand. This is called "unshadowing" the password.[cyberciti.biz/faq/understanding-etcshadow-file/]

Use the following command to unshadow the files:

```bash
unshadow password.txt shadow.txt > unshadowed.txt
```
#### Step 2: Create a Custom Wordlist

Instead of using a large wordlist, we will create a smaller, custom wordlist from the last 100 words of the popular `rockyou.txt` wordlist. This will reduce the cracking time and make the task more manageable, like focusing on quality over quantity. As Bruce Lee once said, “I fear not the man who has practiced 10,000 kicks once, but I fear the man who has practiced one kick 10,000 times.” We’ll be honing in on a smaller, more effective list.

Use the following command to create your custom wordlist:

```bash
tail -n 100 rockyou.txt > small_wordlist.txt
```
#### Step 3: Run John the Ripper

Now, with the `unshadowed.txt` file and the custom `small_wordlist.txt`, you can use **John the Ripper** to attempt cracking the passwords.

Run the following command:

```bash
john --wordlist=small_wordlist.txt unshadowed.txt
```
#### Step 4: Review the Results

After John the Ripper finishes running, you can review the cracked passwords. In our case, if the process was successful, one of the cracked passwords will be displayed as `abygurl69`.

To view the results, run the following command:

```bash
john --show unshadowed.txt
```
## FLAG :- FLAG-RAID{abygurl69}

### Tools Suggested
- Hash identification tools[eg: Haiti]
- Hashcat or John the Ripper
- ROCKYOU.txt wordlist



---
*"Happiness can be found even in the darkest of times when one remembers to turn on the hash cracker." - Modified Dumbledore*