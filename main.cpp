// Standard headers
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;


/*=========================================================
Tempalte: Vector
Author: QAISARAH SHAMSUL AZRAN
=========================================================*/

template<class T>
class Vector
{
private:
    T* data;
    int length;
    int capacity;

    void resize()
    {
        capacity *= 2;  //double the array capacity

        T* temp = new T[capacity];  //create a dynamic temporary array

        for(int i = 0; i < length; i++)
            temp[i] = data[i];  //assign all elements from old array to new array

        delete[] data;  //delete old array

        data = temp;    //temp array is the new data array
    }

public:
    Vector()
    {
        capacity = 4;
        length = 0;
        data = new T[capacity]; //when a vector is created, a dynamic array with capacity 4 is created
    }

    ~Vector()
    {
        delete[] data;  //delete the dynamic array from memory
    }

    void push_back(T value)
    {
        if(length == capacity)  //if the length of the elements in the array has reached max capacity, the array resizes
            resize();

        data[length] = value;   //assign the given value to the last index
        length++;   //increase length aka the index
    }

    void pop_back()
    {
        if(length == 0)
        {
            cout << "Vector is empty." << endl; //if the array is empty, give error message
            return;
        }

        length--;   //reduce the length aka the index so that cannot access the last element
    }

    bool empty()
    {
        if(length == 0)
        {
            return true;    //return true if empty
        }
        else
        {
            return false;   //return  false if not empty
        }
    }

    void insert(int index, T value)
    {
        if(length == capacity)  //if the length of the elements in the array has reached max capacity, the array resizes
        {
            resize();
        }

        if(index < 0 || index > length)
        {
            cout<<"Index out of range\n";   //if the index value given is more than the length of the array or less than 0, give error message
            return;
        }

        for(int i = length; i > index; i--)
        {
            data[i] = data[i-1];    //shifting/copying all elements from the desired index location to the right
        }

        data[index] = value;    //assign the value given to the index position
        length++;   //increase length
    }

    T& operator[](int index)
    {
        if(index < 0 || index >= length)
        {
            cout<<"Index out of range\n";   //if the index value given is more than the length of the array or less than 0, give error message
            exit(1);
        }
        return data[index]; //when operator [] is used, it returns the value at the given index
    }

    int size()
    {
        return length;
    }
};

/*=========================================================
Class: Stack
Author: QAISARAH SHAMSUL AZRAN
=========================================================*/

class Stack
{
private:
    signed char stack[8];
    int top;

public:
    Stack();
    bool isEmpty();
    bool isFull();
    void push(signed char value);
    signed char pop();
    signed char peek(); //get top element
    int getTop() const; //get top index
};

/*=========================================================
Implementation: Stack
Author: QAISARAH SHAMSUL AZRAN
=========================================================*/

Stack::Stack()
{
    top = -1;
}

bool Stack::isEmpty()
{
    if(top == -1)
    {
        return true;    //return true if empty
    }
    else
    {
        return false;   //return false if not empty
    }
}

bool Stack::isFull()
{
    if(top == 7)
    {
        return true;    //return true if full aka there are 8 elements in the stack
    }
    else
    {
        return false;   //return false if not full
    }
}

void Stack::push(signed char value)
{
    if(isFull())
    {
        cout << "Stack Overflow" << endl;   //give error message if stack is full
        return;
    }

    top++;  //increase top index value
    stack[top] = value; //assign given value to top of stack
}

signed char Stack::pop()
{
    if(isEmpty())
    {
        cout << "Stack Underflow" << endl;  //give error message if stack is empty
        return 0;
    }

    signed char value;
    value = stack[top]; //assign the top most element of the stack to variable value

    top--;  //decrease the top index to 'remove' the element from stack

    return value;   //return the value variable which is the top most element that was 'removed'
}

signed char Stack::peek()
{
    if(isEmpty())
    {
        cout << "Stack is empty\n"; //give error message if stack is empty
        return 0;
    }

    return stack[top];  //return the top most element
}

int Stack::getTop() const
{
    return top; //return the top element's index
}

