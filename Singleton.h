#include <string>

class Singleton {
public:
	static Singleton* Instance();
	void writeToLogFile();
	void Ivedimas ( int A[][10], int & n, int & m);
	void Spausdinti ( int A[][10], int n, int m);
	int geriauisais( int A[][10], int n, int m);
	int Neigiami (int A[][10], int n, int m);

private:
	Singleton() {};  // Private so that it can  not be called
	Singleton(Singleton const&) {};             // copy constructor is private
	Singleton& operator=(Singleton const&) {};  // assignment operator is private
	static Singleton* m_pInstance;
};