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
27. Conditional Branch: An instruction that tests a value and that allows for a subsequent transfer of control to a new address in the program based on the 
    outcome of the test.
28. Branch Address Table: Also called branch table. A table of addresses of alternative instruction sequences.
29: Procedure: A stored subroutine that performs a specific task based on the parameters with which it is provided.
30: jump-and-link instruction An instruction that branches to an address and simultaneously saves the address of the following instruction in a register 
    (usually x1 in RISC-V).
31: Return Address: A link to the calling site that allows a procedure to return to the proper address; in RISC-V it is stored in register x1.
32: Caller: The program that instigates a procedure and provides the necessary parameter values.
33: Callee: A procedure that executes a series of stored instructions basedon parameters provided by the caller and then returns control to the caller.
34: Program Counter (PC): The register containing the address of the instruction in the program being executed.
35: Global Pointer: The register that is reserved to point to the static area.
36: Procedure Frame: Also called activation record. The segment of the stack containing a procedure’s saved registers and local variables.
37: Frame Pointer: A value denoting the location of the saved registers and local variables for a given procedure.
38: Text Segment: The segment of a UNIX object file that contains the machine language code for routines in the source file.
39: PC-relative Addressing: An addressing regime in which the address is the sum of the program counter (PC) and a constant in the instruction.
40: Addressing Mode: One of several addressing regimes delimited by their varied use of operands and/or addresses.
41: Data Race: Two memory accesses form a data race if they are from different threads to the same location, at least one is a write, and they occur one 
    after another.
42: Pseudoinstruction: A common variation of assembly language instructions often treated as if it were an instruction in its own right.
43: Symbol Table: A table that matches names of labels to the addresses of the memory words that instructions occupy.
44: Linker: Also calledlink editor. A systems program that combines independently assembled machine language programs and resolves all undefined labels 
    into an executable file.
45: executable file A functional program in the format of an object file that contains no unresolved references. It can contain symbol tables and debugging 
    information. A “stripped executable” does not contain that information. Relocation information may be included for the loader.
46: Dynamically Linked Libraries (DLLs): Library routines that are linked to a program during execution.
47: Arithmetic Logic Unit (ALU): Hardware that performs addition, subtraction, and usually logical operations such as AND and OR.
48: Combinational Element: An operational element, such as an AND gate or an ALU.
49. State Element: A memory element, such as a register or a memory
50: Clocking Methodology: The approach used to determine when data are valid and stable relative to the clock.
51: Edge-triggered Clocking: A clocking scheme in which all state changes occur on a clock edge.

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
13: Machine A is n times faster than machine B means: 
    Speedup = performance_A / Performance_B = Execution time_B/ Excution time_A

Machine code <-> Assembly code:
    Immediate; 12 bits
    Register: 5 bits
    funct7: 7 bits
    funct3: 3 bits
    opcode: 7 bits
