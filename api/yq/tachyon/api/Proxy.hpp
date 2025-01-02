////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstdint>
#include <functional>
#include <yt/keywords.hpp>
#include <yq/tachyon/typedef/proxy.hpp>
#include <yt/typedef/post.hpp>
#include <yt/typedef/tachyon.hpp>
#include <yt/Type.hpp>

namespace yq::tachyon {
    class Tachyon;
    class InterfaceInfo;
    struct TachyonSnap;
    struct TypedID;
    
    //! The proxy is a *buffer* to an interface
    class Proxy {
    public:
    
        /*
            Debate: Make this a generic "object" with object inheritance?  This'd
            give rise to meta based properties/methods.
        */
    
        TachyonID               id() const;
        Types                   types() const;
        TypedID                 object() const;
        uint64_t                revision() const { return m_revision; }
        const InterfaceInfo*    interface(info_k) const { return m_interface; }
    
    protected:
        Proxy();
        virtual ~Proxy();
        
        //! Pushes a post into the tachyon's inbox for their next tick()
        void    mail(const PostCPtr&);
        
    private:
        friend class Tachyon;
        friend struct TachyonSnap;
        
        Tachyon*                m_tachyon;
        uint64_t                m_revision  = 0;
        const InterfaceInfo*    m_interface = nullptr;
        
    protected:
        enum class F {
            //! Interface is disabled
            Disabled,
            
            //! Interface can have its property be set
            Settable,
            
            //! Interface can have its property tweaked (ie, += or moveable )
            Moveable,
            
            Adjustable = Moveable,
            
            //! Interface can have its property tweaked (ie *= or inflatable )
            Scalable,
            
            Inflatable = Scalable
        };
        
        using FFlags    = Flags<F>;
        FFlags                  m_flags     = {};
    };
}

