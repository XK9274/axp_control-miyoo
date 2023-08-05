#include <stdio.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>

void read_all_registers(int file) { // pulled a bunch of registers off the axp document
  char registers[] = {
  0x00, 0x01, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 
  0x10, 0x12, 0x13, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x21, 0x22, 0x23, 
  0x24, 0x25, 0x27, 0x28, 0x29, 0x2A, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 
  0x38, 0x39, 0x3C, 0x3D, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x48, 0x49, 0x4A, 0x4B, 
  0x4C, 0x56, 0x57, 0x58, 0x59, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x80, 0x82, 0x84, 
  0x85, 0x8A, 0x8C, 0x8D, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94, 0x97, 0xB8, 0xB9, 0xE0, 
  0xE1, 0xE6, 0xE8, 0xE9, 0xEC
  };

  for (int i = 0; i < sizeof(registers); i++) {
    char regAddr = registers[i];
    char regValue;

    if (write(file, &regAddr, 1) != 1 || read(file, &regValue, 1) != 1) {
      perror("Failed to read from the device");
      return;
    }

    printf("Register 0x%02X: 0x%02X\n", regAddr, regValue);
    printf("  Bits: ");
    for (int j = 0; j < 5; j++) { // read up to 5 bits (0 - 4) 
      printf("%d", (regValue >> j) & 0x01);
      if (j < 4) {
        printf(", ");
      }
    }
    printf("\n");
  }
}

int main(int argc, char *argv[]) {
  if (argc < 2 || (strcmp(argv[1], "shutdown") != 0 && strcmp(argv[1], "acin") != 0 && strcmp(argv[1], "charging") != 0 && strcmp(argv[1], "read") != 0)) {
    fprintf(stderr, "Usage: %s [shutdown|acin|charging|read] [-f filename]\n", argv[0]); // can print to file for the read command
    return -1;
  }

  FILE *outputFile = stdout;
  if (argc == 4 && strcmp(argv[2], "-f") == 0) {
    outputFile = fopen(argv[3], "w");
    if (outputFile == NULL) {
      perror("Failed to open output file");
      return -1;
    }
  }

  int file = open("/dev/i2c-1", O_RDWR);
  if (file < 0) {
    perror("Failed to open the bus");
    return -1;
  }

  if (ioctl(file, I2C_SLAVE, 0x34) < 0) {
    perror("Failed to acquire bus access and/or talk to slave");
    return -1;
  }

  if (strcmp(argv[1], "read") == 0) {
    read_all_registers(file);
    if (outputFile != stdout) {
      int tmp_stdout = dup(fileno(stdout));
      fflush(stdout);
      dup2(fileno(outputFile), STDOUT_FILENO);
      read_all_registers(file);
      fflush(stdout);
      dup2(tmp_stdout, STDOUT_FILENO);
      close(tmp_stdout);
    }
  }

  char regAddr;
  char regValue;

  if (strcmp(argv[1], "shutdown") == 0) {
    regAddr = 0x32;
    if (write(file, &regAddr, 1) != 1 || read(file, &regValue, 1) != 1) {
      perror("Failed to read from the device");
      return -1;
    }
    regValue |= (1 << 7);
    char buf[2] = {regAddr, regValue};
    if (write(file, buf, 2) != 2) {
      perror("Failed to write to the device");
      return -1;
    }
    printf("Sent shutdown command to AXP223\n");
  }
  else if (strcmp(argv[1], "acin") == 0) {
    regAddr = 0x48;
    if (write(file, &regAddr, 1) != 1 || read(file, &regValue, 1) != 1) {
      perror("Failed to read from the device");
      return -1;
    }
    int acinPluggedIn = (regValue >> 6) & 0x01;
    printf("ACIN is %splugged in\n", acinPluggedIn ? "" : "not ");
  }
  else if (strcmp(argv[1], "charging") == 0) {
    regAddr = 0x49;
    if (write(file, &regAddr, 1) != 1 || read(file, &regValue, 1) != 1) {
      perror("Failed to read from the device");
      return -1;
    }
    int charging = (regValue >> 3) & 0x01;
    printf("Charging status: %s\n", charging ? "Charging" : "Not Charging");
  }

  if (outputFile != stdout) {
    fclose(outputFile);
  }

  close(file);
  return 0;
}