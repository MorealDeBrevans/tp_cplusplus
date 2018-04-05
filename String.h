class String {
	public:
		//Constructeurs
		String(char* s); //constructeur à partir de c-string
		
		String (String copy); //constructeur par copie
		
		//Accesseurs
		unsigned long capacity();
		
		//Modificateurs
		void reserve(int n);	

		//Méthodes
		bool empty();

		//Méthodes 
		int length();
		int max_Size();
		void resize(int n); 
		void resize(int n, char c);
		
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
