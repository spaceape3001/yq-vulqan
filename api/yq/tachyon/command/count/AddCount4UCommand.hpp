////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddCount⁴UCommand : public CountCommand {
        YQ_OBJECT_DECLARE(AddCount⁴UCommand, CountCommand)
    public:
        AddCount⁴UCommand(const Header&, const Vector4U&);
    
        const Vector4U&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        unsigned  Δx() const { return m_Δ.x; }
        unsigned  Δy() const { return m_Δ.y; }
        unsigned  Δz() const { return m_Δ.z; }
        unsigned  Δw() const { return m_Δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddCount⁴UCommand(const AddCount⁴UCommand&, const Header&);
        AddCount⁴UCommand(const Header&);
        ~AddCount⁴UCommand();

    private:
        Vector4U  m_Δ = ZERO;
        
        AddCount⁴UCommand(const AddCount⁴UCommand&) = delete;
        AddCount⁴UCommand(AddCount⁴UCommand&&) = delete;
        AddCount⁴UCommand& operator=(const AddCount⁴UCommand&) = delete;
        AddCount⁴UCommand& operator=(AddCount⁴UCommand&&) = delete;
    };
}
