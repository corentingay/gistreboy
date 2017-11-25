#include <memory.hpp>
#include <vector>
#include <utility>

Memory::Memory(Processor& proc) : processor(proc),
	       cartridge({std::make_pair(0x00, 0x7FFF),
			  std::make_pair(0xA000, 0xBFFF)}),

	       video(proc, {std::make_pair(0xFF40, 0xFF4B),
			    std::make_pair(0x8000, 0xFE9F),
			    std::make_pair(0xFE00, 0xFE9F)})
{
	memory.fill(0);
}


void Memory::change_game(uint8_t *cart)
{
	cartridge.change_game(cart);
	_ready = true;
}

bool Memory::is_ready()
{
	return _ready;
}

void Memory::reset()
{
	_ready = false;
}

uint8_t Memory::read(uint16_t address)
{
	if (cartridge.isInRange(address))
		return cartridge.read(address);
	else if (video.isInRange(address))
		return video.read(address);
	else
		return memory[address];
}

void Memory::write(uint16_t address, uint8_t byte)
{
	if (cartridge.isInRange(address))
		cartridge.write(address, byte);
	else if (video.isInRange(address))
		video.write(address, byte);
	else
		memory[address] = byte;
}

Video& Memory::get_video()
{
	return video;
}

Cartridge& Memory::get_cartridge()
{
	return cartridge;
}
