1. Just get the multiplication and get the addition. CPI = 0.2 * 1 
    + 0.4 * 2 + 0.1 * 3 + 0.3 * 4 = 2.5. IPC = 1 / 2.5 = 0.4.

2. LD and other have the largest fractions. So we pick these two.

3. Even removing the Other part doesn't achieve that amount of 
    speedup. So it's not possible.
    ; How to calculate the speedup?

4.  (1): addi x3,x7,0x03 - im: 000000000011 rs1: 00111 func3: 000 rd: 00011 opcode: 0010011
    (2): jalr x8, x5, 0x10 (!!: It's hex) - 000000010000 im: 000000010000 rs1: 00101 func3: 000 rd: 01000 opcode: 1100111
    (3): bne x1,ra, 0x30 - im 12|10:5: 0000001 rs2: 00001 rs1: 00001 func3: 001 im 4:1|11: 10000 opcode: 1100011 00110000

5.  (1): INST 1: addi x3,x7,0x03:                       A: 0x07 ; Reason: The input is the content of the first register.
                                                        B: 0x27 ; Reason: This is what is built into the register.
                                                        C: 0X2A ; Reason: 0x27 + 0x03 = 0x2A.
                                                        D: 0x00 ; Reason: Not branch, not jump, so the output is 0.
    (2): INST 2: jalr x8, x5, 0x10                      A: 0x05 ; Reason: The input is the content of the first register.
                                                        B: 0x25 ; Reason: This is what is built into the register.
                                                        C: 0x35 ; Reason: 0x25 + 0x10 = 0x35.
                                                        D: 0x01 ; Readon: It's jump, so one of the input of OR gate is 1. Therefore, the output is 1.
    (3): INST 3: bne x1,ra, 0x30  // if taken, PC+0x30  A: 0x01 ; Reason: The input is the content of the first register.
                                                        B: 0x21 ; Reason: This is what is built into the register.
                                                        C: 0x00 ; Reason: x1 = ra, so equal. 
                                                        D: 0x00 ; Reason: Jump part is 0, and the output from ALU is 0. So the output is 0.

6.  0xfef42623 -> 0b11111110111101000010011000100011. So the opcode is 0100011. Therefore, choose A.

7.  im: 111111101100, rs1:01000, func3: 010, rd: 01111, opcode: 0000011 -> 0b111111101100 01000 010 01111 0000011 -> 0xfec42783
    ; Can't understand "im", "rs1", "rd"