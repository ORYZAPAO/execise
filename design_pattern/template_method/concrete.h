class ConcreteClass : public AbstractClass{ 
 public:
  virtual void open(){
    std::cout << "<<";
  }

  virtual void print(){
    std::cout << "A";
  }

  virtual void close(){
    std::cout << ">>";
  }
  
};
