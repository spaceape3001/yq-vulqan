////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/CountCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetCount⁴UCommand : public CountCommand {
        YQ_OBJECT_DECLARE(SetCount⁴UCommand, CountCommand)
    public:
        SetCount⁴UCommand(const Header&, const Vector4U&);
    
        const Vector4U&   count() const  { return m_count; }
        
        static void init_meta();
        
        unsigned  x() const { return m_count.x; }
        unsigned  y() const { return m_count.y; }
        unsigned  z() const { return m_count.z; }
        unsigned  w() const { return m_count.w; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetCount⁴UCommand(const Header&);
        SetCount⁴UCommand(const SetCount⁴UCommand&, const Header&);
        ~SetCount⁴UCommand();

    private:
        Vector4U   m_count = ZERO;
        
        SetCount⁴UCommand(const SetCount⁴UCommand&) = delete;
        SetCount⁴UCommand(SetCount⁴UCommand&&) = delete;
        SetCount⁴UCommand& operator=(const SetCount⁴UCommand&) = delete;
        SetCount⁴UCommand& operator=(SetCount⁴UCommand&&) = delete;
    };
}
