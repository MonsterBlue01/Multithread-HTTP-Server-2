1. Just get the multiplication and get the addition. CPI = 0.2 * 1 
    + 0.4 * 2 + 0.1 * 3 + 0.3 * 4 = 2.5. IPC = 1 / 2.5 = 0.4.

2. LD and other have the largest fractions. So we pick these two.

3. Even removing the Other part doesn't achieve that amount of 
    speedup. So it's not possible.
    ; How to calculate the speedup?

4.  (1): addi x3,x7,0x03 - im: 000000000011 rs1: 00111 func3: 000 rd: 00011 opcode: 0010011
    (2): jalr x8, x5, 0x10 (!!: It's hex) - 000000010000 im: 000000010000 rs1: 00101 func3: 000 rd: 01000 opcode: 1100111
    (3): bne x1,ra, 0x30 - im 12|10:5: 0000001 rs2: 00001 rs1: 00001 func3: 001 im 4:1|11: 10000 opcode: 1100011 00110000

5.  (1): INST 1: addi x3,x7,0x03:                       A: 
                                                        B:
                                                        C:
                                                        D:
    (2): INST 2: jalr x8, x5, 0x10                      A:
                                                        B:
                                                        C:
                                                        D:
    (3): INST 3: bne x1,ra, 0x30  // if taken, PC+0x30  A:
                                                        B:
                                                        C:
                                                        D: