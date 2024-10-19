# Challenge Name: Image Base

#### Author: Mohammed Musharraf 
#### Difficulty: [Hard++]

#### Points: 100

#### Wave: 2 & 4
#### Number of Solves: 2
## Challenge Description

The challenge involves navigating through a misleading link to uncover a hidden flag.

## Solution

### Initial Deception
The author is on TryHackMe(THM). To find the hidden URL, visit my TryHackMe [Profile](https://tryhackme.com/p/MohammedMusharraf)  and explore the website linked there.

### Finding the Hidden URL
 `Image in Error` in question hints you to navigate URL/error
Now your (URL)[https://browhatdoiknowpesu.netlify.app/error]

There you can download [error.txt](error.txt)


### Decoding the File
The **error** contains base64 Encoded image to decode visit <b>
[CyberChef](https://gchq.github.io/CyberChef/#recipe=Render_Image('Base64'))

Once you Render Image you'll get 
[error.jpg](error.jpg)



## Flag
After following the steps above, you will uncover the final flag.

`FLAG-RAID{YOUR-GENIUS-404-SN}`
