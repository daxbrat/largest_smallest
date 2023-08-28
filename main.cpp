#include "std_lib_facilities.h"

int main()
{
	double num{};
	string unit{};
	double total{};
	double largest{};
	double smallest{};
	vector <double> nums {};
	cout << "Enter a number and unit: \n";
	while (cin >> num >> unit) {
		if (unit != "cm" && unit != "m" && unit != "in" && unit != "ft") {  // reject wrong unit
			cout << "Not a valid unit. Please enter the number and unit again." << endl;
			continue;
		}
		else { // convert cm to m
			if (unit == "cm") {
				num /= 100;
				unit = "m";
			}
			else { // convert in to m
				if (unit == "in") {
					num *= .0254;
					unit = "m";
				}
				else { // convert ft to m
					if (unit == "ft") {
						num *= .0254 * 12;
						unit = "m";
					}
				}
			}

		}
		total += num;
		nums.push_back(num);
		sort(nums);
		cout << "Vector so far: ";
		for (double i : nums) {
			cout << i << " ";
		}
		cout << '\n';
		if (num == nums[nums.size() - 1]) {
			cout << num << unit << " is the largest so far\n";
			largest = num;
		}
		else {
			if (num == nums[0]) {
				cout << num << unit << " is the smallest so far\n";
				smallest = num;
			}
		}
		cout << "Total so far: " << total << '\n';
	}
	return 0;
}
