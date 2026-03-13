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
    class AddCount³UCommand : public CountCommand {
        YQ_OBJECT_DECLARE(AddCount³UCommand, CountCommand)
    public:
        AddCount³UCommand(const Header&, const Vector3U&);
    
        const Vector3U&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        unsigned  Δx() const { return m_Δ.x; }
        unsigned  Δy() const { return m_Δ.y; }
        unsigned  Δz() const { return m_Δ.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddCount³UCommand(const AddCount³UCommand&, const Header&);
        AddCount³UCommand(const Header&);
        ~AddCount³UCommand();

    private:
        Vector3U  m_Δ = ZERO;
        
        AddCount³UCommand(const AddCount³UCommand&) = delete;
        AddCount³UCommand(AddCount³UCommand&&) = delete;
        AddCount³UCommand& operator=(const AddCount³UCommand&) = delete;
        AddCount³UCommand& operator=(AddCount³UCommand&&) = delete;
    };
}
