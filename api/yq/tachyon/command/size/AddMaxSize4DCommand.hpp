////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddMaxSize⁴DCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSize⁴DCommand, SizeCommand)
    public:
        AddMaxSize⁴DCommand(const Header&, const Vector4D&);
    
        const Vector4D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }
        double  Δw() const { return m_Δ.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSize⁴DCommand(const AddMaxSize⁴DCommand&, const Header&);
        AddMaxSize⁴DCommand(const Header&);
        ~AddMaxSize⁴DCommand();

    private:
        Vector4D  m_Δ = ZERO;
        
        AddMaxSize⁴DCommand(const AddMaxSize⁴DCommand&) = delete;
        AddMaxSize⁴DCommand(AddMaxSize⁴DCommand&&) = delete;
        AddMaxSize⁴DCommand& operator=(const AddMaxSize⁴DCommand&) = delete;
        AddMaxSize⁴DCommand& operator=(AddMaxSize⁴DCommand&&) = delete;
    };
}
