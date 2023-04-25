#pragma once
#include <memory>

class IClonable{
public:
	std::shared_ptr<IClonable> Clone() const { return std::shared_ptr<IClonable>(this->Clone_impl()); };
private:
	virtual IClonable* Clone_impl() const = 0;
};

