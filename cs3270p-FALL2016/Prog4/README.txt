Program4_Calmes                                                                                       11/2/16

This program will grab in the input file “system.txt” and take the first two inputs and set them to the number 
or resources and number of programs in the system.

The program will then execute a series of for loops to set the allocation, claim, available resource matrices 
based on how many resources are in each matrix.  This will allow the program to read in the proper amount of 
resources for each matrix.

	*These matrices are dynamically allocated in the main*

		resource = new int[MAX_SIZE];
		allocationMatrix = new int[MAX_SIZE];
		claimMatrix = new int[MAX_SIZE];
		availableMatrix = new int[MAX_SIZE];
		needMatrix = new int[MAX_SIZE];

	*Determines the matrix resource size by getting the product of the number of process and number of 
	 resources in each process*

			// Read in the Matrices
			int matrixResource = numProcesses * numResources;

			for (int i = 0; i < matrixResource; i++)
			{
				inputFile >> allocationMatrix[i];
			}
			for (int i = 0; i < matrixResource; i++)
			{
				inputFile >> claimMatrix[i];
			}
			for (int i = 0; i < matrixResource; i++)
			{
				inputFile >> availableMatrix[i];
			}

After reading in the date, the program will ask the user wither they would like to end the program.

	If they would like to, it lets them know to enter yes to end the program

If they user determines they would not like to end the program, they will then be asked if they would like to 
add/change a system process

	If they select yes, they will be prompted to ender the process they would like to update.

	The user then enters that said process and will then be asked to enter the resources that the process has.

		The program will ask them this a series of times, determined by a for loop for how many resources 
		was read in from the input file.

			int changeResource;
			changeResource = numResources * newProcess;

			for (int i = 0; i < numResources; i++)
			{
				cout << "Enter Resource " << i << " : ";
				cin >> newResource;
				if (newResource < allocationMatrix[changeResource])
				{
					cout << "Sorry, we cannot process that request." << endl;
					cout << "Enter New Resource " << i << " (greater than " << allocationMatrix[changeResource] << "): ";
					cin >> newResource;
				}
				else
					claimMatrix[changeResource] = newResource;
					changeResource++;
			}

After the user and input their changes to a process, the program will then edit the arrays accordingly to make sure 
the updated process is now in the array.

The program will then be able to determine the need matrix because we not have our claim and allocation matrices set.  
The dynamically allocated need matrix will be filled in by setting its current position in the array as the difference 
between the claim and allocation resources in its respected position.

	for (int i = 0; i < matrixResource; i++)
	{
		needMatrix[i] = claimMatrix[i] - allocationMatrix[i];
	}

After all of the matrices are set, the program will then call the printState function in order to print out the systems 
initial state.

After the initial state is printed out the program will then go through the banker’s algorithm in order to figure out 
if the system is in a safe state or not a safe state

	After checking to see if there are enough available resources for each process, a new system state will be 
	printed out to show the current state of the system.

	The program will continue to do this until either all the programs have ran through successfully (safe) or if it 
	determines there are not enough resources to fulfill every process need (unsafe)

Finally, the program will check to see if every position in the need matrix is set to 0 to determine if the system state 
is safe or not safe.

If every element in the array is set to 0 it is determined that the system is safe and the program will print out that 
it is safe.

If every element in the array is not set to 0, that means that there were not enough resources available and the system 
is not safe.

	//	Determine if the state is safe or not
	int safeCheck = 0;

	for (int i = 0; i < matrixResource; i++)
	{
		if (needMatrix[i] == 0)
		{
			safeCheck++;
		}
	}

	if (safeCheck == matrixResource)
	{
		cout << "///////////////////////////////////" << endl;
		cout << "//This System is in a Safe State!//" << endl;
		cout << "///////////////////////////////////" << endl;
	}
	else
	{
		cout << "///////////////////////////////////////" << endl;
		cout << "//This System is in a Not Safe State!//" << endl;
		cout << "///////////////////////////////////////" << endl;
	}
