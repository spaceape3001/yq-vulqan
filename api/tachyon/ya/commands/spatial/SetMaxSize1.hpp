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
    class SetMaxSize¹ : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetMaxSize¹, SpatialCommand)
    public:
        SetMaxSize¹(const Header&, const Size1D&);
    
        const Size1D&   size() const  { return m_size; }
        
        static void init_info();
        
        double  x() const { return m_size.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMaxSize¹(const Header&);
        SetMaxSize¹(const SetMaxSize¹&, const Header&);
        ~SetMaxSize¹();

    private:
        Size1D   m_size = ZERO;
        
        SetMaxSize¹(const SetMaxSize¹&) = delete;
        SetMaxSize¹(SetMaxSize¹&&) = delete;
        SetMaxSize¹& operator=(const SetMaxSize¹&) = delete;
        SetMaxSize¹& operator=(SetMaxSize¹&&) = delete;
    };
}
