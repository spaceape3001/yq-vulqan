////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class AddSize² : public SpatialCommand {
        YQ_OBJECT_DECLARE(AddSize², SpatialCommand)
    public:
        AddSize²(const Header&, const Size2D&);
    
        const Size2D&   size() const  { return m_size; }
        
        static void init_info();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSize²(const Header&);
        AddSize²(const AddSize²&, const Header&);
        ~AddSize²();

    private:
        Size2D   m_size = ZERO;
        
        AddSize²(const AddSize²&) = delete;
        AddSize²(AddSize²&&) = delete;
        AddSize²& operator=(const AddSize²&) = delete;
        AddSize²& operator=(AddSize²&&) = delete;
    };
}
