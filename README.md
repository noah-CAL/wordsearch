Wordlist taken from: mit.edu/~ecprice/wordlist.100000

# WORDSEARCH

This is a brief project to find whether a word is in a *randomized* list of 100,000 words which are split across multiple files.

Learning objectives:

1) Learn Makefiles to build project
2) Work with C file readers and file I/O
3) Use OpenMP to parallize the search and make it more efficient

The file `randomize.py` contains a function `randomize_wordlists` which splits up `dictionary_large.txt` into N smaller dictionary files with an independent random word ordering. Thus, the C `wordsearch` program can be tested by determining if a given word is found in 2 text files or 80 textfiles.
