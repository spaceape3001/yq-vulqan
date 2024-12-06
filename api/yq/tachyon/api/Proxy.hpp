////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstdint>
#include <functional>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/typedef/proxy.hpp>
#include <yq/tachyon/typedef/post.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>
#include <yq/tachyon/typedef/types.hpp>

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
        const InterfaceInfo*    interface(info_t) const { return m_interface; }
    
    protected:
        Proxy();
        virtual ~Proxy();
        
        //! Pushes a post into the tachyon's inbox for their next tick()
        void    dispatch(const PostCPtr&);
        
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
            Adjustable,
            
            Moveable = Adjustable
        };
        
        using FFlags    = Flags<F>;
        FFlags                  m_flags     = {};
    };
}

