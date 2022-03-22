#include <string>
#include <vector>
#include "Direction.hpp"

using namespace std;
using ariel::Direction;

namespace ariel{
	class Line{
		private:
		char arr[100];
		public:
		Line();
	};
	class Page{
		private:
		int amount;
		vector<Line> lines();
		public:
		Page();
	};
	class Notebook {
		private:
		vector<Page> pages();
		public:
		Notebook();
		void write(int page, int line, int column, Direction, string str);
		string read(int page, int line, int column, Direction, int num);
		void erase(int page, int line, int column, Direction, int num);
		void show(int page); 
	};
};