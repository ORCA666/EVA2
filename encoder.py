#!/usr/bin/python
#coded by orca666

import sys


# Your shellcode [x64]
raw_data = "ur shellcode"

encoded_shellcode = []
for opcode in raw_data:
  # the encryption keys : ^ 0x11) ^ 0x52 ) ^ 0xc7) ^ 0xa3) ^ 0xd8) ^ 0x05) ^ 0x32) ^ 0xf7) ^ 0x7a) 
  # thus to decode it [if you want to change the key] place the key in reverse order in EVA.cpp 
  
        new_opcode = (((((((((ord(opcode) ^ 0x11) ^ 0x52 ) ^ 0xc7) ^ 0xa3) ^ 0xd8) ^ 0x05) ^ 0x32) ^ 0xf7) ^ 0x7a)
        encoded_shellcode.append(new_opcode)
print("".join(["\\x{0}".format(hex(abs(i)).replace("0x", "")) for i in encoded_shellcode]))
