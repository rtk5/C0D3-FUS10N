# Challenge Name: **Magnus's Secrect**

---

#### Author: A Arshad Khan

#### Difficulty: Hard

#### Points: 100

#### Wave: 2

---

## Challenge Overview

Magnus Carlsen, the reigning chess grandmaster, has left a secret hidden in a chessboard position. Our task is to analyze the provided chessboard image, uncover the hidden clue, and extract the flag.

The challenge requires us to:

- Investigate the chessboard image for any clues.
- Use **chess notations** and **steganography** techniques to reveal a hidden flag.
- Follow a link to decode the chess game's PGN (Portable Game Notation) data to obtain the flag.

---

## Step-by-Step Solution

### Step 1: Extract Hidden Data

The first step is to extract any hidden data from the provided chessboard image `chess.jpg`. Steganography involves hiding data within files, and tools like **`steghide`** can help extract such data.

To extract hidden content, run:

```bash
steghide extract -sf chess.jpg
```

- **Note:** The password is blank, so press **Enter** when prompted.

If you’re new to steganography, here’s a great **[Introduction to Steganography](https://medium.com/@FourOctets/ctf-tidbits-part-1-steganography-ea76cc526b40)** that walks through the basic concepts.

Alternatively, if you're on a Windows machine or prefer an online approach, you can use **[Aperi'Solve](https://www.aperisolve.com/)**, an online steganography analysis tool. Upload the `chess.jpg` file and it will attempt to extract hidden data for you.

### Step 2: Review Extracted Data

After extraction, you should find a text file containing a URL. The URL links to a **YouTube video** that explains how data can be encoded and decoded in chess games using **PGN** (Portable Game Notation) files. The link to the video is [here](https://www.youtube.com/watch?feature=shared&v=TUtafoC4-7k), created by **wintrcat**.

To better understand **PGN files** and how they represent chess games, you can read through **[this guide to PGN format](https://www.chess.com/terms/pgn)** which explains how chess games are recorded in PGN format.

The video description also contains a link to a **GitHub repository** with a Python script that decodes the hidden message in PGN files. The repository can be found [here](https://github.com/WintrCat/chessencryption).

---

### Step 3: Decode the PGN

Now, we need to use the technique outlined in **wintrcat's** video to decode the chessboard position and extract the hidden flag from the **PGN** file.

1. **Download the Script**: Clone the GitHub repository using:

   ```bash
   git clone https://github.com/WintrCat/chessencryption
   ```

2. **Run the Python Script**: Navigate to the directory and run the script (which you need to write) to decode the hidden message in the PGN file:

   ```bash
   python run_decode.py
   ```

- you can get the run_decode.py [here](/WR!T3-U9's/Solution-Files/Magnus's-Secret/run_decode.py)

This will generate an output text file, likely named `flag.txt`, containing the flag.

For more practice on reverse engineering PGN files, you can explore similar challenges or guides on **[CTFtime](https://ctftime.org)**, a platform that lists numerous Capture The Flag (CTF) competitions with tasks involving cryptography, steganography, and more.

---

### Step 4: Retrieve the Flag

Open the `flag.txt` file to view the hidden flag. The final flag should be:

```text
Flag{Y0U_D1D_17}
```

---

## Conclusion

By analyzing the chessboard image and employing steganography tools along with PGN decoding techniques, we successfully uncovered the hidden flag. This challenge introduces a creative way of encoding data using chess notations, combining elements of chess, steganography, and reverse engineering.

For those looking to dive deeper into steganography or chess-based cryptography, you can explore more challenges on platforms like **[Hack The Box](https://www.hackthebox.com)** or **[picoCTF](https://picoctf.org)**, which frequently feature these types of puzzles.
