class String {
    friend String operator+(String s1, char* s2);
    friend String operator+(String s1, String s2);

	public:
		//Constructeurs
		String(const char* s); //constructeur à partir de c-string

		String (const String& copy); //constructeur par copie

		//Accesseurs
		unsigned long capacity();
		long max_size();

		//Modificateurs
		void reserve(int n);
		const char* c_str() const;

		//Méthodes
		bool empty();
		int length();
	
		
		//Opérateurs
		String& operator=(const char* s2);
		String& operator=(const String s);

		//Suppresseur
		~String();

	protected:
		//Attributs
		int length_;
		char* tab_;
		unsigned long capacity_;
		const static long max_size_=1000000;
};
