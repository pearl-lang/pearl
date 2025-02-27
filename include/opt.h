enum SetOpt {
	Help,
	Shell,
	Compile,
	Version,
};

struct Option {
	bool status; 
	bool verbose;
	enum SetOpt curropt;
	const char *file; // This will be dynamic, but for now single file can be loaded.
	const char *options[]; // This is for store the options.
};
