template<typename T>
class Template_Vector {
private:
	T* elem;   // elem points to an array of sz elements of type T
	int sz;
public:
	explicit Template_Vector(int s);        // constructor: establish invariant, acquire resources
	/*Template_Vector(T* elem);*/ // we can't know the size of the array pointer
	Template_Vector(std::initializer_list<T> elem); //?? how to make it work check for release resources, how we have to do it???
	~Template_Vector() { delete[] elem; }   // destructor: release resources

	// ... copy and move operations ...

	T& operator[](int i);
	const T& operator[](int i) const;
	int size() const { return sz; }
};

// Why templates need to be implemented in teh header file??
//The reason is templates are too hi - level constructs for standard compiling and 
//linking tools.
//One of goals in the design of C++ was backward compatibility.link.exe can only link 
//"machine code", but templates are "half-generated code".So you need implement all of 
//your template methods in header files.Compilers will find them and compile.

template<typename T>
Template_Vector<T>::Template_Vector(int s)
{
	if (s<0)
		throw Negative_size{};
	elem = new T[s];
	sz   = s;
}

// we can't know the size of the array pointer
//template<typename T>
//Template_Vector<T>::Template_Vector(T* elem)
//	: elem{ elem }, sz{ elem->size() }
//{ }

template<typename T>
Template_Vector<T>::Template_Vector(std::initializer_list<T> list)
	: sz{ list.size() }
{ 
	sz                = list.size();
	T* at             = new T[sz];
	auto checkedArray = stdext::checked_array_iterator<T*>(at, sz);
	std::move(list.begin(), list.end(), checkedArray);
	elem = &at[0];
}

template<typename T>
T& Template_Vector<T>::operator[](int i)
{
	if (i<0 || size() <= i)
		throw std::out_of_range{ "Vector::operator[]" };
	return elem[i];
}

template<typename T>
const T& Template_Vector<T>::operator[](int i) const
{
	if (i<0 || size() <= i)
		throw std::out_of_range{ "Vector::operator[]" };
	return elem[i];
}


template<typename T>
T* begin(Template_Vector<T>& x);

template<typename T>
T* end(Template_Vector<T>& x);

template<typename T>
T* begin(Template_Vector<T>& x)
{
	return x.size() ? &x[0] : nullptr;      // pointer to first element or nullptr
}

template<typename T>
T* end(Template_Vector<T>& x)
{
	return begin(x) + x.size();     // pointer to one-past-last element
}