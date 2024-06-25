#ifndef INPUT
#define INPUT


enum Input {

	BTN_X ='W',
	BTN_Y ='S',
	BTN_A ='A',
	BTN_B ='D'

};

uint8_t ProcessPlayerAction(uint8_t currentA, uint8_t Action) {
	uint8_t out = currentA;

	uint8_t pos = (out >> 2) & 0x03;

	out &= 0x03;

	switch (Action)
	{

	case BTN_X: out = currentA | 0x01  ; break;
	case BTN_Y: out = currentA | 0x02; break;
	case BTN_A: pos--; break;
	case BTN_B: pos++; break;



	default:
		break;
	}

	pos &= 0x03;

	out |= (pos << 2);


	return out;
}


#endif // !INPUT

