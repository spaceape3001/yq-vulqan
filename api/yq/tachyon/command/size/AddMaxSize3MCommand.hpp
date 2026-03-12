////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class AddMaxSize³MCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSize³MCommand, SizeCommand)
    public:
        AddMaxSize³MCommand(const Header&, const Size3D&);
    
        const Size3D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Meter  Δx() const { return m_Δ.x; }
        Meter  Δy() const { return m_Δ.y; }
        Meter  Δz() const { return m_Δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSize³MCommand(const AddMaxSize³MCommand&, const Header&);
        AddMaxSize³MCommand(const Header&);
        ~AddMaxSize³MCommand();

    private:
        Size3D  m_Δ = ZERO;
        
        AddMaxSize³MCommand(const AddMaxSize³MCommand&) = delete;
        AddMaxSize³MCommand(AddMaxSize³MCommand&&) = delete;
        AddMaxSize³MCommand& operator=(const AddMaxSize³MCommand&) = delete;
        AddMaxSize³MCommand& operator=(AddMaxSize³MCommand&&) = delete;
    };
}
