import ctypes
import requests

if __name__ == '__main__':
    data = requests.get("https://raw.githubusercontent.com/dwyl/english-words/master/words.txt")
    libpath = "../cmake-build-debug-systemclang/libdynbsdk.so"
    clib = ctypes.CDLL(libpath)
    clib.fnv1ext.restype = ctypes.c_uint64
    words = data.content.splitlines()
    words_hashl = []
    for word in words:
        words_hashl.append(f"{word.decode('utf-8')} - {hex(clib.fnv1ext(word, ctypes.c_size_t(len(word))))}")

    unique_hashes = set(words_hashl)
    seen = set()
    dupes = []

    for x in words_hashl:
        if x in seen:
            dupes.append(x)
        else:
            seen.add(x)

    print(dupes)
    print(len(words), len(unique_hashes), len(dupes))
    with open("out.txt", "w") as fd:
        for hash in unique_hashes:
            fd.write(f"{hash}\n")
