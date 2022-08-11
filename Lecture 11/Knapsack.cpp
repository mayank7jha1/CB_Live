//Function to return max value that can be put in knapsack of capacity W.
int knapSack(int W, int wt[], int val[], int n)
{
	if (n == 0 or W == 0) {
		return 0;
	}

	//Current item ka weight max weight se jada hojaaye:
	if (wt[n - 1] > W) {
		return 0 + knapSack(W, wt, val, n - 1);
	}


	//Lets say we Take the current item:
	int Option1 = val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1);

	//Lets not take the item:
	int Option2 = 0 + knapSack(W, wt, val, n - 1);

	return max(Option1, Option2);
}
/*
n = 3;
n = 0;
wt[] = {10, 200, 300};
val[] = {1, 2, 3};

W = 250;

Can the bag ever carry item number 3 ?*/
