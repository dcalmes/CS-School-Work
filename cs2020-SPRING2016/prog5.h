/////////////////////////////////////////////////////////////////////////
//	Program			5
//	Description:	This program will have a user input a temperature.
//					It will take this temperature and print out if
//						certain substances will freeze or boil at
//						the temperature that was input.
//	Programmer:		Douglas G Calmes
//	Class:			CS 2020, Spring 2016
/////////////////////////////////////////////////////////////////////////

#ifndef TEMPERATURE_H
#define TEMPERATURE_H

class Temperature
{
private:
	int temperature;

public:

	//	Accessors
	int getTemp() const 
	{ 
		return temperature;
	}									
	void oxygenFreezes() const;
	void oxygenBoils() const;
	void ethylFreezes() const;
	void ethylBoils() const;
	void waterFreezes() const;
	void waterBoils() const;
	void nitrogenFreezes() const;
	void nitrogenBoils() const;

	//	Constructors
	Temperature() 
	{
		temperature = 0; 
	}
	Temperature(int temp)
	{
		temperature = temp;
	}
	
	//	Mutators
	void setTemp(int tempSet) 
	{
		temperature = tempSet; 
	}
};

#endif;