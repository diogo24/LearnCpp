class Class_W {
public:
	Class_W(const Class_W&) = delete;             // no copy operations
	Class_W& operator=(const Class_W&) = delete;

	Class_W(Class_W&&) = delete;                  // no move operations
	Class_W& operator=(Class_W&&) = delete;

	~Class_W();
	// ...
};