
/// Decorator
class coffee_decorator : public coffee_component {
public:
  coffee_decorator(coffee_component *pbase):m_pcomp(pbase){}

 protected:
  coffee_component *m_pcomp;

}; 
