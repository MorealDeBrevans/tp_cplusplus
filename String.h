class String {
	public:
		//Constructeurs
		String(char* s); //constructeur à partir de c-string
=======
		String (String copy); //constructeur par copie
		
		//Accesseurs
		
		//Modificateurs
		
		//Méthodes 
		int length();
		int max_Size();
		void resize(int n);
		
	protected:
		//Attributs
		int length_;
		char* tab_;
};
