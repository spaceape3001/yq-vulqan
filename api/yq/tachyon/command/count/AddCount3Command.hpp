////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddCount³Command : public CountCommand {
        YQ_OBJECT_DECLARE(AddCount³Command, CountCommand)
    public:
        AddCount³Command(const Header&, const Vector3D&);
    
        const Vector3D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        unsigned  Δx() const { return m_Δ.x; }
        unsigned  Δy() const { return m_Δ.y; }
        unsigned  Δz() const { return m_Δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddCount³Command(const AddCount³Command&, const Header&);
        AddCount³Command(const Header&);
        ~AddCount³Command();

    private:
        Vector3D  m_Δ = ZERO;
        
        AddCount³Command(const AddCount³Command&) = delete;
        AddCount³Command(AddCount³Command&&) = delete;
        AddCount³Command& operator=(const AddCount³Command&) = delete;
        AddCount³Command& operator=(AddCount³Command&&) = delete;
    };
}
