////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetSize² : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSize², SizeCommand)
    public:
        SetSize²(const Header&, const Size2D&);
    
        const Size2D&   size() const  { return m_size; }
        
        static void init_info();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSize²(const Header&);
        SetSize²(const SetSize²&, const Header&);
        ~SetSize²();

    private:
        Size2D   m_size = ZERO;
        
        SetSize²(const SetSize²&) = delete;
        SetSize²(SetSize²&&) = delete;
        SetSize²& operator=(const SetSize²&) = delete;
        SetSize²& operator=(SetSize²&&) = delete;
    };
}
