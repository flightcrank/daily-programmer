
/*

Description:

Today's challenge we explore some curiosity in rolling a 6 sided di. I often wonder about the outcomes of a rolling a simple 6 side di in a game or even simulating the roll on a computer.

I could roll a 6 side di and record the results. This can be time consuming, tedious and I think it is something a computer can do very well.

So what I want to do is simulate rolling a 6 sided di in 6 groups and record how often each number 1-6 comes up. Then print out a fancy chart comparing the data. What I want to see is if I roll the 6 sided di more often does the results flatten out in distribution of the results or is it very chaotic and have spikes in what numbers can come up.

So roll a D6 10, 100, 1000, 10000, 100000, 1000000 times and each time record how often a 1-6 comes up and produce a chart of % of each outcome.

Run the program one time or several times and decide for yourself. Does the results flatten out over time? Is it always flat? Spikes can occur?
Input:

None.
Output:

Show a nicely formatted chart showing the groups of rolls and the percentages of results coming up for human analysis.
example:

# of Rolls 1s     2s     3s     4s     5s     6s       
====================================================
10         18.10% 19.20% 18.23% 20.21% 22.98% 23.20%
100        18.10% 19.20% 18.23% 20.21% 22.98% 23.20%
1000       18.10% 19.20% 18.23% 20.21% 22.98% 23.20%
10000      18.10% 19.20% 18.23% 20.21% 22.98% 23.20%
100000     18.10% 19.20% 18.23% 20.21% 22.98% 23.20%
1000000    18.10% 19.20% 18.23% 20.21% 22.98% 23.20%

notes on example output:

    Yes in the example the percentages don't add up to 100% but your results should
    Yes I used the same percentages as examples for each outcome. Results will vary.
    Your choice on how many places past the decimal you wish to show. I picked 2. if you want to show less/more go for it.

Code Submission + Conclusion:

Do not just post your code. Also post your conclusion based on the simulation output. Have fun and enjoy not having to tally 1 million rolls by hand.

*/

#include <stdio.h>
#include <stdlib.h>

#define SIDES 6 //sides of dice

int roll(int n);
void print_result(int n);
int results[SIDES];

int main() {
	
	printf("\n# of rolls %d % 8d % 8d % 8d % 8d % 8d\n", 1, 2, 3, 4, 5, 6);
	puts("==============================================================");
	
	roll(10);
	print_result(10);

	roll(100);
	print_result(100);
	
	roll(1000);
	print_result(1000);
	
	roll(10000);
	print_result(10000);
	
	roll(100000);
	print_result(100000);
	
	roll(1000000);
	print_result(1000000);
	
	return 0;
}

void print_result(int times) {

	printf("%10d % 5.2f % 8.2f % 8.2f % 8.2f % 8.2f % 8.2f\n", times,
						((float)results[0] / times) * 100, 
						((float)results[1] / times) * 100, 
						((float)results[2] / times) * 100, 
						((float)results[3] / times) * 100, 
						((float)results[4] / times) * 100, 
						((float)results[5] / times) * 100); 
}

int roll(int times) {
	
	int i;
	
	//make sure results are set to 0
	for(i = 0; i < SIDES; i++) {
	
		results[i] = 0;
	}
	
	//roll dice n times
	for (i = 0; i < times; i++) {
		
		int side = rand() % 6 + 1;
		
		switch (side) {
			
			case 1:
				results[0]++;
			break;
			case 2:
				results[1]++;
			break;
			case 3:
				results[2]++;
			break;
			case 4:
				results[3]++;
			break;
			case 5:
				results[4]++;
			break;
			case 6:
				results[5]++;
			break;
			default:
				puts("error: number is not in range 1 - 6");
				return 1;
		}
	}
	
	return 0;
}
