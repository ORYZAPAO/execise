// Component
class coffee_component{
  virtual std::string getName()=0;
  virtual int         cost()=0;
};


class coffee_decorator : public coffee_component{
private:
  coffee_component *m_pbase;
public:
  coffee_decorator(coffee_component *pbase):m_pbase(pbase){}
}; 
