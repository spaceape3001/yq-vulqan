////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/InfoBinder.hpp>
#include <concepts>

namespace yq::tachyon {

    class Tachyon;

    class InterfaceInfo;
    
    /*! \class Interface
    
        An interface is a SOLO and SMALL class that represents a single 
        attribute to a plugin that can be provided, proxied, and controlled.  
        
        It should *ALWAYS* have at least one virtual method (can be the destructor).
        
        NO CHAINED INHERITANCE of Interfaces... Interfaces are derived by tachyons,
        no interface chains, they are meant to be SIMPLE.
        
        \note When associating these with tachyons, consider the proxy 
        interfaces/adapters, the PRIMARY for a trait should be listed first on the 
        tachyon (ie position).
    */
    
    template <typename T>
    concept Interface    = requires {
        T::IsInterface == true;
    };
    
    template <typename T>
    concept is_proxied    = requires {
        { T::MyProxy };
    };
}

namespace yq {
    template <tachyon::Interface I>
    struct InfoBinder<I> {
        using Info = tachyon::InterfaceInfo;
        static constexpr const bool Defined         = true;
        static constexpr const bool IsObject        = false;
        static constexpr const bool IsCompound      = true;
        static constexpr const bool IsType          = false;
        static constexpr const bool IsTachyon       = true;
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
        static const ::yq::tachyon::InterfaceInfo&  staticMetaInfo();                       \
        const ::yq::tachyon::InterfaceInfo&  metaInfo() const;
        
/*! \brief IMPLEMENTS a proxied interface
*/        
#define YQ_INTERFACE_IMPLEMENT(name)                                                                                \
    const ::yq::tachyon::InterfaceInfo&     name::staticMetaInfo()                                                                  \
    {                                                                                                               \
        static yq::tachyon::InterfaceFixer<name>*  s_info = new yq::tachyon::InterfaceFixer<name>(#name);           \
        return *s_info;                                                                                             \
    }                                                                                                               \
    const ::yq::tachyon::InterfaceInfo&     name::metaInfo() const                                                                  \
    {                                                                                                               \
        return staticMetaInfo();                                                                                    \
    }                                                                                                               \
    template <> yq::DelayInit::Ctor yq::tachyon::InterfaceFixer<name>::s_reg([](){ name::staticMetaInfo(); });                  \
    
    
