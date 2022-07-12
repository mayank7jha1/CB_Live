#include<bits/stdc++.h>//Slow 
using namespace std;
#define int long long
#define val 1000000100000


int Hamburgers(char* in, int nb, int ns, int nc, int pb, int ps, int pc, int r) {
	int s = 0;//Minimum Number of Hamburgers that i can make.
	int e = val;//Maximum Number of Hamburgers that i can make.

	int ans = -1;//-1 can never be the answer so if after the loop is over
	//and ans is still -1 then that means ki have not found our answer.

	//For calculating the amount or the frequency of individual item.
	int cb = 0, cs = 0, cc = 0;

	//AT MAX there can be only 100 computations because the maximum
	//string length can be only 100 given in the question.
	for (int i = 0; in[i] != '\0'; i++) {
		if (in[i] == 'B') cb++;
		else if (in[i] == 'S') cs++;
		else cc++;
	}

	while (s <= e) {
		int mid = (s + e) / 2;

		//Can i Make mid number of Hamburgers?
		//So basically to answer the above question what i need is
		//How much money do i require to make mid number of hamburgers.


		//What if nb is greater than cb*mid what this means is to make
		//mid amount of hamburgers you already have items more than required
		//in this scenario the answer will be negative which we cannot have.

		int total_price_required_for_bread = ((cb * mid - nb) * pb) < 0 ? 0 : ((cb * mid - nb) * pb);
		int total_price_required_for_sausage = ((cs * mid - ns) * ps) < 0 ? 0 : ((cs * mid - ns) * ps);
		int total_price_required_for_cheese = ((cc * mid - nc) * pc) < 0 ? 0 : ((cc * mid - nc) * pc);

		int total_money_required_to_make_mid_number_of_Hamburgers = total_price_required_for_cheese +
		        total_price_required_for_bread + total_price_required_for_sausage;

		if (total_money_required_to_make_mid_number_of_Hamburgers == r) {
			//This means you can make mid number of hamburgers with the given amount of money.
			return mid;
		} else if (total_money_required_to_make_mid_number_of_Hamburgers < r) {
			s = mid + 1;
			ans = mid;
		} else {
			e = mid - 1;
		}
	}
	return ans;
}


int32_t main() {
	char in[1000];
	cin >> in;
	int nb, ns, nc, pb, ps, pc, r;
	cin >> nb >> ns >> nc;
	cin >> pb >> ps >> pc;
	cin >> r;
	cout << Hamburgers(in, nb, ns, nc, pb, ps, pc, r) << endl;

}