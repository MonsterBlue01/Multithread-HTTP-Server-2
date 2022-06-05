1.  1.2[Base CPI] + 0.1[Branch Instruction](0.25[Branch Taken](0.6[Delay Slots filled] * 2[Delay Cycles] + 
    0.4[Delay Slots not filled] * 3[Delay Cycles]) + 0.75[Branch Not Taken](0.6[Delay Slots filled] * 0[Delay Cycles] + 
    0.4[Delay Slots not filled] * 1[Delay Cycles])) + 0.2[Jump Instruction](0.6[Delay Slots filled] * 1[Delay Cycles] + 
    0.4[Delay Slots not filled] * 2[Delay Cycles])

    ; If delay slots are filled, then it will less one.
    
2.  BTB has 8 bits, so erase the last "0" and keep last 3 digits. PHT has 16 bits, so erase the last "0" and keep last 
    4 digits. For example, 0x318. Convert 318 to 0b00011000. 00011000 -> 000110. For PHT, 0110. 0b0110 -> 6. So set 00 
    to 01. For BTB, 0110. 0b110 -> 6. So set 00 to 01. 

    Tips: BTB: Just find that and set that to the corresponding number. PHT: 00 (Predict NO, Actually NO) -> 01 
    (Predict YES, Actually NO) -> 11 (Predict YES, Actually YES) -> 10 (Predict YES, Actually NO) -> 00 (Predict NO, 
    Actually NO).
    ; Are these two digits seperated or it's a whole number?

3.  0x0:  lui a3,0x0:  F0 F1 D  X  WB
    0x2:  li a4,0:        F0 F1 D  X  WB (Not using the previous register)
    0x6:  li a2, 3:          F0 F1 D  X  WB (Not using the previous register)
    0x8:  j 0x10:               F0 F1 D  X  WB (Not using the previous register)
    0xa:  addiw a4,a4,1:           F0 F1 (The latter part is flushed (because jump jumps to the corresponding register in the decode part, the latter part can be omitted directly)
    0xc:  beq a4,a2,0x24:             F0 (Same reason as above)
    0x10: lw a5,0(a3) # 0:               F0 F1 D X0 X1 X2[0]    WB (Other)
    0x14: andi a5,a5,1:                     F0 F1 D  D  D        X[0][1](This is the process for caltulation(0 and 1 = 0)) WB (Previous instruction use EX and that cause hazard)
        ; We can only execute 0x14 after 0x10
    0x16: beqz a5,0xa:                         F0 F1 F1 F1 D X0[0][1] X1        WB (Still stalled)
                                                        (The 0 is from previous instruction, 1 is passed in)
    0x18: j 0xa:                                  F0 F0 F0 F1 D X0              X0 WB (Still has hazard)
    0x22: lw a5,0(a3):                                     F0 F1 (Other parts got flushed)

4.  A: Correct
    B: Predict not taken, so we have to flush it, but it didn't do that.
    C: No branch delay slot, which means two lines need to be flushed instead of one.

5.  add  r2, r2, r3:        IF ID X0 WB
foo: add  r3, r3, #1:          IF ID X0 WB
    cmp  r3, r7:                  IF ID X0 X1 WB ; Pay attention to the questions when taking the 
        ; final exam.
    bne foo:                         IF ID ID ID X0 WB ; Why does the ID card here have three cycles 
        ; instead of entering X0 directly in the previous line X1?
    ldr r3, .L9:                        IF IF IF (FLUSHED) ; The question mentioned branch taken 2 
        ; times
foo: add  r3, r3, #1:                            IF ID X0 WB
    cmp  r3, r7:                                    IF ID X0 X1 WB
    bne foo:                                           IF ID ID ID X0 WB
    ldr r3, .L9:                                          IF IF IF (FLUSHED)
foo: add  r3, r3, #1:                                              IF ID X0 WB
    cmp  r3, r7:                                                      IF ID X0 X1 WB
    bne foo:                                                             IF ID ID ID X0 WB ; What 
        ; exactly does this step do? Why is the time of jumping back different this time?