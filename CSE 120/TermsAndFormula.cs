Terms:
1. Response time: Also called execution time. The total time required for the computer to complete a task, including disk accesses, memory accesses, 
    I/O activities, operating system overhead, CPU execution time, and so on.
2. Throughput: Also called bandwidth. Another measure of performance, it is the number of tasks completed per unit time.
3. CPU execution time: Also called CPU time. The actual time the CPU spends computing for a specific task.
4. User CPU time: The CPU time spent in a program itself.
5. System CPU time: The CPU time spent in the operating system performing tasks on behalf of the program.
6. Clock Cycle: Also called tick, clock tick, clock period, clock, or cycle. The time for one clock period, usually of the processor clock, which runs at a 
    constant rate.
7. Clock Period: The length of each clock cycle.
8. Clock Cycles Per Instruction (CPI): Average number of clock cycles per instruction for a program or program fragment.
9. Instruction mix: A measure of the dynamic frequency of instructions across one or many programs.
10. Workload: A set of programs run on a computer that is either the actual collection of applications run by a user or constructed from real programs to 
    approximate such a mix. A typical workload specifies both the programs and the relative frequencies.
11. Benchmark: A program selected for use in comparing computer performance.
12. Amdahl’s Law: A rule stating thatthe performance enhancement possible with a given improvement is limited by the amount that the improved 
feature is used. It is a quantitative version of the law of diminishing returns.
13. Million Instructions Per Second (MIPS): A measurement of program execution speed based on the number of millions of instructions. MIPS is 
  computed as the instruction count divided by the product of the execution time and 106.
14. Instruction set: The vocabulary of commands understood by a given architecture
15. Stored-program Concept: The idea that instructions and data of many types can be stored in memory as numbers and thus be easy to change, leading to 
    the stored-program computer.
16. Doubleword: Another natural unit of access in a computer, usually a group of 64 bits; corresponds to the size of a register in the RISC-V architecture.
17. Word: A natural unit of access in a computer, usually a group of 32 bits.
18. Data transfer instruction: A command that moves data between memory and registers.
19. Address: A value used to delineate the location of a specific data element within a memory array.
20: Alignment Restriction: A requirement that data be aligned in memory on natural boundaries.
21: Least Significant Bit: The rightmost bit in an RISC-V doubleword.
22: Most significant bit: The leftmost bit in an RISC-V doubleword.
23: One’s complement A notation that represents the most negative value by 10 ... 000two and the most positive value by01 ... 11two, leaving an equal 
    number of negatives and positives but ending up with two zeros, one positive (00 ... 00two) and one negative (11 ... 11two). The term is also used to 
    mean the inversion of every bit in a pattern: 0 to 1 and 1 to 0.
24: Based notation A notation that represents the most negative value by 00 ... 000two and the most positive value by 11 ... 11two , with 0 typically 
    having the value 10 ... 00two, thereby biasing the number such that the number plus the bias has a non-negative representation.
25: Instruction format: A form of representation of an instruction composed of fields of binary numbers.
26: Machine Language: Binary representation used for communication within a computer system.

Formulas:
1. Performance = 1 / Excution time
2. CPU execution time = CPU clock cycles for a program for a program * Clock cycle time
3. CPU execution time for a program = CPU clock cycles for a program / Clock rate
4. CPU clock cycles = Instructions for a program * Average clock cycles per instruction
5. CPU time = Instructioncount * CPI * Clock cycle time
6. CPU time = Instruction count * CPI / Clock rate
7. CPU clock cycles = CPI * C
8. Power ratio = Power_new / Power_old
9. Power = Capacitive load * Voltage ^ 2 * Frequency Switched
10. Execution time after improvement = Execution time affected by improvement / Amount of improvement + Execution time unaffected
11. MIPS = Instruction count / (Execution time 10^6) = Instruction count / ((Instruction count * CPI / clock rate) * 10 ^ 6) = clock rate / CPI
* 10 ^ 6
12. Seconds / Program = (Instructions / Program) * (Clock cycles / Instructions) * (Seconds / Clock Cycle)
