# Inverted Search

An implementation of an **Inverted Index** in C using **Hashing**, designed for fast full-text search across multiple files. Commonly used in document retrieval systems and search engines.

## Overview

This project creates an inverted index from a set of text files. It maps each word to the files where it appears and tracks the frequency in each file, enabling fast keyword-based searches.

## Features

- Accepts multiple text files as input
- Builds a searchable inverted index
- Tracks:
  - Word occurrences
  - File names containing the word
  - Frequency of each word in respective files
- Supports querying: search a word to get list of files and counts

## Technologies Used

- **Language**: C  
- **Concepts**:  
  - Hash Tables  
  - File Handling  
  - String Parsing  
  - Linked Lists (for chaining)  

## Usage

1. Compile the code using `make`.
2. Then `./a.out <filenames>`
3. Run the program and provide input files.
4. Use the CLI to search for keywords or view the complete index.

