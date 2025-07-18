////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/MetaBinder.hpp>
#include <concepts>

namespace yq::tachyon {

    class Tachyon;

    class InterfaceMeta;
    
    /*! \class Interface
    
        An interface is a SOLO and SMALL class that represents a single 
        attribute to a plugin that can be provided, proxied, and controlled.  
        
        It should *ALWAYS* have at least one virtual method.
        
        NO CHAINED INHERITANCE of interfaces... Interfaces are derived by tachyons,
        no interface chains, they are meant to be SIMPLE.
        
        \note When associating these with tachyons, consider the proxy 
        interfaces/adapters, the PRIMARY for a trait should be listed first on the 
        tachyon (ie position).
        
        *2024 DEC 1* [CSA] -- design update.  We'll be playing with some logical
        inheritance, so that, for instance, there's a generic IPosition, while 
        there's more specific ones for the dimension/data, to allow meta-ishness 
        to the APIs.
    */
    
    template <typename T>
    concept Interface    = requires {
        T::IsInterface == true;
    };
    
    template <typename T>
    concept is_proxied    = requires {
        { T::MyProxy };
    };
    
    template <typename T>
    struct is_interface : public std::false_type {};
    
    template <Interface I>
    struct is_interface<I> : public std::true_type {};
    
    template <typename T>
    static constexpr const bool is_interface_v  = is_interface<T>::value;
}

namespace yq {
    template <tachyon::Interface I>
    struct MetaBinder<I> {
        using Info = tachyon::InterfaceMeta;
        static constexpr const bool Defined         = true;
        static constexpr const bool IsObject        = false;
        static constexpr const bool IsCompound      = true;
        static constexpr const bool IsType          = false;
        static constexpr const bool IsTachyon       = false;
        static constexpr const bool IsInterface     = true;
        static const Info& bind() { return I::staticMetaInfo(); } 
        static Info&       edit() { return const_cast<Info&>(I::staticMetaInfo()); }
    };
}


/*! \brief Declares a proxied interface
*/
#define YQ_INTERFACE_DECLARE(iface, proxy)                                                  \
    public:                                                                                 \
        static constexpr const bool IsInterface = true;                                     \
        using MyProxy               = proxy;                                                \
        static const ::yq::tachyon::InterfaceMeta&  staticMetaInfo();                       \
        const ::yq::tachyon::InterfaceMeta&  metaInfo() const;
        
/*! \brief IMPLEMENTS a proxied interface
*/        
#define YQ_INTERFACE_IMPLEMENT(name)                                                                                \
    const ::yq::tachyon::InterfaceMeta&     name::staticMetaInfo()                                                  \
    {                                                                                                               \
        static yq::tachyon::InterfaceFixer<name>*  s_info = new yq::tachyon::InterfaceFixer<name>(#name);           \
        return *s_info;                                                                                             \
    }                                                                                                               \
    const ::yq::tachyon::InterfaceMeta&     name::metaInfo() const                                                  \
    {                                                                                                               \
        return staticMetaInfo();                                                                                    \
    }                                                                                                               \
    template <> yq::DelayInit::Ctor yq::tachyon::InterfaceFixer<name>::s_reg([](){ name::staticMetaInfo(); });      \
    
    
