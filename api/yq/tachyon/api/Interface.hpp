////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ID.hpp>

namespace yq::tachyon {

    template <typename T>
    static constexpr const bool     is_interface_v       = InfoBinder<T>::IsTachyon && InfoBinder<T>::IsInterface;
    
    class InterfaceInfo;
    
    
    /*! \class Interface
    
        An interface is a SOLO and SMALL class that represents a single 
        attribute to a plugin that can be provided, proxied, and controlled.  
        
        It should *ALWAYS* have at least one virtual method (can be the destructor).
        
        NO CHAINED INHERITANCE of Interfaces... Interfaces are derived by tachyons,
        no interface chains, they are meant to be SIMPLE.
    */
}


/*! \brief Declares a meta type

    \note   MUST BE USED AT GLOBAL SCOPE (NO NAMESPACES)
*/
#define YQ_INTERFACE_DECLARE(...)                                       \
    namespace yq {                                                      \
        template <>                                                     \
        struct InfoBinder<__VA_ARGS__>  : public std::true_type {       \
            using Info = tachyon::InterfaceInfo;                        \
            static constexpr const bool Defined         = true;         \
            static constexpr const bool IsObject        = false;        \
            static constexpr const bool IsType          = false;        \
            static constexpr const bool IsCompound      = true;         \
            static constexpr const bool IsInterface     = true;         \
            static constexpr const bool IsProxy         = false;        \
            static constexpr const bool IsTachyon       = true;         \
            static const Info&   bind() { return edit(); }              \
            static Info&         edit();                                \
        };                                                              \
    } 
    
#define YQ_PROXY(...)   \
    using MyProxy   = __VA_ARGS__;
