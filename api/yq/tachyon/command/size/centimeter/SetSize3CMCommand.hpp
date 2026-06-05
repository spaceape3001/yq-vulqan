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

    //! Instructs an object to set it's size
    class SetSize³CMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetSize³CMCommand, SizeCommand)
    public:
        SetSize³CMCommand(const Header&, const Size3CM&);
    
        const Size3CM&   size() const  { return m_size; }
        
        static void init_meta();
        
        Centimeter  x() const { return m_size.x; }
        Centimeter  y() const { return m_size.y; }
        Centimeter  z() const { return m_size.z; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetSize³CMCommand(const Header&);
        SetSize³CMCommand(const SetSize³CMCommand&, const Header&);
        ~SetSize³CMCommand();

    private:
        Size3CM   m_size = ZERO;
        
        SetSize³CMCommand(const SetSize³CMCommand&) = delete;
        SetSize³CMCommand(SetSize³CMCommand&&) = delete;
        SetSize³CMCommand& operator=(const SetSize³CMCommand&) = delete;
        SetSize³CMCommand& operator=(SetSize³CMCommand&&) = delete;
    };
}
