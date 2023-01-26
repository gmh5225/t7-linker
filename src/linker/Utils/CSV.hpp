#pragma once

#ifndef STD_INCLUDED
#error "Missing standard header"
#endif

namespace Utils
{
	class CSV
	{
	public:
		class Row
		{
		public:
			Row(std::string row);

			size_t getColumnCount();
			std::string getColumn(int col);

		private:
			std::vector<std::string> data;
		};

		CSV(std::string data);

		size_t getRowCount();
		Row& getRow(int row);
		std::string getElement(int row, int col);

	private:
		std::vector<Row> rows;
	};
}