/*=========================================================
Class: Register
Author: QAISARAH SHAMSUL AZRAN
=========================================================*/
class Register
{
private:
    signed char value;

public:
    Register();
    void setValue(signed char v);
    signed char getValue() const;
};

/*=========================================================
Implementation: Register
Author: QAISARAH SHAMSUL AZRAN
=========================================================*/
Register::Register()
{
    value = 0;  //all register value initially 0
}

void Register::setValue(signed char v)
{
    value = v;  //set value of the chosen register to the given value
}

signed char Register::getValue() const
{
    return value;   //get the value associated with the chosen register
}

/*=========================================================
Class: GeneralRegister
Author: QAISARAH SHAMSUL AZRAN
=========================================================*/
class GeneralRegister : public Register
{
private:
    string name;

public:
    GeneralRegister();
    GeneralRegister(string n);
    string getName() const;
};

/*=========================================================
Implementation: GeneralRegister
Author: QAISARAH SHAMSUL AZRAN
=========================================================*/
GeneralRegister::GeneralRegister()
{
    name = "";  //default constructor to initialize register name to ""
}

GeneralRegister::GeneralRegister(string n)
{
    name = n;   //constructor to set register name to given name
}

string GeneralRegister::getName() const
{
    return name;    //return the name of the register aka R0-R7
}


/*=========================================================
Class: FlagRegister
Author: QAISARAH SHAMSUL AZRAN
=========================================================*/
class FlagRegister
{
private:
    bool OF;
    bool UF;
    bool CF;
    bool ZF;

public:
    FlagRegister();
    void reset();
    void setOverflow(bool x);
    void setUnderflow(bool x);
    void setCarry(bool x);
    void setZero(bool x);
    bool getOverflow() const;
    bool getUnderflow() const;
    bool getCarry() const;
    bool getZero() const;
};

/*=========================================================
Implementation: FlagRegister
Author: QAISARAH SHAMSUL AZRAN
=========================================================*/
FlagRegister::FlagRegister()
{
    reset();    //whenever the flag register is initialized, all flags are reset
}

void FlagRegister::reset()
{
    OF = false; //all flags are reset aka all flags are set to false/0
    UF = false;
    CF = false;
    ZF = false;
}

void FlagRegister::setOverflow(bool x)
{
    OF = x; //set the overflow flag to the given boolean value
}

void FlagRegister::setUnderflow(bool x)
{
    UF = x; //set the underflow flag to the given boolean value
}

void FlagRegister::setCarry(bool x)
{
    CF = x; //set the carry flag to the given boolean value
}

void FlagRegister::setZero(bool x)
{
    ZF = x; //set the zero flag to the given boolean value
}

bool FlagRegister::getOverflow() const
{
    return OF;  //return the overflow flag boolean value
}

bool FlagRegister::getUnderflow() const
{
    return UF;  //return the underflow flag boolean value
}

bool FlagRegister::getCarry() const
{
    return CF;  //return the carry flag boolean value
}

bool FlagRegister::getZero() const
{
    return ZF;  //return the zero flag boolean value
}

/*=========================================================
Class: Memory
Author: QAISARAH SHAMSUL AZRAN
=========================================================*/
class Memory
{
private:
    signed char mem[64];    //an array with 64 space is created

public:
    Memory();
    void clear();
    signed char read(int address);
    void write(int address, signed char value);
};

/*=========================================================
Implementation: Memory
Author: QAISARAH SHAMSUL AZRAN
=========================================================*/
Memory::Memory()
{
    clear();    //whenever the memory is initialized, it is cleared
}

void Memory::clear()
{
    for(int i = 0; i < 64; i++)
    {
        mem[i] = 0; //set to 0 for all memory address
    }
}

signed char Memory::read(int address)
{
    if(address < 0 || address >= 64)
    {
        cout << "Invalid memory address\n"; //give error message if the given memory address is < 0 or >= 64 which is the max number of addresses
        return 0;
    }
    return mem[address];    //return the value at the address aka index
}

