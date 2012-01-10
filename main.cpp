#include <stdio.h>
#include <vector>
#include <time.h>

using namespace std;

enum Prize { goat, porshe, opened };

const int ndoors = 300;
const int nporshe = 10;

int main ()
{
	srand((unsigned)time(0));
	
	vector<Prize> doors;
	doors.resize(ndoors);

	int trys = 0;

	while (1) {

		trys++;

		for (int i=0; i<ndoors; i++)
		{
			doors[i] = goat;
		};

		for (int i=0; i<nporshe; i++)
		{
			doors[rand()%ndoors] = porshe;
		};

		// Choose door
		int chosen = rand()%ndoors;

		// Open other door
		int rnd = rand()%ndoors;
		do {
			doors[rnd] = opened;
			break;
		} while (doors[rnd] != porshe && rnd != chosen);

		bool change = (bool)rand()%2;
		if ( change )
		{
			int rnd;
			do {
				rnd = rand()%ndoors;
			} while (doors[rnd] != opened && chosen != rnd );
			chosen = rnd;
		};

		// Open and win (or lose)
		printf ("#%i.\tYou choose #%i door and %s! Mind was %s.\nAgain?(y,n)\n",trys, chosen+1 , doors[chosen]==porshe ? "WIN" : "LOOSE", change ? "changed" : "not changed");
		printf ("Prize was at: [");
		for ( int i=0; i<ndoors; i++ )
		{
			if (doors[i] == porshe) printf ("%i, ", i);
		};
		printf ("] door(s).\n\n");
		if ( doors[chosen]!=porshe ) continue;
		else if ( (char)getchar() == 'n' ) break;
		
		trys = 0;
		system("cls");

	};

	system("pause");

	return 0;
};