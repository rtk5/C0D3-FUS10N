# Challenge Name: **Operation Cruise Control**

---

#### Author: A Arshad Khan

#### Difficulty: Hard +999

#### Points: 200

#### Wave: 2

---

## Challenge Overview

The goal of this challenge is to extract and crack the password from the provided packet capture file (`TOM-CRUISE-7E:DA:8B:BE:B7:AF.cap`). The password is 12 characters long, starts with a capital letter, contains a famous name related to **Tom Cruise**, followed by a special character, and ends with three numbers.

---

## Steps to Solve (on Linux)

### Step 1: Convert the Packet Capture to a Hashcat-Compatible Format

We begin by converting the `.cap` file to a format that Hashcat can process. This is done using the `hcxpcapngtool` utility:

```bash
hcxpcapngtool -o hash.hc22000 TOM-CRUISE-7E:DA:8B:BE:B7:AF.cap
```

Alternatively, you can also use an online tool like [cap2hashcat](https://hashcat.net/cap2hashcat/) for conversion.

you can download the hash.hc22000 [here](\Solution-Files\Operation-Cruise-Control\hash.hc22000)

If you're new to handling packet captures, you can read more about packet analysis with **[Wireshark](https://www.techtarget.com/whatis/definition/Wireshark#:~:text=Wireshark%20is%20a%20widely%20used,ensure%20smooth%20operations%20and%20security.)**, a widely-used network protocol analyzer.

### Step 2: Generate a Wordlist Based on the Password Pattern

According to the provided hints, the password format includes:

- A famous name related to **Tom Cruise**.
- A special character.
- A sequence of three numbers.

In this case, the famous name is "Mapother" (Tom Cruise's real surname). To generate a wordlist based on this pattern, use the `crunch` tool:

```bash
sudo crunch 12 12 -t Mapother^%%% -o wordlist.txt
```

This command generates a wordlist where:

- "Mapother" is the famous name.
- `^` is a placeholder for a special character.
- `%%%` represents three digits.

you can download the wordlist.txt [here](\Solution-Files\Operation-Cruise-Control\wordlist.txt)

For more information on generating custom wordlists, check out **[this guide on creating wordlists with Crunch](https://medium.com/@cuncis/building-unique-wordlists-with-crunch-1ca49f1f188b)**.

### Step 3: Crack the Password Using Hashcat

Now, use Hashcat to perform a dictionary attack on the prepared hash:

```bash
hashcat -m 22000 -a 0 hash.hc22000 wordlist.txt
```

This command uses Hashcat with mode `22000` (WPA-EAPOL-PBKDF2) and runs a dictionary attack using `wordlist.txt`.

To learn more about Hashcat's usage and modes, check out the **[Hashcat guide](https://www.freecodecamp.org/news/hacking-with-hashcat-a-practical-guide/)**.

### Step 4: Alternative Method - Crack with John the Ripper

You can also use John the Ripper to crack the password:

```bash
john --wordlist=wordlist.txt --format=wpapsk hash.hc22000
```

This command uses the generated wordlist with John the Ripper to crack the WPA hash. For a deeper dive into John the Ripper, **[John the Ripper guide](https://www.freecodecamp.org/news/crack-passwords-using-john-the-ripper-pentesting-tutorial/)**.

---

## Steps to Solve (on Windows)

### Step 1: Download Necessary Tools

1. **Hashcat**: Download Hashcat for Windows from [Hashcat's official site](https://hashcat.net/hashcat/). Extract the contents to a directory, e.g., `C:\hashcat\`.
2. **hcxpcapngtool**: Download the Windows version of `hcxpcapngtool` from [hcxtools GitHub Releases](https://github.com/ZerBea/hcxtools/releases). Extract it to a directory like `C:\hcxtools\`.
3. **Crunch**: For generating wordlists, download **Crunch** for Windows from [here](https://github.com/shadwork/Windows-Crunch/releases), and extract it to a directory, e.g., `C:\crunch\`.

### Step 2: Convert the Packet Capture File

Open **Command Prompt** (or PowerShell) and navigate to the folder where you extracted `hcxpcapngtool`. Use the following command to convert the `.cap` file into a `.hc22000` format:

```cmd
cd C:\hcxtools
hcxpcapngtool.exe -o hash.hc22000 TOM-CRUISE-7E:DA:8B:BE:B7:AF.cap
```

This command will create a file called `hash.hc22000`, which is compatible with Hashcat.

### Step 3: Generate Wordlist with Crunch

In **Command Prompt**, generate a wordlist:

```cmd
cd C:\crunch
./crunch_win.exe 12 12 -t Mapother^%%% -o wordlist.txt
```

This command creates a `wordlist.txt` file containing all possible combinations based on the pattern:  

- **Mapother** (name)
- **^** (special character)
- **%%%** (three numbers)

### Step 4: Crack the Password with Hashcat

Now, use Hashcat to crack the password:

```cmd
cd C:\hashcat
hashcat.exe -m 22000 -a 0 C:\hcxtools\hash.hc22000 C:\crunch\wordlist.txt
```

This command uses Hashcat in WPA mode (`-m 22000`) with a dictionary attack (`-a 0`) to crack the password using the generated wordlist.

### Step 5: Retrieve the Password

Once Hashcat finishes, the password will be displayed:

```text
Mapother|843
```

### Step 6: Format the Flag

The password is formatted as:

```text
FLAG-RAID{Mapother|843}
```

---

## Conclusion

By converting the packet capture, generating a custom wordlist, and running a dictionary attack using Hashcat or John the Ripper, we successfully cracked the password and retrieved the challenge flag.

For those looking to further their knowledge in wireless security, consider checking out **[the WiFi Security Guide](https://www.securew2.com/blog/complete-guide-wi-fi-security)** which covers best practices and techniques for securing wireless networks.
