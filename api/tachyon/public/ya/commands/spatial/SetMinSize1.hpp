////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/shape/Size1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMinSize¹ : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetMinSize¹, SpatialCommand)
    public:
        SetMinSize¹(const Header&, const Size1D&);
    
        const Size1D&   size() const  { return m_size; }
        
        static void init_info();
        
        double  x() const { return m_size.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSize¹(const Header&);
        SetMinSize¹(const SetMinSize¹&, const Header&);
        ~SetMinSize¹();

    private:
        Size1D   m_size = ZERO;
        
        SetMinSize¹(const SetMinSize¹&) = delete;
        SetMinSize¹(SetMinSize¹&&) = delete;
        SetMinSize¹& operator=(const SetMinSize¹&) = delete;
        SetMinSize¹& operator=(SetMinSize¹&&) = delete;
    };
}
