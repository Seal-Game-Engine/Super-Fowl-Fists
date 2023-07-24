#pragma once
#include <memory>

class IClonable{
public:
	std::shared_ptr<IClonable> Clone() const { return std::shared_ptr<IClonable>(this->_Clone()); };
private:
	virtual IClonable* _Clone() const = 0;
};

