# Image Editor in C: A CLI-Based Tool

## Overview

This repository contains a CLI-based image editing tool written in C, designed to process and manipulate image files. Users can upload their desired image and adjust various aspects of the photo, such as brightness, contrast, saturation, or temperature. The program supports a select range of edits, and it is designed with simplicity and efficiency in mind, catering to those who need quick modifications to their images without the need for complex software.
## Getting Started

To use this tool, clone the repository 
```bash
git clone https://github.com/weihong0827/simple-image-editor.git
```

Compile the source code with your C compiler.
```bash
make compile
```
You can directly run the program with the following command. include the name of the file you wish to edit, or the folder in which you wish to edit all the photos of.
```bash
make run filename=./images //folder
make run filename=./images/caked.ppm //file
```
It will automatically compile the source code and run the program.

The program is run through the command line, where you can specify the image file and desired edits according to the supported formats and commands.

## Folder Structure
- **src**: Contains the source code for the image editing tool.
- **images**: Contains sample images for testing the program.
- **includes**: Contains the header files for the program.
The [Makefile](./Makefile) contains the commands to compile and run the program.
There are 4 main files in the src folder:
  - **main.c**: Contains the main function to run the program, state machine, and user interaction.
  - **image.c**: Contains the functions to read, write, and manipulate the image.
  - **preset.c**: Contains the functions to handle the presets
  - **adjustments_func.c**: Contains the functions to apply the adjustments to the image. These adjustments are called from the `image.c` file.


## Features

- **Supported Image Formats**: Currently, the tool supports PPM and BMP file formats for easy manipulation and broad compatibility.
- **CLI-Based Editing**: All edits are made through the command line interface (CLI), allowing users to specify their desired adjustments in a straightforward manner (e.g., `Brightness -1`, `Contrast +5`).
- **Preview and Export**: The program provides a preview of the image after edits are applied. Users can then choose to export and save the file, either overwriting the original file or creating a new one.
- **Undo Functionality**: Supports undoing up to 9 times from the latest state to allow users to revert changes.
- **Limited State Tracking**: To manage memory efficiently and avoid infinite states, the program keeps up to 10 past states of the photo.

## Input and Output Requirements

### Input

- **Image File**: An image in PPM or BMP format.
- **User Commands**: Edits and commands inputted from the CLI.

### Output

- **Edited Image File**: The edited image in the same format as the input.

## Supported Edits

- Brightness
- High Contrast
- Shadows
- Temperature
- Tint
- Image Presets
- Grey Scale
- Negative
- Flatten
- Add Noise


## Parser Requirements

The parser is designed to handle PPM files as shown in the example provided. It will parse the header to determine the image format, size, and maximum RGB value. Each pixel's RGB components are then read and processed according to the user's commands.

We also have a CSV parser that reads the CSV file and applies the edits to the image. The CSV file should be formatted as follows:
```
command,value
```
You can also save the presets in the CSV file and apply them to the image.

## Program State Machine

The program operates in the following states:

1. **Initial**: Awaiting file upload.
2. **Editing State**: User is applying edits to the image.
3. **Exporting State**: User is saving the edited image.

## Editing Image State Machine

To facilitate undoing changes, the program tracks the state of the photo, maintaining up to 10 past states. This allows for significant flexibility in editing, with the following considerations:

- **Reset Functionality**: Users can reset the image to its initial state (no edits).
- **Edit Limitations**: Due to the RGB components being 1 byte each, there's a limit to the degree of edits. The program ensures that edits stay within viable ranges and notifies users if an edit is no longer doable.

