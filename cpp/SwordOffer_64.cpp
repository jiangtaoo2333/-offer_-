class Temp {

private:
	static unsigned int N;
	static unsigned int SUM;

public:
	Temp(){
		N++;
		SUM += N;
	}
	static void Reset() {
		N = 0;
		SUM = 0;
	}

	static unsigned int GetSum() {
		return SUM;
	}
};

unsigned int Sum(int n) {

	Temp::Reset();

	Temp* a = new Temp[n];
	delete []a;
	a = nullptr;
	return Temp::GetSum();
}