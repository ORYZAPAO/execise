// 
//[from] /usr/include/c++/7.2.1/type_traits
//

// Reference transformations.

namespace MY{
  /// remove_reference
  template<typename _Tp>
    struct remove_reference
    { typedef _Tp   type; };

  template<typename _Tp>
    struct remove_reference<_Tp&>
    { typedef _Tp   type; };

  template<typename _Tp>
    struct remove_reference<_Tp&&>
    { typedef _Tp   type; };

#if __cplusplus > 201103L
  /// Alias template for remove_reference
  template<typename _Tp>
    using remove_reference_t = typename remove_reference<_Tp>::type;

  /// Alias template for add_lvalue_reference
  template<typename _Tp>
    using add_lvalue_reference_t = typename add_lvalue_reference<_Tp>::type;

  /// Alias template for add_rvalue_reference
  template<typename _Tp>
    using add_rvalue_reference_t = typename add_rvalue_reference<_Tp>::type;
#endif



  template<typename _Tp>
  constexpr typename std::remove_reference<_Tp>::type&
    move2(_Tp& __t) noexcept{
    return static_cast<typename std::remove_reference<_Tp>::type&>(__t);
  }

  template<typename _Tp>
  constexpr typename std::remove_reference<_Tp>::type&&
    move2(_Tp&& __t) noexcept{
    return static_cast<typename std::remove_reference<_Tp>::type&&>(__t);
  }


// 
//[from] /usr/include/c++/7.2.1/bits/move.h
//

  /**
   *  @brief  Forward an lvalue.
   *  @return The parameter cast to the specified type.
   *
   *  This function is used to implement "perfect forwarding".
   */
  template<typename _Tp>
    constexpr _Tp&&
    forward(typename std::remove_reference<_Tp>::type& __t) noexcept
    { return static_cast<_Tp&&>(__t); }

  /**
   *  @brief  Forward an rvalue.
   *  @return The parameter cast to the specified type.
   *
   *  This function is used to implement "perfect forwarding".
   */
  template<typename _Tp>
    constexpr _Tp&&
    forward(typename std::remove_reference<_Tp>::type&& __t) noexcept
    {
      static_assert(!std::is_lvalue_reference<_Tp>::value, "template argument"
		    " substituting _Tp is an lvalue reference type");
      return static_cast<_Tp&&>(__t);
    }


  
};
