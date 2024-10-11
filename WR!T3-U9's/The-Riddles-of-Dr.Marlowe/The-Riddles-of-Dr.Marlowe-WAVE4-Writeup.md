# Challenge Name: **The Riddles of Dr. Marlowe**

---

#### Author: A Arshad Khan

#### Difficulty: Hard +999

#### Points: 200

#### Wave: 4

#### Number of Solves: 0

---

## Challenge Overview

Dr. Evelyn Marlowe left behind a PDF file that seems ordinary at first glance. However, as she is known for embedding secrets in unexpected ways, our task is to extract the hidden message from the file. By using online tools and software, we can uncover the hidden image and retrieve the secret message.

---

## Tools Required

- [HexEd.it](https://hexed.it/): A web-based hex editor for analyzing and extracting hex data from files.
- [StegOnline](https://georgeom.net/StegOnline/image): An online tool to analyze images for hidden data.
- **zsteg**: A Ruby gem used to extract data hidden in images. You can learn more about it [here](https://github.com/zed-0xff/zsteg).

---

## Step-by-Step Solution

### Step 1: Analyze the PDF Using HexEdit

1. Go to [hexed.it](https://hexed.it/), a web-based hex editor.

2. Upload the provided PDF file (`FinancialReport.pdf`).

3. Once the file is open, search for the hexadecimal header signature of a PNG file, which is:

   ```text
   89 50 4E 47
   ```

4. Scroll down through the file until you locate the end of the PNG file. The hexadecimal footer for a PNG file is:

   ```text
   AE 42 60 82
   ```

5. Select the portion of the file between these two hexadecimal signatures (from the header to the footer). This section is the embedded PNG image.

6. Right-click and choose the option to **Export selection** as a new file, and save it as `Flag.png`.

you can download the Flag.png [here](./Flag.png)

### Step 2: Analyze the PNG for Hidden Data

Now that you have extracted the PNG file (`Flag.png`), follow the appropriate method based on your operating system.

#### **Linux Method**

1. Use the `zsteg` tool to analyze the image for hidden data. If you don't have `zsteg` installed, you can install it via:

   ```bash
   sudo gem install zsteg
   ```

2. Run the command to analyze the image:

   ```bash
   zsteg --all Flag.png
   ```

3. The tool will detect the hidden data embedded in the least significant bits (LSB). Look for the output that reveals the flag.

#### **Windows Method**

1. Open [StegOnline](https://georgeom.net/StegOnline/image).
2. Upload the `Flag.png` file.
3. Use the **LSB extraction** feature, and select the red channel since the flag is hidden in the least significant bits of the red values.
4. After processing, the tool will reveal the hidden message in the image.

For a more comprehensive understanding of steganography techniques, you can check out **[Steganography: A Comprehensive Guide](https://medium.com/@FourOctets/ctf-tidbits-part-1-steganography-ea76cc526b40)**.

### Step 3: Retrieve the Flag

Once the analysis is complete, either via `zsteg` or StegOnline, you will retrieve the hidden flag:

```text
FLAG-RAID{EV31YN_M4R10W35_53CR3T_M3S54G3}
```

---

## Conclusion

Using the online tools **HexEdit** to extract the embedded image and **StegOnline** or **zsteg** to analyze it, we successfully uncovered Dr. Evelyn Marlowe's secret message.

For those interested in further exploring the world of digital forensics and data extraction techniques, consider looking into **[Digital Forensics: A Comprehensive Overview](https://www.ibm.com/topics/digital-forensics)**.
