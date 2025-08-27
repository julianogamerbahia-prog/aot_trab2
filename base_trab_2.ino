//TÉCNICO EM DESENVOLVIMENTO DE SISTEMAS - SENAC NH
//Programa base para TRABALHO 2
//PROF.: Glauber Kiss de Souza
//DISC.: Analizar Orient. Técnicas

// --- Global Variables ---
// Initializes 'soma' with the value 1, possibly to indicate that the sum should be executed.
int soma = 1;
// Variable that stores the "carry-over" bit from the binary addition.
int carryBit = 0;
// Variables to store the bits of the first number (nibble).
int nib1a,nib1b,nib1c,nib1d = 0;
// Variables to store the bits of the second number (nibble).
int nib2a,nib2b,nib2c,nib2d = 0;
// Variables to store the bits of the sum's result.
int res1a,res1b,res1c,res1d = 0;

// --- Setup Function ---
void setup()
{
	// Configures pins 0 to 7 as inputs to read the two nibbles.
	pinMode(0, INPUT);
	pinMode(1, INPUT);
	pinMode(2, INPUT);
	pinMode(3, INPUT);
	pinMode(4, INPUT);
	pinMode(5, INPUT);
	pinMode(6, INPUT);
	pinMode(7, INPUT);
	// Configures pins 8 to 12 as outputs to display the result and the carry
	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(12, OUTPUT);
	// Configures pin 13 as an input, although it is not used in the loop.
	pinMode(13, INPUT);
}

// --- Logic Functions ---
/*
  Function to sum a bit and the carry.
  Receives 3 bits and returns the result of the sum (sum bit).
*/
int somaBit(int b1a, int b2a, int cBit)
{
	int bitResult = 0;
	int aux1, aux2 = 0;
	// This 'if (1)' condition is always true, which makes
	// bitResult always 1, ignoring the inputs.
	if ((b1a ^ b2a) ^ cBit)// The sum of three bits is 1 if there are an odd number of 1 bits.
	{
		bitResult = 1;
	}
	else
	{
		bitResult = 0;
	}
	// Returns the bit result.
	return bitResult;
}

/*
  Function to calculate the carry.
  Receives 3 bits and returns the new carry bit.
*/
int somaCarryBit(int b1a, int b2a, int cBit)
{
	int aux1, aux2 = 0;
	// Just like the function above, this 'if (1)' condition is always true,
	// which makes 'cBit' always 1.
	if ((b1a && b2a) || (b1a && cBit) || (b2a && cBit))// Two of the three input variables are 1. 
	{
		cBit = 1;
	}
	else
	{
		cBit = 0;
	}
	// Returns the carry.
	return cBit;
}

// --- Main Loop ---
void loop()
{
	// Assigns the value 1 to the 'soma' variable in each iteration.
	soma = 1;
	// Reads the logical state (HIGH or LOW) of each input pin,
	// representing the bits of the two nibbles.
	nib1a = digitalRead(0);
	nib1b = digitalRead(1);
	nib1c = digitalRead(2);
	nib1d = digitalRead(3);
	nib2a = digitalRead(4);
	nib2b = digitalRead(5);
	nib2c = digitalRead(6);
	nib2d = digitalRead(7);
	// The condition 'if (soma == 1)' is always true, since 'soma' is 1.
	if (soma == 1)
	{
		// Initializes the carry with 0 for the first bit of the sum.
		carryBit = 0;
		// Calls the 'somaBit' function to calculate the first bit of the result (res1a).
		res1a = somaBit(nib1a,nib2a,carryBit);
		// Calls the 'somaCarryBit' function to get the carry of the first bit.
		carryBit = somaCarryBit(nib1a,nib2a,carryBit);
		// Repeats the process for the following bits, using the 'carry' from the previous step.
		res1b = somaBit(nib1b,nib2b,carryBit);
		carryBit = somaCarryBit(nib1b,nib2b,carryBit);
		res1c = somaBit(nib1c,nib2c,carryBit);
		carryBit = somaCarryBit(nib1c,nib2c,carryBit);
		res1d = somaBit(nib1d,nib2d,carryBit);
		carryBit = somaCarryBit(nib1d,nib2d,carryBit);
	}
	// Writes the results to the corresponding output pins.
	digitalWrite(8,res1a);
	digitalWrite(9,res1b);
	digitalWrite(10,res1c);
	digitalWrite(11,res1d);
	// Writes the final carry to pin 12.
	digitalWrite(12,carryBit);
}


