#include "Renderer.h"
#include "Characters.h"
#include "Serial.h"
#include "Input.h"


int main()
{

	int8_t frame = 0;

	ent* Entities[2];

	HANDLE P = Open();

	uint8_t Data;

	for (size_t i = 0; i < 2; i++)
	{
		Entities[i] = malloc(sizeof(ent));

		if (Entities[i] != NULL) {
			Entities[i]->HP = 100;
			Entities[i]->Stamina = 100;
			Entities[i]->Actions = 0;
		}
	}

	for(frame;frame<60;frame++)
	{
		if (frame == 0) {
			for (size_t i = 0; i < 2; i++)
			{
				if (Entities[i] != NULL) {
					Entities[i]->Actions &= 0xFC;
				}
			}
		}

		Data = 0;
		Data = ReadSingleByte(P);
		
		if (Entities[0] != NULL) {
			Entities[0]->Actions = ProcessPlayerAction(Entities[0]->Actions, Data);
		}

		if ((frame % AI_PROCESS_I) == 0) {

			ProcessActions(Entities[1], Entities[0]);
			AI_Handler(Entities[1], Entities[0]);
		}

		if ((frame % P_PROCESS_I) == 0) {

			ProcessActions(Entities[0], Entities[1]);
		}

		for (size_t i = 0; i < 2; i++)
		{
			Recover(Entities[i]);
		}
	
		Render(Entities[0], Entities[1]);

		if (Entities[0] != NULL && Entities[1] !=NULL) {

			if (Entities[0]->HP <= 0 || Entities[1]->HP <= 0) {
				break;
			}

		}

		if (frame == 59) {
			frame = -1;
		}

	}  

	printf("END");

	for (size_t i = 0; i < 2; i++)
	{
		if (Entities[i] != NULL) {
			free(Entities[i]);
		}
	}

	return 0;
}

