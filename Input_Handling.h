#ifndef INPUT_HANDLING_H
#define INPUT_HANDLING_H

class Invalid_Input
{
	public:
		Invalid_Input(char* in_ptr):msg_ptr(in_ptr){}
		const char* const msg_ptr;
	private:
		Invalid_Input(); //prevents default constructor from being called
};

#endif