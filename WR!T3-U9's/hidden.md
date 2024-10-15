# Challenge Name: hidden 

#### Author: Adithi H

#### Difficulty: Medium

#### Points: 50

#### Wave: 3

#### Number of Solves: 0


## Steps:

#### Step 1: Analyzing the Encoded Text File
We opened the .txt file and discovered a series of dots with unusual spacing. This suggests it's not Morse code but likely utilizes whitespace for encoding. Standard text characters wouldn't exhibit such deliberate spacing patterns.

#### Step 2: Decoding the Message
Since standard text editors wouldn't interpret the whitespace correctly, we used an online whitespace decoder: https://vii5ard.github.io/whitespace/

Running the contents of the .txt file through this decoder revealed the flag

```
flag_raid{hidden_in_plain_sight}
```