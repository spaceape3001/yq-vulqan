////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddMinSize³Command : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSize³Command, SizeCommand)
    public:
        AddMinSize³Command(const Header&, const Vector3D&);
    
        const Vector3D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSize³Command(const AddMinSize³Command&, const Header&);
        AddMinSize³Command(const Header&);
        ~AddMinSize³Command();

    private:
        Vector3D  m_Δ = ZERO;
        
        AddMinSize³Command(const AddMinSize³Command&) = delete;
        AddMinSize³Command(AddMinSize³Command&&) = delete;
        AddMinSize³Command& operator=(const AddMinSize³Command&) = delete;
        AddMinSize³Command& operator=(AddMinSize³Command&&) = delete;
    };
}
