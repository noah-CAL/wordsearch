Wordlist taken from: mit.edu/~ecprice/wordlist.100000

# WORDSEARCH

This is a brief project to find whether a word is in a *randomized* list of 100,000 words which are split across multiple files.

Learning objectives:

1) Learn Makefiles to build project
2) Work with C file readers and file I/O
3) Use OpenMP to parallize the search and make it more efficient

The file `randomize.py` contains a function `randomize_wordlists` which splits up `dictionary_large.txt` into N smaller dictionary files with an independent random word ordering. Thus, the C `wordsearch` program can be tested by determining if a given word is found in 2 text files vs. 200 textfiles.

## Timing results (400 dictionary files + 8 threads)
With 400 dictionary files and 8 threads on my laptop, average speedup is ~2x with a simple parallelization approach using OpenMP.

![image](https://user-images.githubusercontent.com/90151434/209312034-9a041374-c7b5-4609-b04d-72b8c2e4f9ec.png)
