# Challenge Name: Mystic Vault

#### Author: Adithi H

#### Difficulty: Hard

#### Points: 100

#### Wave: 3

#### Number of Solves: 11

## Steps:
#### Step 1: Examine the given file
It turns out to be an ELF file (executable file).

After running the file - 
You have three attempts to guess a random number.
The program also gives whether the guess is too high or too low, narrow down the possible range of guesses. 

###### Alternate way - Use reverse engineering tools to directly examine the source code and get the number.
Put that in the program after running.  


#### Step 2: 
After you guessed correctly, you'll receive an ASCII sequence.

This ASCII sequence, when decoded using Base64, will reveal the flag

```
flag_raid{ul1imat3_tr3asur3_unl0ck3d}
```