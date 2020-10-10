#include <any>
#include <vector>

using namespace std;

// Tip: You can use el.type() == typeid(vector<any>) to check whether an item is
// a list or an integer.
int productSum(vector<any> array, int depth);
int productSum(vector<any> array) {
  // Write your code here.
  return productSum(array, 1);
}

int productSum(vector<any> array, int depth)
{
	int sum = 0;
	for (auto item : array)
	{
		if (item.type() == typeid(vector<any>))
		{
			sum += productSum(any_cast<vector<any>>(item), depth + 1);
		}
		else
		{
			sum += any_cast<int>(item);
		}
	}
	return sum * depth;
}