void Memory::write(int address, signed char value)
{
    if(address < 0 || address >= 64)
    {
        cout << "Invalid memory address\n"; //give error message if the given memory address is < 0 or >= 64 which is the max number of addresses
        return;
    }
    mem[address] = value;   //assign the given value to the address aka the index position in the array
}


/*=========================================================
Class: CPU
Author: QAISARAH SHAMSUL AZRAN
=========================================================*/

class CPU
{
private:
    GeneralRegister registers[8];   //initialize 8 register objects through an array
    Memory memory;
    Stack stack;
    FlagRegister flags;
    unsigned char PC;

public:
    CPU();

    void setRegisterValue(int index, signed char value);
    signed char getRegisterValue(int index) const;

    void writeMemory(int address, signed char value);
    signed char readMemory(int address);

    void pushStack(signed char value);
    signed char popStack();

    void setZeroFlag(bool value);
    bool getZeroFlag() const;

    void setCarryFlag(bool value);
    bool getCarryFlag() const;

    void setOverflowFlag(bool value);
    bool getOverflowFlag() const;

    void setUnderflowFlag(bool value);
    bool getUnderflowFlag() const;

    int getPC() const;
    void incrementPC();

    int getSI() const;

    void reset();
};

/*=========================================================
Implementation: CPU
Author: QAISARAH SHAMSUL AZRAN
=========================================================*/

CPU::CPU()
{
    registers[0] = GeneralRegister("R0");   //initialize each register with the given name from R0-R7
    registers[1] = GeneralRegister("R1");
    registers[2] = GeneralRegister("R2");
    registers[3] = GeneralRegister("R3");
    registers[4] = GeneralRegister("R4");
    registers[5] = GeneralRegister("R5");
    registers[6] = GeneralRegister("R6");
    registers[7] = GeneralRegister("R7");

    PC = 0; //set Program Counter to 0
}

void CPU::setRegisterValue(int index, signed char value)
{
    if(index < 0 || index >= 8)
    {
        cout<<"Invalid register\n";   //if the index value given is more than 8 which is the max number of registers or less than 0, give error message
        return;
    }
    registers[index].setValue(value);   //use member function inherited from Register class to set value of the chosen register at the given index
}

signed char CPU::getRegisterValue(int index) const
{
    if(index < 0 || index >= 8)
    {
        cout<<"Invalid register\n";   //if the index value given is more than 8 which is the max number of registers or less than 0, give error message
        return 0;
    }
    return registers[index].getValue(); //use the member function inherited from Register class to get value stored in the chosen register
}

void CPU::writeMemory(int address, signed char value)
{
    if(address < 0 || address >= 64)
    {
        cout << "Invalid memory address\n"; //give error message if the given memory address is < 0 or >= 64 which is the max number of addresses
        return;
    }
    memory.write(address, value);   //write the value given into the address chosen using the member function from Memory class
}

signed char CPU::readMemory(int address)
{
    if(address < 0 || address >= 64)
    {
        cout << "Invalid memory address\n"; //give error message if the given memory address is < 0 or >= 64 which is the max number of addresses
        return 0;
    }
    return memory.read(address);    //get the value stored in the address given using member function from Memory class
}

void CPU::pushStack(signed char value)
{
    stack.push(value);  //use member function of Stack class (stack operation) to push given value into stack
}

signed char CPU::popStack()
{
    return stack.pop();  //use member function of Stack class (stack operation) to pop the last value from stack
}

void CPU::setZeroFlag(bool value)
{
    flags.setZero(value);   //use member function from Flag Register class to set value for zero flag
}

bool CPU::getZeroFlag() const
{
    return flags.getZero();   //use member function from Flag Register class to get value for zero flag
}

void CPU::setCarryFlag(bool value)
{
    flags.setCarry(value);   //use member function from Flag Register class to set value for carry flag
}

bool CPU::getCarryFlag() const
{
    return flags.getCarry();   //use member function from Flag Register class to get value for carry flag
}

void CPU::setOverflowFlag(bool value)
{
    flags.setOverflow(value);   //use member function from Flag Register class to set value for overflow flag
}

