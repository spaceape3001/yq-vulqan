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
    class AddSize¹ : public SpatialCommand {
        YQ_OBJECT_DECLARE(AddSize¹, SpatialCommand)
    public:
        AddSize¹(const Header&, const Size1D&);
    
        const Size1D&   size() const  { return m_size; }
        
        static void init_info();
        
        double  x() const { return m_size.x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSize¹(const Header&);
        AddSize¹(const AddSize¹&, const Header&);
        ~AddSize¹();

    private:
        Size1D   m_size = ZERO;
        
        AddSize¹(const AddSize¹&) = delete;
        AddSize¹(AddSize¹&&) = delete;
        AddSize¹& operator=(const AddSize¹&) = delete;
        AddSize¹& operator=(AddSize¹&&) = delete;
    };
}
