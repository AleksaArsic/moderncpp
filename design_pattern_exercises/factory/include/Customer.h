#pragma once

namespace Customer
{
	class Customer final
	{
	public:
		Customer()
		{
			id++;
		}

		// ... additional non-implemented functionality

		[[nodiscard]] unsigned int getId() const
		{
			return id;
		}

		// ... additional non-implemented functionality
	private:
		static unsigned int id;
	};
}