/*
 * File : processor.cpp
 *
 * File created by : Arnaud Bastie
 * File was created at : 29/08/2017
 */

#include <processor.hpp>
#include <instruction.hpp>
#include <interrupthandler.hpp>
#include <memory.hpp>

/* PUBLIC METHODS */

void Processor::enableIME()
{
	_handler->enableIME();
}

void Processor::disableIME()
{
	_handler->disableIME();
}


void Processor::enableIMEDelay()
{
	_handler->enableIMEDelay();
}

int Processor::step()
{
	if (!_handler || !_mem)
		throw std::runtime_error("Memory or handler pointer not set.");
	if (halted || stopped) {
		if (halted) {
			// Check that the selected interrupt is triggered
			std::bitset<8> IF = 0; /*_m->getInterruptFlags();*/
			std::bitset<8> IE = 0; /*_m->getInterruptEnable();*/
			std::bitset<8> res = IF & IE;
			int inter = res.any();
			if (inter) {

				//The handler will not do the interrupt
				// if IME is not set.

				(void)_handler->doInterrupt();
				halted = false;
				return 4;
			}
			else
				return 0;
		}
		else {
			// Check if any selected button is pressed
			uint8_t joypad_status = 0; _mem->read(0xFF00);

			// Get bits [0-3] check that a button is pressed
			int pressed = ~joypad_status & 0x0F;

			// Get bits [4-5], check that joypad is enabled
			int selected = ~joypad_status & 0x30;

			if (pressed && selected) {
				// We end STOP mode.
				stopped = false;
				return 4;
			}
		}
		return 0;
	}
	_fetchNextInstruction();
	return _execCurrentInstruction();
}


void Processor::HALT()
{
	halted = false;
}

void Processor::STOP()
{
	stopped = true;
}

/* PRIVATE METHODS */

int Processor::_execCurrentInstruction()
{
	currentInstruction->exec(this);
	return currentInstruction->nbCycles();
}

void Processor::_fetchNextInstruction()
{
	uint16_t opcode = _mem->read(PC.value);
	if (!iset.isValidOpCode(opcode)) {
		// We try the to get the instruction over 16bits
		opcode = (opcode << 8) | _mem->read(++PC.value);
		if (!iset.isValidOpCode(opcode)) {
			// We dont really care if the program crashes,
			// the rom is bad or there is a bug.
			_BUG("Unknown opcode : ", opcode);
			throw std::runtime_error("Unknown opcode, check the logs");
		}
	}
	// Opcode is valid
	currentInstruction = iset.getInstruction(opcode);
	InstructionArgs args;

	// We get each argument for the instruction, according to its length.
	for (int i = 0; i < currentInstruction->nbArgs() ; ++i) {

		uint16_t arg = 0;

		int size = 0;
		for (; size < currentInstruction->argSize(i); ++size)
			arg = (arg << 8) | _mem->read(++PC.value);

		addShort(args, arg);
	}
	currentInstruction->setArgs(args);
}

uint8_t Processor::_read(uint16_t address)
{
	return _mem->read(address);
}

void Processor::_write(uint8_t value, uint16_t address)
{
	_mem->write(value, address);
}

void Processor::_BUG(std::string str, int value) const
{
	//We dump everything.
	std::cout << str << "0x" << std::hex << value << std::dec << std::endl;
	std::cout << "REGISTERS" << std::endl;
	std::cout << "Register A : 0x"  << std::hex << A.value << std::endl;
	std::cout << "Register B : 0x"  << std::hex << B.value << std::endl;
	std::cout << "Register C : 0x"  << std::hex << C.value << std::endl;
	std::cout << "Register D : 0x"  << std::hex << D.value << std::endl;
	std::cout << "Register E : 0x"  << std::hex << E.value << std::endl;
	std::cout << "Register H : 0x"  << std::hex << H.value << std::endl;
	std::cout << "Register L : 0x"  << std::hex << L.value << std::endl;
	std::cout << "Program Counter : 0x"  << std::hex << PC.value << std::endl;
	std::cout << "Stack Pointer : 0x"  << std::hex << SP.value << std::endl;
}