bool CPU::getOverflowFlag() const
{
    return flags.getOverflow();   //use member function from Flag Register class to get value for overflow flag
}

void CPU::setUnderflowFlag(bool value)
{
    flags.setUnderflow(value);   //use member function from Flag Register class to set value for underflow flag
}

bool CPU::getUnderflowFlag() const
{
    return flags.getUnderflow();   //use member function from Flag Register class to get value for underflow flag
}

int CPU::getPC() const
{
    return PC;  //return the current program counter
}

void CPU::incrementPC()
{
    PC++;   //increment program counter by 1
}

int CPU::getSI() const
{
    return stack.getTop() + 1;  //get stack index by getting the top index of stack using member function from Stack class and +1
}

void CPU::reset()
{
    PC = 0; //PC set to 0
    memory.clear(); //memory cleared by setting all to 0
    flags.reset();  //all flags reset aka set to false/0

    while(!stack.isEmpty())
    {
        stack.pop();    //while stack is not empty, keep popping elements until stack is empty
    }

    for(int i = 0; i < 8; i++)
    {
        registers[i].setValue(0);   //set to 0 for all register values
    }
}

/*=========================================================
Class: Instruction (Abstract base class)
Author: Aleessa Batrisyia Binti Azwan 
=========================================================*/

class Instruction{
    protected:
        int getRegisterIndex(string reg); // get the register index without the R
        bool isRegister(string text); // verify if operand is a register
        bool isMemoryRegister(string text); // verify if operand is memory register
        bool isMemoryAddress(string text); // verify if operand is memory address
        void updateFlags(CPU& cpu, int result); // update flags for when destination register is modified


    public:
        virtual void execute(CPU& cpu) = 0;
        virtual ~Instruction(){}
};

/*=========================================================
Implementation: Instruction
Author: Aleessa Batrisyia Binti Azwan
=========================================================*/

int Instruction::getRegisterIndex(string reg){
    return reg[1] - '0';
}

bool Instruction::isRegister(string text){
    return text.length() == 2 &&
        text[0] == 'R' &&
        text[1] >= '0' &&
        text[1] <= '7';
}

bool Instruction::isMemoryRegister(string text){
    return text.length() == 4 &&
           text[0] == '[' &&
           text[1] == 'R' &&
           text[2] >= '0' &&
           text[2] <= '7' &&
           text[3] == ']';
}


bool Instruction::isMemoryAddress(string text){
    return text.length() >= 3 &&
           text[0] == '[' &&
           text[text.length() - 1] == ']';
}

void Instruction::updateFlags(CPU& cpu, int result) {
    cpu.setOverflowFlag(result > 127);
    cpu.setUnderflowFlag(result < -128);
    cpu.setCarryFlag(result > 255 || result < -255);
    cpu.setZeroFlag(result == 0);
}

/*=========================================================
Class: ArithmeticInstruction
Author: Aleessa Batrisyia Binti Azwan 
=========================================================*/

class ArithmeticInstruction : public Instruction{
    private:
        string opcode;
        string operand1;
        string operand2;  
        
        int getValue(CPU& cpu, string operand); // get the value stored in register if operand is a register

    public:
        ArithmeticInstruction(string op, string op1, string op2 = " ");
        void execute(CPU& cpu);

};

/*=========================================================
Implementation: ArithmeticInstruction
Author: Aleessa Batrisyia Binti Azwan (Person 3)
=========================================================*/

// Constructor
ArithmeticInstruction::ArithmeticInstruction(string op, string op1, string op2){
    opcode = op;
    operand1 = op1;
    operand2 = op2;
}

// Get value stored in register if operand is a register
int ArithmeticInstruction::getValue(CPU& cpu, string operand){
    if (isRegister(operand)){
        return cpu.getRegisterValue(getRegisterIndex(operand));
    }

    return atoi(operand.c_str());
}

