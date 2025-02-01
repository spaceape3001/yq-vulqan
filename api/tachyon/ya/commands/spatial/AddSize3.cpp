////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/shape/Size3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class AddSize³ : public SpatialCommand {
        YQ_OBJECT_DECLARE(AddSize³, SpatialCommand)
    public:
        AddSize³(const Header&, const Size3D&);
    
        const Size3D&   size() const  { return m_size; }
        
        static void init_info();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        double  z() const { return m_size.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSize³(const Header&);
        AddSize³(const AddSize³&, const Header&);
        ~AddSize³();

    private:
        Size3D   m_size = ZERO;
        
        AddSize³(const AddSize³&) = delete;
        AddSize³(AddSize³&&) = delete;
        AddSize³& operator=(const AddSize³&) = delete;
        AddSize³& operator=(AddSize³&&) = delete;
    };
}
