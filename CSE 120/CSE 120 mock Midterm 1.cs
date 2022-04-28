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
//    (2). 