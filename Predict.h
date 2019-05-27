
class Predict {
	public:
		void Start() { // initialize
			predictValue();
		}
	
	protected:
		double prevCost[11]; // cost before
		double newCost; // predicted cost

	private:
		void predictValue() { // predict value
			cout << "Enter the anual cost of the prodoct for the past 10 periods (day, week, month, year)" << endl;
			for(int i = 0; i < 10; i++) {
				cin >> prevCost[i]; // take the value from user
			}
			mathValue(); // do math

			cout << "Your product should cost about $" << newCost << " next period";
		}

		double mathValue() { // Do the math
			double cost = 0;
			double rChange[10];
			double pCost = 1;
			double averageChange;
			for(int j = 0; j <= 10; j++) {
				cost = prevCost[j];
				if (j <= 2) {
					pCost = prevCost[j - 1];
					rChange[j] = cost - pCost;
				}
			}

			for(int a = 0; a <= 10; a++) {
				averageChange = rChange[a] - rChange[a + 1];
				if (a <= 2) {
					averageChange /= 10;
				}
			}

			cost /= averageChange;
			
			prevCost[10] = cost;

			pCost = 1;

			for(int j = 0; j <= 10; j++) {
				cost += prevCost[j];
				if (j <= 2) {
					pCost = prevCost[j - 1];
					rChange[j] = cost - pCost;
				}
			}

			for(int a = 0; a <= 10; a++) {
				averageChange = rChange[a] - rChange[a + 1];
				if (a <= 2) {
					averageChange /= 11;
				}
			}

			cost = averageChange;

			newCost = abs(cost / (prevCost[10] / pCost));
			

			return abs(newCost);
		}

};
