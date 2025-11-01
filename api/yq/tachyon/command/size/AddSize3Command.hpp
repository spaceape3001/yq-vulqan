////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddSize³Command : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSize³Command, SizeCommand)
    public:
        AddSize³Command(const Header&, const Vector3D&);
    
        const Vector3D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSize³Command(const AddSize³Command&, const Header&);
        AddSize³Command(const Header&);
        ~AddSize³Command();

    private:
        Vector3D  m_Δ = ZERO;
        
        AddSize³Command(const AddSize³Command&) = delete;
        AddSize³Command(AddSize³Command&&) = delete;
        AddSize³Command& operator=(const AddSize³Command&) = delete;
        AddSize³Command& operator=(AddSize³Command&&) = delete;
    };
}
