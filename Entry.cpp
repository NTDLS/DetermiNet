///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "Cases.h"

#include "CNeuralNetwork/CNeuralNetwork.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

double TestAccuracy(CNeuralNetwork *nn)
{
	double casesTested = 0;
	double casesCorrect = 0;
	double accuracy = 0;

	for(int i = 0; i < TEST_CASES; i++)
	{
		double result[1];
		nn->Compute(Cases[i], result);
		//printf("Case[%d], Result: %.6f (%d=%.0f)\n", i, result[0], (result[0] >= 0.5), ExpectedResult[i]);
		casesCorrect += ((int)(result[0] >= 0.5)) == (int)(ExpectedResult[i]);
		casesTested++;
	}

	accuracy = (casesCorrect / casesTested) * 100.0;

	printf("Tested %.0f cases, with %.0f correct predictions (%.2f%% Accuracy).\n", casesTested, casesCorrect, accuracy);

	return accuracy;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void main()
{
	CNeuralNetwork nn(0.01, 2, 6, 16, 1);

	for(int iTrainIteration = 0; iTrainIteration < TRAIN_ITERATIONS; iTrainIteration++)
	{
		for(int i = 0; i < TEST_CASES; i++)
		{
			double expectedResult[1];
			expectedResult[0] = ExpectedResult[i];
			nn.Train(Cases[i], expectedResult);
		}

		if(iTrainIteration == 0 || (iTrainIteration % 100) == 0)
		{
			TestAccuracy(&nn);
		}
	}

	system("Pause");
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
