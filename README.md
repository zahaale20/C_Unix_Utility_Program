# C_Unix_Utility_Programs

The "C_Unix-Utility_Programs" GitHub repository contains two C programs, each replicating a classic Unix utility. These programs are focused on text processing and are designed to operate under specific constraints to mimic Unix system behaviors.

Word Count (word_count.c): This program functions similarly to the Unix 'wc' utility, counting characters, words, and lines in an input stream. It defines a word as a sequence of characters separated by whitespace and a line as a sequence ending in a newline character. The program is structured to read input one character at a time, without using dynamic memory allocation.

Unique Lines (unique.c): Modeled after the Unix 'uniq' utility, this program filters out consecutive duplicate lines from its input. It reads input line by line, using the getline function, and prints each unique line to the output. The focus is on efficient input handling and comparison without explicit dynamic memory allocation.
