# Challenge Name: Segfault

#### Author: Rithvik Rajesh Matta

#### Difficulty: Easy

#### Points: 20

#### Wave: 3

#### Challenge Description:  
The goal of this challenge is to create a segmentation fault in the provided executable file (`a.out`). A segmentation fault, commonly referred to as "segfault," occurs when a program tries to access memory that it isn’t permitted to use. When successfully caused, the segmentation fault will reveal the flag.

#### Hints:  
- Think of ways to access restricted memory or overflow buffers.
- Using a string longer than expected might trigger the segmentation fault.

#### Files Attached: 
- `a.out` (Linux executable)

## Steps:

1. Download and save the provided `a.out` file.
2. Open a terminal and navigate to the directory where `a.out` is saved.
3. Give execute permissions to the file if needed by running:
   ```bash
   chmod +x a.out
4. Run the executable in the terminal with:
    '''bash
    ./a.out
5. Enter an input string larger than the buffer (e.g., a very long string) to cause a segmentation fault.
6. Once the segmentation fault is triggered, the program should reveal the flag.

#### Flag Format:
The flag will be displayed FLAG-RAID{l00ks_like_wr1ting_segf4ult-y_c0de}.

#### Additional Notes: 
- The segmentation fault occurs due to an overflow in the copy function, where the buffer size is not adequately protected.
- Linux users may need to compile the source code if they want to experiment with it; however, the provided `a.out` should suffice for this challenge.