// Execute arithmetic operation based on the opcode
void ArithmeticInstruction::execute(CPU& cpu){
    int dest = getRegisterIndex(operand1); // get register index at operand1
    int left = cpu.getRegisterValue(dest); // assign value stored at dest 
    int result = left; // initial result state 

    if (opcode == "ADD"){
        result = left + getValue(cpu, operand2); // add left with value stored at operand2
    }
    else if(opcode == "SUB"){
        result = left - getValue(cpu, operand2); // subtract left with value stored at operand2
    }
    else if(opcode == "MUL"){
        result = left * getValue(cpu, operand2); //multiply left with value stored at operand2
    }
    else if(opcode == "DIV"){
        int right = getValue(cpu, operand2); // get value at operand2 
        
        // if value at operand2 is 0 then output error division by zero
        if(right == 0){
            cout << "Error: Division by zero." << endl;
            return;
        }
        result = left / right;
    }
    else if(opcode == "INC"){
        result = left + 1; 
    }
    else if(opcode == "DEC"){
        result = left - 1;
    }
    
    updateFlags(cpu, result);
    cpu.setRegisterValue(dest, result);
}

/*=========================================================
Class: IOInstruction
Author: Aleessa Batrisyia Binti Azwan 
=========================================================*/

class IOInstruction : public Instruction{
    private:
        string opcode;
        string operand1;

    public:
        IOInstruction(string op, string op1);
        void execute(CPU& cpu);
};

/*=========================================================
Implementation: IOInstruction
Author: Aleessa Batrisyia Binti Azwan 
=========================================================*/

// Constructor
IOInstruction::IOInstruction(string op, string op1){
    opcode = op;
    operand1 = op1;
}

void IOInstruction::execute(CPU& cpu){
    int reg = getRegisterIndex(operand1);

    if(opcode == "INPUT"){
        int value;

        cout << "? ";
        cin >> value; // Get value from user

        updateFlags(cpu, value); // update flags because register is modified
        cpu.setRegisterValue(reg, value);
    }
    else if(opcode == "DISPLAY"){
        cout << cpu.getRegisterValue(reg) << endl; // display value at register
    }
}

/*=========================================================
Class: MovInstruction
Author: Aleessa Batrisyia Binti Azwan 
=========================================================*/

class MovInstruction : public Instruction{
    private:
        string opcode;
        string operand1;
        string operand2;

        int getAddressFromBracket(string text);

    public:
        MovInstruction(string op, string op1, string op2);
        void execute(CPU& cpu);

};

/*=========================================================
Implementation: MovInstruction
Author: Aleessa Batrisyia Binti Azwan 
=========================================================*/

// Constructor
MovInstruction::MovInstruction(string op, string op1, string op2){
    opcode = op;
    operand1 = op1;
    operand2 = op2;
}

// Get the address stored in register with []
int MovInstruction::getAddressFromBracket(string text){
    string numberText = text.substr(1, text.length() - 2);
    return atoi(numberText.c_str());
}

void MovInstruction::execute(CPU& cpu){
    int dest = getRegisterIndex(operand1); 
    int value = 0;

    if(isRegister(operand2)){
        int src = getRegisterIndex(operand2);
        value = cpu.getRegisterValue(src); // get the value stored at operand2
    }
    else if(isMemoryRegister(operand2)){
        int srcReg = operand2[2] - '0';
        int address = cpu.getRegisterValue(srcReg);
        value = cpu.readMemory(address);
    }
    else if(isMemoryAddress(operand2)){
        int address = getAddressFromBracket(operand2);
        value = cpu.readMemory(address);
    }
    else{
        value = atoi(operand2.c_str());
    }

    updateFlags(cpu, value);
    cpu.setRegisterValue(dest, value);
}

/*=========================================================
Class: MemoryInstruction
Author: Aleessa Batrisyia Binti Azwan 
=========================================================*/

class MemoryInstruction : public Instruction{
    private:
        string opcode;
        string operand1;
        string operand2;
    
        int getAddress(CPU& cpu, string operand);

    public:
        MemoryInstruction(string op, string op1, string op2);
        void execute(CPU& cpu);
};

/*=========================================================
Implementation: MemoryInstruction
Author: Aleessa Batrisyia Binti Azwan 
=========================================================*/

