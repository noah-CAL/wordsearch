import collections
import os
import random
import re
import sys

def randomize_wordlists(n=10):
    """
    Randomizes and creates a set of N wordlists from the dictionary of 100,000 english words. 
    Each file will be named of the format "dict_i.txt" and will contain a semi-random ordering
    of words.
    """
    # Delete any current lists to restart the randomization
    curr_lists = [list for list in os.listdir() if re.search(r"dict_\d+\.txt", list)]
    for wordlist in curr_lists:
        if os.path.exists(wordlist):
            os.remove(wordlist)

    SOURCE_LIST = "dictionary_large.txt"
    # Use a DeQueue for fast insertion on either sides of the list
    wordlists = {f"dict_{i}.txt": collections.deque() 
                    for i in range(n)}
    with open(SOURCE_LIST, "r") as f:
        dequeue_list = list(wordlists.values())
        for line in f:
            # Randomize whether we add each word to the start or the end 
            # of each DeQueue
            rand_list = random.choice(dequeue_list)
            append_left = random.randint(0, 1)
            rand_list.appendleft(line) if append_left else rand_list.append(line)
    for dict_name, wordlist in wordlists.items():
        with open(dict_name, "w") as f:
            f.writelines(wordlist)


if __name__ == "__main__":
    n = 10
    if len(sys.argv) > 1:
        try:
            n = int(sys.argv[1])
            if n < 0:
                raise TypeError(f"Input {n} must be >= 1")
        except TypeError:
            raise TypeError(f"Input {n} must be a positive integer >= 1. ")
    randomize_wordlists(n)

