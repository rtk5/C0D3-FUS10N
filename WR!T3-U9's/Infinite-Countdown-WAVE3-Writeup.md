# Challenge Name: **Infinite Countdown**

---

#### Author: A Arshad Khan

#### Difficulty: Medium

#### Points: 50

#### Wave: 3

---

## Challenge Overview

The **Infinite Countdown** challenge involves an executable file that asks a series of questions and provides parts of the flag for each correct answer. The waiting time between each question increases exponentially, but it is manageable, with the total time adding up to around 5 minutes. The challenge can be solved either by answering the questions manually or by using reverse engineering techniques to extract the flag more efficiently.

---

## Tools Required

- **`strings`**: A command-line tool to extract readable strings from executables.  
  - If you're unfamiliar with the `strings` command, you can learn how to use it from **[this guide](https://ioflood.com/blog/strings-linux-command/#:~:text=The%20'strings'%20command%20in%20Linux%20is%20used%20to%20extract%20readable,bin%20.&text=In%20this%20example%2C%20we've,a%20binary%20file%20named%20'myfile.)**.
  
- **Reverse Engineering Tools** (Optional, for advanced users):
  - **Ghidra**: A free software reverse engineering tool.
    - Learn how to set up and use Ghidra from **[this official documentation](https://ghidra-sre.org/)**.
  - **IDA Free**: A disassembler and debugger for analyzing executable files.
    - You can download **[IDA Free](https://hex-rays.com/ida-free/)** and find a useful **[IDA Pro reverse engineering tutorial](https://www.youtube.com/watch?v=N_3AGB9Vf9E)** for beginners.
  - **x64dbg**: A debugger for Windows applications.
    - For a more practical approach, check out **[this tutorial on using x64dbg](https://www.varonis.com/blog/how-to-use-x64dbg)** to analyze executables.

---

## Step-by-Step Solution

### Beginner-Friendly Approach: Answer the Questions

1. **Run the Program**: Execute the `infinite_countdown.exe` program directly on your system.

2. **Answer the Questions**: As the program runs, it will ask you a series of questions. Answer each question correctly to reveal a part of the flag. The program reveals the flag in 6 parts, with the waiting time increasing between each question.

3. **Endure the Waiting Time**: The waiting time between each question increases, but the total time to complete the program is around 5 minutes. You can wait patiently to answer all the questions.

4. **Retrieve the Flag**: After answering all the questions correctly, the program will reveal the complete flag.

### Step 2: Analyze the Executable with `strings`

For users looking for a quicker solution, you can use the `strings` command to extract readable parts of the executable, which may contain hints, answers, or parts of the flag:

1. Run the following command on the executable:

   ```bash
   strings infinite_countdown
   ```

2. **Search for Readable Output**: Look through the output for any readable strings, flag parts, or answers to the questions. Often, strings stored in an executable file can reveal important information such as hidden messages or parts of the flag.

   - If you need help filtering through the output efficiently, check out this **[tutorial on using regular expressions with `grep`](https://linuxize.com/post/regular-expressions-in-grep/)** to speed up your analysis.

### Step 3: Use Reverse Engineering Tools (Optional)

For advanced users, reverse engineering the executable can help you bypass the waiting times and directly extract the flag.

#### Ghidra Method

1. **Open Ghidra** and import the `infinite_countdown` executable.  
   - If you're new to Ghidra, **[this tutorial on Ghidra basics](https://www.varonis.com/blog/how-to-use-ghidra)** can help you navigate through decompiling and analyzing executable files.

2. **Analyze the Code**:
   - Look for the main game logic, specifically functions handling questions, delays (e.g., `sleep` or `wait` functions), and flag construction.
   - Reverse engineering techniques allow you to skip or manipulate these delays to access the flag faster.

3. **Extract the Flag**: Once you locate the relevant functions, you can directly extract the flag from the decompiled code without waiting through the delays.

---

### Conclusion

The **Infinite Countdown** challenge can be solved either by manually answering the questions and waiting through the delays (which add up to around 5 minutes) or by using tools like `strings`, Ghidra, or IDA to extract the flag directly. Beginners can comfortably solve this challenge by simply interacting with the program, while more advanced users can opt for reverse engineering to bypass the waiting mechanism.

you can download the infinite_countdown.c file that was used to create the executable [here](\WR!T3-U9's\Solution-Files\Infinite-Countdown\infinite_countdown.c)

The final flag will be in the format:

```text
FLAG-RAID{EV31YN_M4R10W35_53CR3T_M3S54G3}
```

For more reverse engineering practice, check out CTF challenges on platforms like **[picoCTF](https://play.picoctf.org/)** or **[CTFtime](https://ctftime.org/)**, which offer similar tasks and puzzles for all skill levels.