MemoryInstruction::MemoryInstruction(string op, string op1, string op2){
    opcode = op;
    operand1 = op1;
    operand2 = op2;
}

int MemoryInstruction::getAddress(CPU& cpu, string operand){
    if(isMemoryRegister(operand)){
        int reg = operand[2] - '0';
        return cpu.getRegisterValue(reg);
    }

    if(isMemoryAddress(operand)){
        string numberText = operand.substr(1, operand.length() - 2);
        return atoi(numberText.c_str());
    }

    return atoi(operand.c_str());
}

void MemoryInstruction::execute(CPU& cpu){
    if(opcode == "LOAD"){
        int dest = getRegisterIndex(operand1);
        int address = getAddress(cpu, operand2);

        int value = cpu.readMemory(address);

        cpu.setRegisterValue(dest, value);
        updateFlags(cpu, value);
    }
    else if(opcode == "STORE"){
        int value;
        int address;

        if(isRegister(operand1)){
            value = cpu.getRegisterValue(getRegisterIndex(operand1));
            address = getAddress(cpu, operand2);
        }

        cpu.writeMemory(address, value);
    }
}

/*=========================================================
Class: StackInstruction
Author: Aleessa Batrisyia Binti Azwan 
=========================================================*/

class StackInstruction : public Instruction{
    private:
        string opcode;
        string operand1;
    
    public:
        StackInstruction(string op, string op1);
        void execute(CPU& cpu);
};

/*=========================================================
Implementation: StackInstruction
Author: Aleessa Batrisyia Binti Azwan 
=========================================================*/

StackInstruction::StackInstruction(string op, string op1){
    opcode = op;
    operand1 = op1;
}

void StackInstruction::execute(CPU& cpu){
    int reg = getRegisterIndex(operand1);

    if(opcode == "PUSH"){
        int value = cpu.getRegisterValue(reg);
        cpu.pushStack(value);
    }
    else if(opcode == "POP"){
        int value = cpu.popStack();
        cpu.setRegisterValue(reg, value);
        updateFlags(cpu, value);
    }
}

/*=========================================================
Class: ShiftInstruction
Author: NUR DAMIA' BATRISYIA
=========================================================*/

class ShiftInstruction : public Instruction
{
private:
    string operation; // SHL, SHR, ROL, ROR
    string destination; // Register name (R0...)
    string count;

public:
    ShiftInstruction(string op, string dest, string c);

    void execute(CPU& cpu) override;
};

/*=========================================================
Implementation: ShiftInstruction
Author: NUR DAMIA' BATRISYIA
=========================================================*/
ShiftInstruction::ShiftInstruction(string op, string dest, string c) : operation(op), destination(dest), count(c) {}

void ShiftInstruction::execute(CPU& cpu)
{
    int index = getRegisterIndex(destination);
    signed char regValue = cpu.getRegisterValue(index);
    unsigned char bits = static_cast<unsigned char>(regValue);

    int shift = atoi(count.c_str()) % 8; // Ensure the shift count is within 0-7

    if (operation == "SHL")
    {
        bits <<= shift;
    }
    else if(operation == "SHR")
    {
        bits >>= shift;
    }
    else if(operation == "ROL")
    {
        bits = (bits << shift) | (bits >> (8 - shift));
    }
    else if(operation == "ROR")
    {
        bits = (bits >> shift) | (bits << (8 - shift));
    }

        regValue = static_cast<signed char>(bits);

    cpu.setZeroFlag(regValue == 0);
    cpu.setRegisterValue(index, regValue);

    cpu.incrementPC();
}

/*=========================================================
Class: InstructionFactory
Author: Aleessa Batrisyia Binti Azwan 
=========================================================*/

class InstructionFactory {
public:
    static Instruction* createInstruction(string tokens[], int tokenCount);
};

/*=========================================================
Implementation: InstructionFactory
Author: Aleessa Batrisyia Binti Azwan 
=========================================================*/

