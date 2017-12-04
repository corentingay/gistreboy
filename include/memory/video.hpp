#pragma once

#include <processor.hpp>
#include <memoryobject.hpp>

#include <array>
#include <vector>
#include <string>

class Video : public MemoryObject {

public :

 	Video(Processor& proc,
		std::vector<std::pair<uint16_t, uint16_t>> range);

	uint8_t read(uint16_t address);
	void write(uint8_t byte, uint16_t address);

	void dma_transfer(uint16_t beg_src, uint16_t end_src);

	//FIXME
	// If we try to access potentially protected memory,
	// we return _accessible otherwise we return true.
	bool can_read(uint16_t address);
	bool can_write(uint8_t byte, uint16_t address);

	// Change permission on protected memory:
 	// VRAM (0x8000-0x9FFF) and OAM (0xFE00-0xFE9F)
	void set_VRAM_accessible(bool accessible);
	void set_OAM_accessible(bool accessible);

	uint8_t get_lcd_control();
	uint8_t get_lcd_status();
	uint8_t get_scrolly();
	uint8_t get_scrollx();
	uint8_t get_ly();
	uint8_t get_lyc();
	uint8_t get_wy();
	uint8_t get_wx(); /* actually wx - 7 */
	uint8_t get_bgp();
	uint8_t get_obp0();
	uint8_t get_obp1();

private:
	bool _is_OAM(uint16_t address);
	bool _is_VRAM(uint16_t address);
private :

	Processor &_proc;
	std::array<uint8_t, 0x10000> video_memory;
	bool _OAM_accessible = false;
	bool _VRAM_accessible = true;
};
