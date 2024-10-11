# Challenge Name: **Flappy CTF**

---

#### Author: A Arshad Khan

#### Difficulty: Medium

#### Points: 50

#### Wave: 3

---

## Challenge Overview

In the **Flappy CTF** challenge, players must guide Flappy, a bird navigating through pillars in a terminal-based game. For every pillar successfully crossed, a character of the flag is revealed. The challenge is simple: play the game, cross the pillars, and collect the flag. Alternatively, for those familiar with reverse engineering, the flag can also be extracted without playing the game.

---

## Tools Required (Optional)

- **Reverse Engineering Tools** (Optional, for advanced users):
  - **Ghidra**: A free software reverse engineering tool.
    - Learn more about **[Ghidra](https://ghidra-sre.org/)** and how to use it.
  - **IDA Free**: A disassembler and debugger for analyzing executable files.
    - You can download **[IDA Free](https://hex-rays.com/ida-free/)** for reverse engineering tasks.
  - **x64dbg**: A debugger for Windows applications.
    - **[x64dbg](https://x64dbg.com/)** is a great open-source tool for debugging Windows executables.

If you're new to reverse engineering, here's a **[Beginner's Guide to Reverse Engineering](https://ctf101.org/reverse-engineering/overview/)** that walks you through basic concepts and tools.

---

## Step-by-Step Solution

### Beginner-Friendly Approach: Play the Game

1. **Run the Flappy CTF Game**: Execute the `flappy_ctf.exe` game in your terminal.

   ```bash
   ./flappy_ctf.exe
   ```

2. **Play the Game**: Use the spacebar to make Flappy flap and navigate through the pillars. The goal is to successfully cross as many pillars as possible.

3. **Reveal the Flag**: For each pillar crossed, the game reveals a character of the flag. Continue playing until you collect all the characters needed to complete the flag.

4. **Format the Flag**: Once you've collected all the characters from the game, format the flag as:

   ```text
   FLAG-RAID{<your_collected_characters>}
   ```

If you're curious about how similar games are coded and how they handle flags, take a look at **[Hack The Box CTFs](https://www.hackthebox.com/hacker/ctf)** to see more game-style CTF challenges.

---

### Advanced Method: Use Reverse Engineering Tools (Optional)

If you're familiar with reverse engineering, you can analyze the executable file to find where the flag is stored in the game's code.

#### Ghidra Method

1. **Open Ghidra** and import the `flappy_ctf.exe` executable.
   - For those new to Ghidra, this **[Ghidra guide](https://www.varonis.com/blog/how-to-use-ghidra)** is an excellent resource for learning to use this tool effectively.

2. **Decompile the game code** and locate functions related to:
   - The game logic (pillar navigation).
   - The flag construction.

3. **Extract the flag** from the code without needing to play the game.

   If you want to learn more about the process of finding hidden flags in executable files, check out this **[Reverse Engineering CTF Challenges Guide](https://infosecwriteups.com/reverse-engineering-ctf-newbies-part-1-cbd0aa47a90d)**, which gives insights into extracting flags via reverse engineering.

---

### Conclusion

For beginners, the most straightforward way to solve this challenge is by playing the **Flappy CTF** game and collecting all characters of the flag. The game is designed to be fun and easy to play, with the total flag revealed as you successfully navigate through the pillars. For those with reverse engineering skills, the flag can also be extracted using tools like **Ghidra**, **IDA Free**, or **x64dbg**.

you can download the flappy_ctf.c file that was used to create the executable [here](/WR!T3-U9's/Solution-Files/Flappy-CTF/flappy_ctf.c)

The final flag will be:

```text
FLAG-RAID{Fl4ppy_B1rd_M4st3r!}
```

If you're interested in learning more about reverse engineering and Capture The Flag challenges, check out **[CTFtime.org](https://ctftime.org/)** and **[PicoCTF](https://play.picoctf.org/)** to find similar challenges and competitions.
