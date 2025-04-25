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
    class SetMinSize² : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSize², SizeCommand)
    public:
        SetMinSize²(const Header&, const Size2D&);
    
        const Size2D&   size() const  { return m_size; }
        
        static void init_info();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSize²(const Header&);
        SetMinSize²(const SetMinSize²&, const Header&);
        ~SetMinSize²();

    private:
        Size2D   m_size = ZERO;
        
        SetMinSize²(const SetMinSize²&) = delete;
        SetMinSize²(SetMinSize²&&) = delete;
        SetMinSize²& operator=(const SetMinSize²&) = delete;
        SetMinSize²& operator=(SetMinSize²&&) = delete;
    };
}
