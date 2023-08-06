# axp_control-miyoo
Test app for communicating with axp223

Usage: %s [shutdown|acin|charging|read|wifi on|off|chgled 0|1|2]

read:
<details>

```
/mnt/SDCARD # axp_control read
Register 0x00: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x01: 0x30
  Bits: 0, 0, 0, 0, 1, 1, 0,
Register 0x04: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x05: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x06: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x07: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x08: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x09: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x0A: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x0B: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x0C: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x0D: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x0E: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x0F: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x10: 0xFF
  Bits: 1, 1, 1, 1, 1, 1, 1,
Register 0x12: 0xD8
  Bits: 0, 0, 0, 1, 1, 0, 1,
Register 0x13: 0x81
  Bits: 1, 0, 0, 0, 0, 0, 0,
Register 0x15: 0x1A
  Bits: 0, 1, 0, 1, 1, 0, 0,
Register 0x16: 0x1A
  Bits: 0, 1, 0, 1, 1, 0, 0,
Register 0x17: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x18: 0x1A
  Bits: 0, 1, 0, 1, 1, 0, 0,
Register 0x19: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x1A: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x1B: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x1C: 0x04
  Bits: 0, 0, 1, 0, 0, 0, 0,
Register 0x21: 0x0E
  Bits: 0, 1, 1, 1, 0, 0, 0,
Register 0x22: 0x19
  Bits: 1, 0, 0, 1, 1, 0, 0,
Register 0x23: 0x19
  Bits: 1, 0, 0, 1, 1, 0, 0,
Register 0x24: 0x19
  Bits: 1, 0, 0, 1, 1, 0, 0,
Register 0x25: 0x0A
  Bits: 0, 1, 0, 1, 0, 0, 0,
Register 0x27: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x28: 0x17
  Bits: 1, 1, 1, 0, 1, 0, 0,
Register 0x29: 0x12
  Bits: 0, 1, 0, 0, 1, 0, 0,
Register 0x2A: 0x17
  Bits: 1, 1, 1, 0, 1, 0, 0,
Register 0x30: 0x60
  Bits: 0, 0, 0, 0, 0, 1, 1,
Register 0x31: 0x03
  Bits: 1, 1, 0, 0, 0, 0, 0,
Register 0x32: 0x7B
  Bits: 1, 1, 0, 1, 1, 1, 1,
Register 0x33: 0xCA
  Bits: 0, 1, 0, 1, 0, 0, 1,
Register 0x34: 0x45
  Bits: 1, 0, 1, 0, 0, 0, 1,
Register 0x35: 0x0E
  Bits: 0, 1, 1, 1, 0, 0, 0,
Register 0x36: 0x5B
  Bits: 1, 1, 0, 1, 1, 0, 1,
Register 0x37: 0x08
  Bits: 0, 0, 0, 1, 0, 0, 0,
Register 0x38: 0xA5
  Bits: 1, 0, 1, 0, 0, 1, 0,
Register 0x39: 0x1F
  Bits: 1, 1, 1, 1, 1, 0, 0,
Register 0x3C: 0xFC
  Bits: 0, 0, 1, 1, 1, 1, 1,
Register 0x3D: 0x16
  Bits: 0, 1, 1, 0, 1, 0, 0,
Register 0x40: 0xD8
  Bits: 0, 0, 0, 1, 1, 0, 1,
Register 0x41: 0xFF
  Bits: 1, 1, 1, 1, 1, 1, 1,
Register 0x42: 0x03
  Bits: 1, 1, 0, 0, 0, 0, 0,
Register 0x43: 0x03
  Bits: 1, 1, 0, 0, 0, 0, 0,
Register 0x44: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x45: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x48: 0x20
  Bits: 0, 0, 0, 0, 0, 1, 0,
Register 0x49: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x4A: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x4B: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x4C: 0x40
  Bits: 0, 0, 0, 0, 0, 0, 1,
Register 0x56: 0xAB
  Bits: 1, 1, 0, 1, 0, 1, 0,
Register 0x57: 0x0A
  Bits: 0, 1, 0, 1, 0, 0, 0,
Register 0x58: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x59: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x78: 0xC9
  Bits: 1, 0, 0, 1, 0, 0, 1,
Register 0x79: 0x08
  Bits: 0, 0, 0, 1, 0, 0, 0,
Register 0x7A: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x7B: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x7C: 0x1F
  Bits: 1, 1, 1, 1, 1, 0, 0,
Register 0x7D: 0x03
  Bits: 1, 1, 0, 0, 0, 0, 0,
Register 0x80: 0x80
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x82: 0xE0
  Bits: 0, 0, 0, 0, 0, 1, 1,
Register 0x84: 0x32
  Bits: 0, 1, 0, 0, 1, 1, 0,
Register 0x85: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x8A: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x8C: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x8D: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x8F: 0x01
  Bits: 1, 0, 0, 0, 0, 0, 0,
Register 0x90: 0x07
  Bits: 1, 1, 1, 0, 0, 0, 0,
Register 0x91: 0x1F
  Bits: 1, 1, 1, 1, 1, 0, 0,
Register 0x92: 0x07
  Bits: 1, 1, 1, 0, 0, 0, 0,
Register 0x93: 0x1F
  Bits: 1, 1, 1, 1, 1, 0, 0,
Register 0x94: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0x97: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0xB8: 0xC0
  Bits: 0, 0, 0, 0, 0, 0, 1,
Register 0xB9: 0x89
  Bits: 1, 0, 0, 1, 0, 0, 0,
Register 0xE0: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0xE1: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0xE6: 0xA0
  Bits: 0, 0, 0, 0, 0, 1, 0,
Register 0xE8: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0xE9: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,
Register 0xEC: 0x00
  Bits: 0, 0, 0, 0, 0, 0, 0,

```
</details>
