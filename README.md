Wordlist taken from: mit.edu/~ecprice/wordlist.100000

# WORDSEARCH

This is a brief project to find whether a word is in a *randomized* list of 100,000 words which are split across multiple files.

Learning objectives:

1) Learn Makefiles to build project
2) Work with C file readers and file I/O
3) Use OpenMP to parallelize the search and make it more efficient

The file `randomize.py` contains a function `randomize_wordlists` which splits up `dictionary_large.txt` into N smaller dictionary files with an independent random word ordering. Thus, the C `wordsearch` program can be tested by determining if a given word is found in 2 text files vs. 200 textfiles.

## Timing results (400 dictionary files + 8 threads)
With 400 dictionary files and 8 threads on my laptop, average speedup is ~2x with a simple parallelization approach using OpenMP.

**Unoptimized**: serial approach which loops through every word in each file until a word is found (or not found in worst-case scenario).

**Optimized**: splits up work among `min(num_dictionaries, num_threads)` different threads resulting in a performance gain.

![image](https://user-images.githubusercontent.com/90151434/209740931-fe64220b-1716-4504-971c-fce44daec0f9.png)
