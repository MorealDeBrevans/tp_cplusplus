class String {
    friend String operator+(String s1, const char* s2);
    friend String operator+(String s1, String s2);
    friend String operator+(const char * c, String s1);

	public:
		//Constructeurs
		String(const char* s); //constructeur à partir de c-string

		String (const String& copy); //constructeur par copie

		//Accesseurs
		unsigned long capacity();
		long max_size();

		unsigned long length();
		
		unsigned long size(); //synonym of length, so the same method is used
		
    const char* c_str() const;	
        
		//Modificateurs
		void reserve(unsigned long n);
		void clear();

		//Méthodes
		bool empty();
	
		void resize(int n); 
		void resize(int n, char c);

		//Opérateurs
		String& operator=(const char* s);
		String& operator=(const String s); 
		String& operator=(const char c);

		//Destructeur
		~String();

	protected:
		//Attributs
		unsigned long length_;
		char* tab_;
		unsigned long capacity_;
		const static unsigned long max_size_=1000000;
};