Instruction* InstructionFactory::createInstruction(string tokens[], int tokenCount) {
    string op = tokens[0];
    if (op == "ADD" || op == "SUB" || op == "MUL" || op == "DIV") {
        if (tokenCount != 3) { return 0; }
        return new ArithmeticInstruction(op, tokens[1], tokens[2]);
    }
    if (op == "INC" || op == "DEC") {
        if (tokenCount != 2) { return 0; }
        return new ArithmeticInstruction(op, tokens[1]);
    }
    if (op == "INPUT" || op == "DISPLAY") {
        if (tokenCount != 2) { return 0; }
        return new IOInstruction(op, tokens[1]);
    }
    if (op == "MOV") {
        if (tokenCount != 3) { return 0; }
        return new MovInstruction(op, tokens[1], tokens[2]);
    }
    if (op == "PUSH" || op == "POP") {
        if (tokenCount != 2) { return 0; }
        return new StackInstruction(op, tokens[1]);
    }
    if (op == "LOAD" || op == "STORE") {
        if (tokenCount != 3) { return 0; }
        return new MemoryInstruction(op, tokens[1], tokens[2]);
    }
    if (op == "SHL" || op == "SHR" || op == "ROL" || op == "ROR") {
        if (tokenCount != 3) { return 0; }

        return new ShiftInstruction(op, tokens[1], tokens[2]);
    }
    return 0;
}

/*=========================================================
Class: DumpState
Author: NUR DAMIA' BATRISYIA
=========================================================*/
class DumpState
{
public:
    static void display(CPU& cpu);
};

/*=========================================================
Implementation: DumpState
Author: NUR DAMIA' BATRISYIA
=========================================================*/
void DumpState::display(CPU& cpu)
{
cout << "#Begin#" << endl;

    cout << "#Registers#";

    for(int i = 0; i < 8; i++)
    {
        cout << setw(4)
             << setfill('0')
             << (int)cpu.getRegisterValue(i)
             << "#";
    }

    cout << endl;

    cout << "#Flags#";
    cout << "OF#" << cpu.getOverflowFlag() << "#";
    cout << "UF#" << cpu.getUnderflowFlag() << "#";
    cout << "CF#" << cpu.getCarryFlag() << "#";
    cout << "ZF#" << cpu.getZeroFlag() << "#";

    cout << endl;

    cout << "#PC#";
    cout << setw(4)
         << setfill('0')
         << cpu.getPC()
         << "#";

    cout << endl;

    cout << "#Memory#" << endl;

    for(int i = 0; i < 64; i++)
    {
        cout << "#"
             << setw(4)
             << setfill('0')
             << (int)cpu.readMemory(i);

        if((i + 1) % 8 == 0)
        {
            cout << "#" << endl;
        }
    }

    cout << "#End#" << endl;
}

/*=========================================================
Class: Runner
Author: NUR ALYA IMAN
=========================================================*/
class Runner
{
private:
    Vector<string> programLines;

    bool isValidInstruction(const string& instruction);
    bool isValidRegister(const string& reg);

public:
    Runner();

    bool loadASMFile(const string& filename);

    void tokenize(const string& line,
                  string tokens[],
                  int& tokenCount);

    bool validateSyntax(string tokens[],
                        int tokenCount);

    void processProgram(CPU& cpu);

    int getLineCount();
    string getLine(int index);
};

/*=========================================================
Implementation: Runner
Author: NUR ALYA IMAN
=========================================================*/
Runner::Runner() {
}


bool Runner::loadASMFile(const string& filename) {
    ifstream inputFile(filename.c_str());

    if (!inputFile) {
        cout << "Error: Cannot open ASM file." << endl;
        return false;
    }

    string line;

    while (getline(inputFile, line)) {
        if (line != "") {
            programLines.push_back(line);
        }
    }

    inputFile.close();
    return true;
}


void Runner::tokenize(const string& line, string tokens[], int& tokenCount) {
    tokenCount = 0;
    string word = "";

    for (int i = 0; i < line.length(); i++) {
        char ch = line[i];

        if (ch == ' ' || ch == ',' || ch == '\t') {
            if (word != "") {
                tokens[tokenCount] = word;
                tokenCount++;
                word = "";
            }
        } else {
            word += ch;
        }
    }

    if (word != "") {
        tokens[tokenCount] = word;
        tokenCount++;
    }
}


