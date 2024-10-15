# Challenge Name: Finding Nemo

#### Author: Adithi H

#### Difficulty: Medium

#### Points: 50

#### Wave: 2

#### Number of Solves: 1

## Steps:
#### Step 1: Examine the given files
One of the file - Stegnography decoder says - nemo says SHARKS
Other has something hidden using steghide

#### Step 2: Use steghide to extract the hidden data from the second file
steghide passphase - SHARKS

#### Step 3: Extract the .txt file using steghide
Secret file has a message encoded in Blub! 

#### Step 4: Cipher Identify - Fish Cipher - Blub!
After decoding - Hooray! You successfully found me!
and the flag is 
```
flag_raid{y0u_f0und_n3m0}
```