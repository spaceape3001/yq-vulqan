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
    class SetSize¹ : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetSize¹, SpatialCommand)
    public:
        SetSize¹(const Header&, const Size1D&);
    
        const Size1D&   size() const  { return m_size; }
        
        static void init_info();
        
        double  x() const { return m_size.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSize¹(const Header&);
        SetSize¹(const SetSize¹&, const Header&);
        ~SetSize¹();

    private:
        Size1D   m_size = ZERO;
        
        SetSize¹(const SetSize¹&) = delete;
        SetSize¹(SetSize¹&&) = delete;
        SetSize¹& operator=(const SetSize¹&) = delete;
        SetSize¹& operator=(SetSize¹&&) = delete;
    };
}
