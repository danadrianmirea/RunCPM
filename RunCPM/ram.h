/* see main.c for definition */

uint8 _RamRead(uint16 address)
{
	return(RAM[address]);
}

void _RamWrite(uint16 address, uint8 value)
{
	RAM[address] = value;
}

void _RamFill(uint16 address, int size, uint8 value)
{
	while (size--)
	{
		_RamWrite(address++, value);
	}
}

void _RamCopy(uint16 source, int size, uint16 destination)
{
	while (size--)
	{
		_RamWrite(destination++, _RamRead(source++));
	}
}

void _RamWrite16(uint16 address, uint16 value)
{
	// Z80 is a "little indian" (8 bit era joke)
	_RamWrite(address, value & 0xff);
	_RamWrite(address + 1, (value >> 8) & 0xff);
}