bool Runner::isValidInstruction(const string& instruction) {
    return instruction == "MOV" ||
           instruction == "ADD" ||
           instruction == "SUB" ||
           instruction == "MUL" ||
           instruction == "DIV" ||
           instruction == "INC" ||
           instruction == "DEC" ||
           instruction == "INPUT" ||
           instruction == "DISPLAY" ||
           instruction == "LOAD" ||
           instruction == "STORE" ||
           instruction == "PUSH" ||
           instruction == "POP" ||
           instruction == "SHL" ||
           instruction == "SHR" ||
           instruction == "ROL" ||
           instruction == "ROR";
}


bool Runner::isValidRegister(const string& reg) {
    return reg.length() == 2 &&
           reg[0] == 'R' &&
           reg[1] >= '0' &&
           reg[1] <= '7';
}


bool Runner::validateSyntax(string tokens[], int tokenCount) {
    if (tokenCount == 0) {
        return false;
    }

    string op = tokens[0];

    if (!isValidInstruction(op)) {
        cout << "Syntax Error: Invalid instruction " << op << endl;
        return false;
    }

    if (op == "INC" || op == "DEC" ||
        op == "INPUT" || op == "DISPLAY" ||
        op == "PUSH" || op == "POP") {

        if (tokenCount != 2) {
            cout << "Syntax Error: " << op << " requires 1 operand." << endl;
            return false;
        }
    } else {
        if (tokenCount != 3) {
            cout << "Syntax Error: " << op << " requires 2 operands." << endl;
            return false;
        }
    }

    if (op == "ADD" || op == "SUB" ||
        op == "MUL" || op == "DIV") {

        if (!isValidRegister(tokens[1]) || !isValidRegister(tokens[2])) {
            cout << "Syntax Error: Invalid register in " << op << endl;
            return false;
        }
    }

    if (op == "INC" || op == "DEC" ||
        op == "INPUT" || op == "DISPLAY" ||
        op == "PUSH" || op == "POP" ||
        op == "SHL" || op == "SHR" ||
        op == "ROL" || op == "ROR") {

        if (!isValidRegister(tokens[1])) {
            cout << "Syntax Error: Invalid register in " << op << endl;
            return false;
        }
    }

    return true;
}


void Runner::processProgram(CPU& cpu) {
    for (int i = 0; i < programLines.size(); i++) {
        string tokens[5];
        int tokenCount = 0;

        tokenize(programLines[i], tokens, tokenCount);

        if (!validateSyntax(tokens, tokenCount)) {
            cout << "Error found in line " << i + 1 << endl;
            return;
        }

        Instruction* instruction =
            InstructionFactory::createInstruction(tokens, tokenCount);

        if (instruction == 0) {
            cout << "Error: Cannot create instruction at line "
                 << i + 1 << endl;
            return;
        }

        instruction->execute(cpu);

        if (tokens[0] != "SHL" &&
            tokens[0] != "SHR" &&
            tokens[0] != "ROL" &&
            tokens[0] != "ROR") {
            cpu.incrementPC();
        }

        delete instruction;

        DumpState dump;
        dump.display(cpu);
    }
}


int Runner::getLineCount() {
    return programLines.size();
}


string Runner::getLine(int index) {
    if (index >= 0 && index < programLines.size()) {
        return programLines[index];
    }

    return "";
}

/*=========================================================
Implementation: main 
Author: ALEESSA BATRISYIA 
=========================================================*/
int main(int argc, char* argv[])
{
    if (argc < 2) {
        cout << "Usage: vm <filename.asm>" << endl;
        return 1;
    }

    CPU cpu;
    Runner runner;

    bool loaded = runner.loadASMFile(argv[1]);

    if (!loaded) {
        return 1;
    }

    runner.processProgram(cpu);
    
    DumpState dump;
    dump.display(cpu);

    cout << "Program executed successfully." << endl;


    return 0;
}
