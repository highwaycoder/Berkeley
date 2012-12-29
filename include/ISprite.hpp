#ifndef ITILE_HPP
#define ITILE_HPP

#include "enums.hpp"

namespace berk
{
	class ITile
	{
	public:
		ITile(ETileType t) : type(t) {}
		virtual void render(void) = 0;
	protected:
		ETileType type;
	};
};

#endif
