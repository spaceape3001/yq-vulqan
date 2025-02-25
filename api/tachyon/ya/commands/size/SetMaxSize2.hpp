////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/SizeCommand.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMaxSize² : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMaxSize², SizeCommand)
    public:
        SetMaxSize²(const Header&, const Size2D&);
    
        const Size2D&   size() const  { return m_size; }
        
        static void init_info();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSize²(const Header&);
        SetMaxSize²(const SetMaxSize²&, const Header&);
        ~SetMaxSize²();

    private:
        Size2D   m_size = ZERO;
        
        SetMaxSize²(const SetMaxSize²&) = delete;
        SetMaxSize²(SetMaxSize²&&) = delete;
        SetMaxSize²& operator=(const SetMaxSize²&) = delete;
        SetMaxSize²& operator=(SetMaxSize²&&) = delete;
    };
}
