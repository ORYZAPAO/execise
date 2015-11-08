class Singleton {
private:
	Singleton() = default;				 //コンストラクタを private に置く
	~Singleton() = default;				 //デストラクタを private に置く
public:
	Singleton(const Singleton&) = delete;	         //コピーコンストラクタを delete 指定
	Singleton& operator=(const Singleton&) = delete; //コピー代入演算子も delete 指定
	Singleton(Singleton&&) = delete;		 //ムーブコンストラクタを delete 指定
	Singleton& operator=(Singleton&&) = delete;	 //ムーブ代入演算子も delete 指定

	static Singleton& getInstance(){
		static Singleton inst;			// privateなコンストラクタを呼び出す
		return inst;
	}

	const char* getString(){
		return "Hello world!";		//Singleton::getInstance().getString(); と記述
	}
};
