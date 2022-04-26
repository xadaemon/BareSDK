import ctypes
from base64 import urlsafe_b64encode

if __name__ == '__main__':
    libpath = "../cmake-build-debug-systemclang/libdynbsdk.so"
    clib = ctypes.CDLL(libpath)
    buffer = ctypes.create_string_buffer(b"", 16)
    fp = open("/home/mxavier/Downloads/Rocky-8.5-x86_64-dvd1.iso", "rb")
    data = fp.read()
    fp.close()
    clib.bsdk_merhash(buffer, data, len(data))
    digest = int.from_bytes(buffer.raw, "big", signed=False)
    print(f"{libpath} {digest :X} {urlsafe_b64encode(buffer.raw).decode('utf-8')}")
