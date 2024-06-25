#ifndef CHARACTERS
#define CHARACTERS

#include <stdint.h>

#define GET_POSITION(a) ((a>>2)&0x03)
#define GET_BLOCKING(a) ((a>>1)&0x01)
#define GET_ATTACK(a) ((a)&0x01)

#define AI_PROCESS_I 4
#define P_PROCESS_I 3

typedef struct Entity
{
	int8_t HP;
	int8_t Stamina;

	uint8_t Actions;  // XXXX RR P A

}ent;

inline int Evaluate_Position(ent* T1, ent* T2) {

	uint8_t T1P = GET_POSITION(T1->Actions);
	uint8_t T2P = GET_POSITION(T2->Actions);


	return (T1P == T2P);
}

inline int Recover(ent* T) {
	if (T->Stamina < 100) {
		T->Stamina++;
	}
	return 0;
}

inline int Attack(ent* Attacker, ent* Target, uint8_t DMG) {

	if (Attacker->Stamina >= 20) {

		if (Evaluate_Position(Attacker,Target) == 1) {

			if (GET_BLOCKING(Target->Actions) == 1) {

				Attacker->Stamina = 20;

				Target->Actions &= 0xFD;
			}

			else
			{
				Target->HP -= DMG;
			}		

		}

		Attacker->Stamina -= 20;
	}

	Attacker->Actions &= 0xFE;

	return 0;
}

inline int Block(ent* User) {
	
	if (User->Stamina - 10 >= 0) {
		User->Stamina -= 10;
	}	
	User->Actions &= 0xFD;

	return 0;
}


inline int ProcessActions(ent* User, ent* Target) {

	if (GET_ATTACK(User->Actions) == 1) {
		Attack(User,Target,5);
	}
	if (GET_BLOCKING(User->Actions)==1) {
		Block(User);
	}

	return 0;
}

inline int AI_Handler(ent* User, ent* Target) {

	uint8_t A_P = GET_POSITION(User->Actions);
	uint8_t B_P = GET_POSITION(Target->Actions);

	if (B_P > A_P) {
		A_P++;
		User->Actions = (A_P << 2) | ((User->Actions) & 0x02);
	}
	else if (B_P < A_P) {
		A_P--;
		User->Actions = (A_P << 2) | ((User->Actions) & 0x02);
	}

	else
	{
		
		if (User->Stamina > 50) {
			User->Actions |= 0x02;
		}

		else if (User->Stamina > 20) {
			User->Actions |= 0x01;
		}

		


	}




	return 0;
}



#endif // !CHARACTERS