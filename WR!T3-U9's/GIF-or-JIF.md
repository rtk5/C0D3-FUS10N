# Challenge Name: GIF or JIF

#### Author: Mohammed Musharraf 
#### Difficulty: [Hard]

#### Points: 100

#### Wave: 1
#### Number of Solves: 22

## Challenge Description
The challenge involves analyzing a GIF that, when split into individual frames, reveals pieces of multiple QR codes. Participants need to reconstruct these QR codes and find the one containing the hidden flag.

## Solution

### Breaking Down the GIF
Start by breaking down the provided GIF into individual frames using a Python script or a tool like ImageMagick. Each QR code is formed by grouping specific frames. 

- Frames `00.png, 010.png, 020.png, ...` will combine to form QR Code 1.
- Frames `01.png, 011.png, 021.png, ...` will combine to form QR Code 2, and so on.

### Reconstructing QR Codes
After splitting the GIF, you should end up with segments that combine into 10 QR codes. Each QR code is unique and of a different color. Reassemble the QR codes by merging the corresponding frames.

### Scanning the QR Codes
Scan each of the  QR codes. One of the QR codes will contain the hidden flag.

## Flag
Once you find the correct QR code, it will reveal the flag in the format:

`FLAG-RAID{Gi7_i5_C0oL}`

