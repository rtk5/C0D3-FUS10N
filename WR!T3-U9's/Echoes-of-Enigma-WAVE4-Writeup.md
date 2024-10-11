# Challenge Name: **Echoes of Enigma**

---

#### Author: A Arshad Khan

#### Difficulty: Hard +999

#### Points: 200

#### Wave: 4

#### Number of Solves: 14

---

## Challenge Overview

In this challenge, Enigma, a legendary cryptographer, has hidden a secret within an audio file. The task is to analyze the provided file, manipulate it using audio software, and decode the hidden message that will ultimately reveal the flag. The challenge requires a careful approach, utilizing audio editing tools and Morse code decoding techniques.

---

## Step-by-Step Solution

### Step 1: Download the File

Start by downloading the provided file. Make sure to save it in a location where you can easily access it.

If you're new to audio analysis and want to understand more about how cryptography works with audio files, check out this detailed guide on **[steganography](https://medium.com/@FourOctets/ctf-tidbits-part-1-steganography-ea76cc526b40)**.

### Step 2: Modify the File Header

To ensure the audio file is recognized correctly, we need to add the proper MP3 header using a hex editor.

1. **Hex Editor**: You can use [HexED.it](https://hexed.it/) for this task.
2. **Open the Audio File**: Load the downloaded audio file in the hex editor.
3. **Add the MP3 Header**:
   - Navigate to the start of the file and insert the MP3 header. The standard MP3 header is as follows:

     ```text
     FF FB 90 44 00 00 00 00
     ```

   - Make sure to save the changes after adding the header.

*Resource*: If you're unfamiliar with how to use a hex editor, this **[Walkthrough](https://marcellelee.medium.com/ctf-challenge-walkthrough-modified-header-2a4a33976b6d)** is a good place to start.

you can download the mp3 file [here](/WR!T3-U9's/Solution-Files/Echoes-of-Enigma/hearme.mp3)

### Step 3: Open the File in Audacity

1. **Download Audacity**: you can use the online version [here](https://wavacity.com/) or download [Audacity](https://www.audacityteam.org/) and install it.
2. **Import the Modified Audio File**: Open Audacity and import the modified audio file.
3. **Split the Stereo Track**: If the audio file is in stereo format, you need to split it:
   - Click on the track name (where it says "Audio Track") to open the dropdown menu.
   - Select `Split Stereo to Mono`.

For a detailed guide on how to work with audio tracks in Audacity, refer to **[this Audacity tutorial](https://manual.audacityteam.org/)**. It covers essential tools, including splitting and manipulating stereo tracks.

### Step 4: Delete the Music

1. **Identify and Isolate the Hidden Sound**: Play the audio tracks and identify the one that contains the Morse code.
2. **Remove the Musical Component**: Delete the track that contains music, leaving only the track with the hidden sound.

*Tip*: If you’re new to using Audacity for removing audio components, you can check out **[this guide](https://support.audacityteam.org/audio-editing/splitting-a-recording-into-separate-tracks)**.

you can download the morse.mp3 file [here](/WR!T3-U9's/Solution-Files/Echoes-of-Enigma/morse.mp3)

### Step 5: Analyze the Remaining Audio

With the music removed, focus on the remaining track. Listen closely for any sequences of sounds that may indicate Morse code (short beeps and long beeps).

### Step 6: Decode the Morse Code

To decode the Morse code:

1. **Use an Online Morse Code Decoder**: Go to [Morse Code World](https://morsecode.world/international/decoder/audio-decoder-adaptive.html).
2. **Upload the Audio**: You can upload the remaining audio track or play it directly for decoding.
3. **Listen for Patterns**: The decoder will provide the translation of the Morse code into readable text.

If you’re curious to learn more about how Morse code works and want to practice manual decoding, this **[Morse Code guide](https://morsecode.world/international/morse2.html)** is a helpful resource.

### Step 7: Retrieve the Flag

After decoding, you will discover the hidden flag. The flag should be formatted as follows:

```text
FLAG-RAID{Y0U-C4N-H34R-7H15-FL4G}
```

---

## Conclusion

By following the outlined steps, including modifying the file header, utilizing Audacity for audio manipulation, and decoding Morse code, we successfully uncovered the hidden flag embedded within the audio file. This challenge showcases the importance of audio analysis and steganography techniques in cryptography.

If you want to dive deeper into similar cryptographic techniques used in audio files, you can explore **[Capture The Flag (CTF) audio challenges](https://ctftime.org/tasks/?tags=stegnography&hidden-tags=audio%2Cstegnography)** for more practice scenarios.
