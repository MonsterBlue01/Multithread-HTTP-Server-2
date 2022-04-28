// Question:
//     1: How to check the value in Control Unit?
//     2: How to check the output from ALU?
//     3: How to get the value for third one in INST 2?

// 1. IPC = 1 / CPI = 1 / (0.2 * 1 + 0.4 * 2 + 0.1 * 3 + 0.3 * 4) = 1 / 2.5 = 0.4

// 2. ADD = 0.2 * 1 = 0.2
//    LD = 0.4 * 2 = 0.8
//    jump = 0.1 * 3 = 0.3
//    Other = 0.3 * 4 = 1.2
//    1.2 > 0.8 > 0.3 > 0.2
//    Therefore, we should choose LD and Other.

// 3. Let's only calculate the IPC exclude "Other" part. The result is:
//    IPC = 1 / CPI = 1 / (0.2 * 1 + 0.4 * 2 + 0.1 * 3) = 1 / 1.3 = 0.76
//    Therefore, it's impossible if we want to improve IPC to 1.5 by only improve "Other" part

// 4. (1). 00000000001100111000000110010011
//    (2). 00000001000000101000010001100111
//    (3). 00000010000100001001100001100011

// 5. (1).    A: 0x07       This is the register 1
        //    B: 0x27       The thing that register 1 contains is 0x27
        //    C: 0x2A       This is the sum of register and immediate (0x27 + 0x03)
        //    D: 0x00       From the previous line, the result obtained after the data passes through several gates is 0x00.

//    (2).    A: 0x05       This is the register 1
        //    B: 0x25       The thing that register 1 contains is 0x25
        //    C: 0x00       ???
        //    D: 0x01       Look directly at the output of the or gate. One of them is 1, so the output is 0x01.

//    (3).    A: 0x05       This is the register 1
        //    B: 0x21       The thing that register 1 contains is 0x21
        //    C: 0x2A       The predicate condition fails, outputting 0x00 instead of 0x01.
        //    D: 0x01       The result of both and gates is false. So the output is 0x00.