class Abstract_Container {
public:
	virtual double& operator[](int) = 0;    // pure virtual function
	virtual int size() const = 0;           // const member function (§4.2.1)
	virtual ~Abstract_Container() {}        // destructor (§4.2.2)
};