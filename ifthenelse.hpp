#ifndef __IFTHENELSE_HPP
#define __IFTHENELSE_HPP

namespace oryzalib{

template<bool bl, class Tr, class Fl>
class IfThenElse;

template<class Tr, class Fl>
class IfThenElse<true,Tr,Fl>{
public:
	typedef Tr result;
};

template<class Tr, class Fl>
class IfThenElse<false,Tr,Fl>{
public:
	typedef Fl result;
};

};


#endif // #define __IFTHENELSE_HPP
