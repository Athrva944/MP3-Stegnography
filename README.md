# MP3 Tag Reader

## Introduction
The MP3 Tag Reader is an application that reads metadata (tags) embedded in MP3 files. These tags provide information about the audio file, such as the title, artist, album, year, and genre. The project demonstrates how to extract and display this metadata from an MP3 file using the ID3 tag standard.

## How MP3 Tag Reading Works
### ID3 Tags
1. **ID3v1**: A metadata container at the end of the MP3 file, storing information like song title, artist, album, year, and genre.
2. **ID3v2**: A more extensive version, located at the beginning of the MP3 file, supporting larger fields and additional metadata (e.g., album art, lyrics).

### Reading Process
1. The application reads the MP3 file, locates the ID3 tags (v1 or v2), and extracts metadata from them.
2. The extracted metadata is displayed in a readable format.

## Requirements
- **GCC version 8.0 or higher** for compiling the program.
- Optionally, you can use `make` for building the project.
- **MP3 Audio Format**: The program only supports the `.mp3` format with embedded ID3 tags.

## Features
1. **Read ID3v1 and ID3v2 Tags**: The program can extract metadata from both ID3v1 and ID3v2 tags.
2. **Display MP3 Metadata**: Displays title, artist, album, year, genre, and additional information from the MP3 file.
3. **Support for Various Tag Fields**: Supports various fields such as comments, track number, and more, depending on the ID3 version.
4. **Optional Validation**: Optionally validates the presence of valid ID3 tags in an MP3 file.

## Usage

### Reading MP3 Tags
```bash
./mp3_tag_reader song.mp3

## Example Output
Title:      Song Title
Artist:     Artist Name
Album:      Album Name
Year:       2024
Genre:      Pop
Comments:   Some comments here
Track:      5
