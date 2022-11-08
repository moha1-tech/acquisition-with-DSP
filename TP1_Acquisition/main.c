#include "dsk6713_aic23.h"

Uint32 input_sample();
void output_sample(int out_data);
void comm_intr();

#define N 64
Uint32 fs = DSK6713_AIC23_FREQ_32KHZ;
short XnBuffer[N];
short Xn;
Uint16 i=0 ;
interrupt void c_int11()
{
	Xn = input_sample();
	XnBuffer[i] = Xn ;
	i = (i + 1) % N;
	output_sample(Xn);
	return;
}

main()
{
	comm_intr();
	while(1);
}
