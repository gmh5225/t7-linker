#include "STDInclude.hpp"

namespace Utils
{
	CSV::Row::Row(std::string row)
	{
		std::regex rowRegex("(((\\\\,)|[^,])*)(,|$)");

		for (std::sregex_iterator i(row.begin(), row.end(), rowRegex); i != std::sregex_iterator(); ++i)
		{
			std::smatch match = *i;
			Utils::String col(match[1].str());
			this->data.push_back(col.replaceAll("\\,", ","));
		}

		this->data.pop_back();
	}

	size_t CSV::Row::getColumnCount()
	{
		return this->data.size();
	}

	std::string CSV::Row::getColumn(int col)
	{
		return this->data[col];
	}

	CSV::CSV(std::string data)
	{
		std::regex lineRegex("(.*)((\\r?\\n)|$)");

		for (std::sregex_iterator i(data.begin(), data.end(), lineRegex); i != std::sregex_iterator(); ++i)
		{
			std::smatch match = *i;
			auto line = match[1].str();
			if (!line.empty() && line[0] != '#')
			{
				this->rows.push_back(Row(line));
			}
		}
	}

	size_t CSV::getRowCount()
	{
		return this->rows.size();
	}

	CSV::Row& CSV::getRow(int row)
	{
		return this->rows[row];
	}

	std::string CSV::getElement(int row, int col)
	{
		return this->getRow(row).getColumn(col);
	}
}
