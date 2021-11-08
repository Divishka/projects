#ifndef ARRAY_HPP
#define ARRAY_HPP

template <class T>
class Array {

private:

	size_t length;
	T* arr;

public:

	Array();
	Array(size_t n);
	Array(Array<T> const& copy);
	virtual ~Array();

	class OutOfLimitsException: public std::exception {
		virtual const char* what() const throw();
	};

	Array& operator= (Array<T> const& copy);
	T& operator[](const size_t index);
	const T& operator[] (size_t index) const;

	size_t size() const;

};

#endif
