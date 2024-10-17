# Challenge Name: Insane Web  
#### Author: [Rishi A Sheth]  

#### Difficulty: Medium  

#### Points: 50  

#### Wave: Wave 3  
#### Number of Solves: 11  

#### Challenge Description:  
You are given a website: https://insanee.vercel.app/. Your goal is to mess around and find the hidden flag.

#### Hints:  
are you?
#### Files Attached:  
- None  

## Steps to Solve:  
1. The text that appears after the "Are you?" changes frequently, and those are clickable links.  
2. Wait until the word "flagg" appears. Click on it to go to a different website containing many buttons.  
3. Click on all the buttons. One of them will show an image saying "You found the flag."  
4. Inspect the website and find the encrypted flag in the comments of that button's HTML code.  
5. Decode the encrypted flag using ROT47 to reveal the final flag: `FLAG-RAID{HTTP_INSANE_302_Legend}`.
