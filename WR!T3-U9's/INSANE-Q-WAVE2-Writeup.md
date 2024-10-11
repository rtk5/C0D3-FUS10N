# Challenge Name: 
#### Author:K R DRUVA

#### Difficulty: Medium

#### Points: 50

#### Wave: 2


#### Challenge Description: OBJECTIVE: Search through a directory structure of 8,401 entries to identify and decrypt an anomalous ciphertext file. Successful decryption yields the required flag.


#### Files Attached: -> Insane-Question.7z



## Steps:
##### Step 1: Initial Misdirection
The first file contains this hexadecimal string:
```
52 6b 78 42 52 79 31 53 51 55 6c 45 65 30 5a 68 53 32 55 74 52 6d 78 68 5a 79 31 30 61 47 6c 7a 4c 57 46 70 62 6e 51 74 63 6d 6c 6e 61 48 52 39
```

Using a decoder tool like CyberChef's Magic function (`gchq.github.io/CyberChef/#recipe=Magic(3,false,false,'')`), this decrypts to:
```
FLAG-RAID{FaKe-Flag-this-aint-right}
```

##### Step 2: Finding the Real Flag
- Participants must identify the file containing unique data among the 8,401 files
- This can be done using recursive grep or any programming language
- Upon finding the correct file and applying the same decryption strategy, the authentic flag is revealed:
```
FLAG-RAID{C0NGR4L4T!0NS-F1nAlly}
```

#### Required Tools
- File system navigation tools
- Hex decoder
- Text searching utilities

---
**Note:** Good luck, hackers!:))
