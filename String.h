class String {
	public:
		//Constructeurs
		
		//Accesseurs
		
		//Modificateurs
		
		//Méthodes
		~String();

		size_t capacity();
		
		bool empty();
		
		friend operator=(String s1, char* s2);
	protected:
		//Attributs
		int length_;
		char* tab_;
		int capacity_;
};
