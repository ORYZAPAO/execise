// Component
class coffee_component{
 public:
  virtual std::string getName()=0;
  virtual int         cost()=0;
};

/// Decorator
class coffee_decorator : public coffee_component {
public:
  coffee_decorator(coffee_component *pbase):m_pcomp(pbase){}

 protected:
  coffee_component *m_pcomp;

}; 
