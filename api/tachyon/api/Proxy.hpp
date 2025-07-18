////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstdint>
#include <functional>
#include <tachyon/keywords.hpp>
#include <tachyon/typedef/proxy.hpp>
#include <tachyon/typedef/post.hpp>
#include <tachyon/typedef/tachyon.hpp>
#include <tachyon/api/Type.hpp>

namespace yq::tachyon {
    class Tachyon;
    class InterfaceMeta;
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
        const InterfaceMeta*    interface(info_k) const { return m_interface; }
        bool                    disabled() const;
    
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
        const InterfaceMeta*    m_interface = nullptr;
        
    protected:
        enum class F {
            //! Interface is disabled
            Disabled,
            
            //! Interface can have its property be set
            Settable,
            
            //! Interface can have its property tweaked (ie, += or moveable )
            Adjustable,
            Addable = Adjustable,
            Moveable = Adjustable,
            Rotatable = Adjustable,
            
            //! Interface can have its property tweaked (ie *= or inflatable )
            Multipliable,
            Scalable = Multipliable,
            Inflatable = Multipliable
        };
        
        using FFlags    = Flags<F>;
        FFlags                  m_flags     = {};
    };
}

