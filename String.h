class String {
	public:
		//Constructeurs
		
		//Accesseurs
		unsigned long capacity();
		
		//Modificateurs
		void reserve(int n);
		
		//Méthodes
		bool empty();
		
		//Opérateurs
		void operator=(char* s2);
		friend operator+(String s1, String s2);
				
		//Suppresseur
		~String();

	protected:
		//Attributs
		int length_;
		char* tab_;
		int capacity_;
};
